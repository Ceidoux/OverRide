# LEVEL02

## 1. Inspect The Executable

```bash
level02@OverRide:~$ ls -l
total 12
-rwsr-s---+ 1 level03 users 9452 Sep 10  2016 level02
```
nananannanap

```bash
[test program....]
```


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

The `printf` of a variable without [classique format string] allows to proceed to a Format String Attack.

### Format String Attack Explaination

[format string attack explanation]

---




## 4. Capture The Flag

```
```
