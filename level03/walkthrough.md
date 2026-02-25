# LEVEL03

## 1. Inspect The Executable

```bash
RELRO           STACK CANARY      NX            PIE             RPATH      RUNPATH      FILE
Partial RELRO   Canary found      NX enabled    No PIE          No RPATH   No RUNPATH   /home/users/level03/level03
level03@OverRide:~$ ls -l
total 8
-rwsr-s---+ 1 level04 users 7677 Sep 10  2016 level03
```

We can see that the binary has the `s` bit set on the **execution permission**, which means the program will run with **`level04` privileges**.

```bash
level03@OverRide:~$ ./level03 
***********************************
*		level03		**
***********************************
Password:password

Invalid Password
level03@OverRide:~$ ./level03 
***********************************
*		level03		**
***********************************
Password:aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa

Invalid Password
level03@OverRide:~$ ./level03 
***********************************
*		level03		**
***********************************
Password:aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa

Invalid Password
```

The program asks for a password and tests it.

## 2. Analyze The Executable

```bash
(gdb) info functions 
All defined functions:

Non-debugging symbols:
[...]
0x08048660  decrypt
0x08048747  test
0x0804885a  main
[...]
```

Using the gdb command `info functions`, we can list all functions present in the binary.
Here, we find 3 functions: `main`, `test` and `decrypt`.

### Program Behavior

#### main function

The `main` function creates a random seed based on the time at the start of the program. Then it asks for a password and calls `test()`.

#### test function

The `test` calculs the offset between his `param_1` *(user input)* and `param_2` *(the hard value : `0x1337d00d`, `322424845` in decimal)*. Then, the program calls the `decrypt` function with a key with a value which depends of the offset.
From 0-9 and 16-21, the key is simply the value of the offset.
From 10-15 and 22 and more, the key is the result of a `rand()`. 

#### decrypt function

The `decrypt` operates a shifting of the key to the string `local_21`, which is set to : `517d7c75607366677e73667b7d7c6133`, or "Q}|u\`sfg~sf{}|a3" in string. On each character of the string, it does : `ctx ^ local_21[index]`;

Then, it compares the shifted string to `"Congratulations!"`, if it is equal, it spawns a shell with `system("/bin/sh")`, otherwise it `puts` `"Invalid Password"`.

## 3. Identify The Vulnerability

Basically, we want to get :

```
Q}|u\`sfg~sf{}|a3 ^ ctx = Congratulations!
ctx = 0x1337d00d - user_input
```

### Found Offset

First we need to found the rotation offset between "Q}|u\`sfg~sf{}|a3" and `"Congratulations!"`. With a python program we can easily found it :

```bash
> python3 rotate_search.py "Q}|u`sfg~sf{}|a3" "Congratulations!"
Search rotate gap between  Q}|u`sfg~sf{}|a3  -  Congratulations!
rotation is :  18
```

### Found Key

Now, we know that `ctx` must be equal to `18`.

```
Q}|u\`sfg~sf{}|a3 ^ 18 = Congratulations!
18 = 0x1337d00d - user_input
```

```
18 = 0x1337d00d - user_input
18 = 322424845 - user_input

user_input = 322424845 - 18
user_input = 322424827
```

So we need to enter `322424827` to get a cryptograph key of `18`.

## 4. Capture The Flag

```bash
level03@OverRide:~$ ./level03 
***********************************
*		level03		**
***********************************
Password:322424827
$ id
uid=1003(level03) gid=1003(level03) euid=1004(level04) egid=100(users) groups=1004(level04),100(users),1003(level03)
$ cat /home/users/level04/.pass
XXX
$ exit
```