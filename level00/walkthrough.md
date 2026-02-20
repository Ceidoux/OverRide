# LEVEL00

## 1. Inspect The Executable

```bash
level00@OverRide:~$ ls -l
total 8
-rwsr-s---+ 1 level01 users 7280 Sep 10  2016 level00
```


The program have the s bits. nananan.

```bash
program test in bash
```

## 2. Analyze The Executable

```bash

(gdb) info functions 
All defined functions:

Non-debugging symbols:
[...]
0x08048494  main
[...]
```

### Program Behavior

#### main function

The main function ask a password and check if it's correct or not. If the correct password is given, it prints "Authenticated!" and spawn a shell with `system("/bin/sh")`.

## 3. Identify The Vulnerability

With the program decompiled we can see the if statement that check the password.

```c
if (xxx)
	system()
```

It's compare the string with the value `0x149c` in hexadecimal.

```bash
> python3 -c 'print(0x149c)'
5276
```

In decimal it equal to `5276`. So we simply need to enter this value as password.

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
