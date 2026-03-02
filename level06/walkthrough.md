# LEVEL06

## 1. Inspect The Executable

```bash
RELRO           STACK CANARY      NX            PIE             RPATH      RUNPATH      FILE
Partial RELRO   Canary found      NX enabled    No PIE          No RPATH   No RUNPATH   /home/users/level06/level06
level06@OverRide:~$ ls -l
total 8
-rwsr-s---+ 1 level07 users 7907 Sep 10  2016 level06
```

We can see that the binary has the `s` bit set on the **execution permission**, which means the program will run with **`level07` privileges**.

```bash
level06@OverRide:~$ ./level06 
***********************************
*		level06		  *
***********************************
-> Enter Login: login
***********************************
***** NEW ACCOUNT DETECTED ********
***********************************
-> Enter Serial: serial
level06@OverRide:~$ ./level06 
***********************************
*		level06		  *
***********************************
-> Enter Login: aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa
***********************************
***** NEW ACCOUNT DETECTED ********
***********************************
-> Enter Serial: level06@OverRide:~$ 
```

The program **asks** for a **Login** and a **Serial**.

## 2. Analyze The Executable

```bash
(gdb) info functions 
All defined functions:

Non-debugging symbols:
[...]
0x08048748  auth
0x08048879  main
[...]
```

Using the gdb command `info functions`, we can list all functions present in the binary.
Here, we find 2 functions: `main`, and `auth`.

### Stack Canary Protection

This binary uses a **stack canary**. It is a **security** to **detect buffer overflows**.

Before a **function returns**, it **checks** if a **random value** placed **on the stack** has been modified. If the **canary value changed** it means a **buffer overflow** occured and the program calls the `__stack_chk_fail()` function to **abort execution** instead of allowing the exploit.

In the **assembly**, we can see:
```s
	0x08048889 <+16>:	mov    %gs:0x14,%eax    ; Load canary from TLS
	0x0804888f <+22>:	mov    %eax,0x4c(%esp)  ; Place canary on stack
	[...]
	0x08048972 <+249>:	xor    %gs:0x14,%edx    ; Check canary at return
	0x08048979 <+256>:	je     0x8048980        ; If equal, continue
	0x0804897b <+258>:	call   0x8048580 <__stack_chk_fail@plt>  ; Else abort
   0x08048980 <+263>:	leave  
   0x08048981 <+264>:	ret    
```

And in the **C program** :
```c
  local_14 = *(int *)(in_GS_OFFSET + 0x14);
  [...]
    if (local_14 != *(int *)(in_GS_OFFSET + 0x14)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar1 != 0;
```

### Program Behavior

#### main function

The `main` function **reads** a **login** with `fgets()` *(with a limited size of `0x20`, 32 bytes in decimal)* and a **serial number** with `scanf()`.

Then calls `auth(login, serial)`. If authentication succeeds, it **spawns a shell** with `system("/bin/sh")`.

#### auth function

The `auth` function **calculates** a **hash** from the **login string** and **compares it** with the provided serial.

It first **checks** that the **login** is at **least 6 characters long** and uses `ptrace(PTRACE_TRACEME)` to trace its own process. The **hash algorithm** uses `XOR` **operations** and a **modulo** `0x539`, starting with `(param_1[3] ^ 0x1337) + 0x5eeded`.


## 3. Identify The Vulnerability

We need to **provide** the **correct serial number** for **any login** we enter.

From the **decompiled code**, we can implement the **hashing algorithm** in a C program.

```bash
> gcc serializer.c -o serializer
> ./serializer aaaaaa

serialization of        aaaaaa  : 6231562

to see step by step, use the program with `-d` as 2nd argument.
```

So if the Login if `aaaaaa`, the correct Serial is **6231562**.

With the step by step algorithm debug flag :
```bash
> ./serializer aaaaaa -d
argv[1][3] ^ 0x1337U : 4950
u + 0x5eeded : 6226243


argv[1][0] ^ h : 6226210
c % 0x539 : 1138
h += g : 6227381

argv[1][1] ^ h : 6227412
c % 0x539 : 1003
h += g : 6228384

argv[1][2] ^ h : 6228417
c % 0x539 : 671
h += g : 6229055

argv[1][3] ^ h : 6229086
c % 0x539 : 3
h += g : 6229058

argv[1][4] ^ h : 6229027
c % 0x539 : 1281
h += g : 6230339

argv[1][5] ^ h : 6230306
c % 0x539 : 1223
h += g : 6231562


serialization of        aaaaaa  : 6231562
```

## 4. Capture The Flag

```bash
level06@OverRide:~$ ./level06 
***********************************
*		level06		  *
***********************************
-> Enter Login: aaaaaa
***********************************
***** NEW ACCOUNT DETECTED ********
***********************************
-> Enter Serial: 6231562
Authenticated!
$ id
uid=1006(level06) gid=1006(level06) euid=1007(level07) egid=100(users) groups=1007(level07),100(users),1006(level06)
$ cat /home/users/level07/.pass
XXX
$ exit

[1]+  Stopped                 ./level06
```
