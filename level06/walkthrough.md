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

The program asks for a Login and a Serial.

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

### Program Behavior

#### main function

blablabla

#### auth function

blablabla

## 3. Identify The Vulnerability

We need to enter the serial value of the login we giving. With the decompile code, we can see the serial algorithm.

From this we can create a C program that serial the user input :

```bash
> gcc serializer.c -o serializer
> ./serializer aaaaaa
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

So if the Login if `aaaaaa`, the correct Serial is 6231562.

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