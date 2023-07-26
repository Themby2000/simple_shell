#ifndef _SHELL_H_
#define _SHELL_H_

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <errno.h>
#include <fcntl.h>
#include <signal.h>
#include <limits.h>

#define BUFSIZE 1024
#define TOK_BUFSIZE 128
#define TOK_DELIM " \t\r\n\a"

int _putchar(char c);
void _puts(char *str);
int _strlen(char *s);
char *_strdup(char *str);
char *concat_all(char *name, char *sep, char *value);
int prompt(char **env);

char **splitstring(char *str, const char *delim);
void execute(char **argv);
void *_realloc(void *prvptr, unsigned int oldsz, unsigned int newsz);

/* Points to an array of pointers to strings called the "environment" */
extern char **environ;

/**
 * struct data - struct that contains all relevant data on runtime
 * @av: argument vector
 * @input: command line written by the user
 * @args: tokens of the command line
 * @status: last status of the shell
 * @counter: lines counter
 * @_environ: environment variable
 * @pid: process ID of the shell
 */
typedef struct data
{
	char **av;
	char *input;
	char **args;
	int status;
	int counter;
	char **_environ;
	char *pid;
} data_shell;

/**
 * struct list_path - Linked list containing PATH directories
 * @dir: directory in path
 * @p: pointer to next node
 */
typedef struct list_path
{
	char *dir;
	struct list_path *p;
} list_path;


char *_getenv(const char *name);
list_path *new_node(list_path **ogP, char *str);
list_path *linkpath(char *path);
char *_which(char *filen_gbvar, list_path *ogP);
/**
 * struct buildD - pointer to function with corresponding buildin command
 * @name: buildin command
 * @func: execute the buildin command
 */
typedef struct buildD
{
	char *name;
	void (*func)(char **);
} buildD;

void(*chkbuild(char **arr))(char **arr);
int _atoi(char *s);
void env(char **arr);
void _setenv(char **arr);
void _unsetenv(char **arr);
char *aux_itoa(int n);
void get_sigint(int sig);
void shell_loop(data_shell *datash);


void freearr(char **arr);
void free_list(list_path *ogP);
void sig_handler(int sig_num);
void _EOF(int len, char *buff);
void _isatty(void);

#endif
