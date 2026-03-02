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

The program **asks** for a **password** and **tests it**.

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

The `main` function creates a random seed based on the time at the start of the program. Then it **asks** for a **password** and calls `test()`.

#### test function

The `test` function function **calculates the offset** between its `param_1`  and `param_2` *(the hardcoded value : `0x1337d00d` (`322424845` in decimal))*.

Then, the program **calls** the `decrypt` function with a **key** that depends on the offset.

- For offsets **0-9** and **16-21**, the key is the **offset value** itself.
- For offsets **10-15** and **22-more**, the key is a **value** from **`rand()`**.

#### decrypt function

The `decrypt` function performs an **XOR operation** between the key and each character of the string `local_21`, which contains: "Q}|u\`sfg~sf{}|a3" *(in hexadecimal: `517d7c75607366677e73667b7d7c6133`)*.

For each character, it **performs**:
```c
result[i] = ctx ^ local_21[i]
```

*(`ctx` is the key.)*

Then, it **compares** the **XORed result** to `"Congratulations!"`. If they match, it **spawns a shell** with `system("/bin/sh")`. Otherwise, it prints `"Invalid Password"`.

## 3. Reverse The Algorithm

Our goal is to achieve :

```
Q}|u\`sfg~sf{}|a3 ^ ctx = Congratulations!
ctx = 0x1337d00d - user_input
```

### Finding The XOR Key

First, we need to find the **XOR key** between **"Q}|u\`sfg~sf{}|a3"** and **`"Congratulations!"`**. With a **Python script**, we can easily find it:

```bash
> python3 xor_key_search.py "Q}|u`sfg~sf{}|a3" "Congratulations!"
Search XOR key between  Q}|u`sfg~sf{}|a3  -  Congratulations!
XOR key is :  18
```

### Finding The Input Value

Now, we know that **`ctx`**, the key, must **equal `18`**.

```
Q}|u\`sfg~sf{}|a3 ^ 18 = Congratulations!
___________________________________________

18 = 0x1337d00d - user_input
18 = 322424845 - user_input
___________________________________________

user_input = 322424845 - 18
user_input = 322424827
```

We need to enter **`322424827`** to get an **XOR key** of **`18`**.

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
