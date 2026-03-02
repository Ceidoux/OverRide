# LEVEL00

## 1. Inspect The Executable

```bash
RELRO           STACK CANARY      NX            PIE             RPATH      RUNPATH      FILE
Partial RELRO   No canary found   NX enabled    No PIE          No RPATH   No RUNPATH   /home/users/level00/level00
level00@OverRide:~$ ls -l
total 8
-rwsr-s---+ 1 level01 users 7280 Sep 10  2016 level00
```

We can see that the binary has the `s` bit set on the **execution permission**, which means the program will run with **`level01` privileges**.

```bash
level00@OverRide:~$ ./level00 
***********************************
* 	     -Level00 -		  *
***********************************
Password:password

Invalid Password!
level00@OverRide:~$ ./level00 
***********************************
* 	     -Level00 -		  *
***********************************
Password:aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa
```

The program asks for a password and tests it.

## 2. Analyze The Executable

In this project, we are gonna use **gdb** *(on the VM)* and **Ghidra** *(on the host machine)* to **analyze** the binary.
- In **gdb**, we can **disassemble functions** using commands like `disas main`.
- In **Ghidra**, we can load the executable and obtain a **human-readable decompiled** version of the code in **pseudo-C**.

The full disassembly code is available in separate files:
- **Assembly code**: see the `gdb-dump` file.
- **Pseudo-C code**: see the `source` file.

```bash
(gdb) info functions 
All defined functions:

Non-debugging symbols:
[...]
0x08048494  main
[...]
```

Using the gdb command `info functions`, we can list all functions present in the binary.
Here, we find only the function: `main`.

### Program Behavior

#### main function

The `main` function **asks** for a **password** and **checks if it's correct**. If the correct password is provided, it prints "Authenticated!" and **spawns a shell** with `system("/bin/sh")`.

## 3. Find The Password

With the **program decompiled**, we can see the **`if` statement** that checks the password:

```c
if (local_14[0] != 0x149c) {
    puts("\nInvalid Password!");
  }
  else {
    puts("\nAuthenticated!");
    system("/bin/sh");
```

It compares the input with the value `0x149c` *(in hexadecimal)*.

```bash
> python3 -c 'print(0x149c)'
5276
```

In decimal, it equals **`5276`**. We simply need to enter this value as the password.

## 4. Capture The Flag

```bash
level00@OverRide:~$ ./level00 
***********************************
* 	     -Level00 -		  *
***********************************
Password:5276

Authenticated!
$ id
uid=1000(level00) gid=1000(level00) euid=1001(level01) egid=100(users) groups=1001(level01),100(users),1000(level00)
$ cat /home/users/level01/.pass
XXX
$ exit
```
