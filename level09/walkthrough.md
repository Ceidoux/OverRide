# LEVEL09

## 1. Inspect The Executable

```bash
RELRO           STACK CANARY      NX            PIE             RPATH      RUNPATH      FILE
Partial RELRO   No canary found   NX enabled    PIE enabled     No RPATH   No RUNPATH   /home/users/level09/level09
level09@OverRide:~$ ls -l
total 16
-rwsr-s---+ 1 end users 12959 Oct  2  2016 level09
```

We can see that the binary has the `s` bit set on the **execution permission**, which means the program will run with **`end` privileges**.


## 2. Analyze The Executable

```bash
(gdb) info functions 
All defined functions:

Non-debugging symbols:
[...]
0x000000000000088c  secret_backdoor
0x00000000000008c0  handle_msg
0x0000000000000932  set_msg
0x00000000000009cd  set_username
0x0000000000000aa8  main
[...]
```

Using the gdb command `info functions`, we can list all functions present in the binary.
Here, we find 5 functions: `main`, `handle_msg`, `set_username`, `set_msg`,  and `secret_backdoor`.

### Program Behavior

#### main function

blablabla

#### handle_msg function

blablabla

#### set_username function

blablabla

#### set_msg function

blablabla

#### secret_backdoor function

blablabla

## 3. Identify The Vulnerability

## 4. Capture The Flag

```bash
```
