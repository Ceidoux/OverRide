# LEVEL08

## 1. Inspect The Executable

```bash
RELRO           STACK CANARY      NX            PIE             RPATH      RUNPATH      FILE
Full RELRO      Canary found      NX disabled   No PIE          No RPATH   No RUNPATH   /home/users/level08/level08
level08@OverRide:~$ ls -l
total 16
drwxrwx---+ 1 level09 users    60 Oct 19  2016 backups
-rwsr-s---+ 1 level09 users 12975 Oct 19  2016 level08
level08@OverRide:~$ ls -lar backups/
total 4
-rwxrwx---+ 1 level09 users    32 Feb 18 23:41 .log
dr-xr-x---+ 1 level08 level08 100 Oct 19  2016 ..
drwxrwx---+ 1 level09 users    60 Oct 19  2016 .
```

blablabla

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
0x00000000004008c4  log_wrapper
0x00000000004009f0  main
[...]
```

Using the gdb command `info functions`, we can list all functions present in the binary.
Here, we find 2 functions: `main`, and `log_wrapper`.

### Program Behavior

#### main function

blablabla

#### log_wrapper function

blablabla

## 3. Identify The Vulnerability

## 4. Capture The Flag

```
```