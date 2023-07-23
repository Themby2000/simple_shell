# SIMPLE SHELL
***
## ABOUT
---
Simple Shell is a simplified UNIX command interpreter
---

## Requirements
---
Allowed editors: vi, vim, emacs
All your files will be compiled on Ubuntu 20.04 LTS using gcc, using the options -Wall -Werror -Wextra -pedantic -std=gnu89
All your files should end with a new line
A README.md file, at the root of the folder of the project is mandatory
Your code should use the Betty style. It will be checked using betty-style.pl and betty-doc.pl
Your shell should not have any memory leaks
No more than 5 functions per file
All your header files should be include guarded
Use system calls only when you need to
Write a README with the description of your project
---

List of allowed functions and system calls

1. `access` (man 2 access)
2. `chdir` (man 2 chdir)
3. `close` (man 2 close)
1. `closedir` (man 3 closedir)
1. `execve` (man 2 execve)
1. `exit` (man 3 exit)
1. `_exit` (man 2 _exit)
1. `fflush` (man 3 fflush)
1. `fork` (man 2 fork)
1. `free` (man 3 free)
1. `getcwd` (man 3 getcwd)
1. `getline` (man 3 getline)
1. `getpid` (man 2 getpid)
1. `isatty` (man 3 isatty)
1. `kill` (man 2 kill)
1. `malloc` (man 3 malloc)
1. `open` (man 2 open)
1. `opendir` (man 3 opendir)
1. `perror` (man 3 perror)
1. `read` (man 2 read)
1. `readdir` (man 3 readdir)
1. `signal` (man 2 signal)
1. `stat` (__xstat) (man 2 stat)
1. `lstat` (__lxstat) (man 2 lstat)
1. `fstat` (__fxstat) (man 2 fstat)
1. `strtok` (man 3 strtok)
1. `wait` (man 2 wait)
1. `waitpid` (man 2 waitpid)
1. `wait3` (man 2 wait3)
1. `wait4` (man 2 wait4)
1. `write` (man 2 write)

## Compilation
	gcc -Wall -Werror -Wextra -pedantic *.c -o hsh

### Testing

Your shell should work like this in interactive mode:
```js
$ ./hsh
($) /bin/ls
hsh main.c shell.c
($)
($) exit
$
```
The shell works like this in non-interactive mode:
```js
$ echo "/bin/ls" | ./hsh
hsh main.c shell.c test_ls_2
$
$ cat test_ls_2
/bin/ls
/bin/ls
$
$ cat test_ls_2 | ./hsh
hsh main.c shell.c test_ls_2
hsh main.c shell.c test_ls_2
$
```
Authors
 Elorm Mensa Komla Dzameshie, Sithembelenkosini Ndlovu
