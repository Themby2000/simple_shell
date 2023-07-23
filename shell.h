#ifndef _SHELL_H_
#define _SHELL_H_

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <errno.h>
#include <stddef.h>
#include <sys/stat.h>
#include <signal.h>

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
char *_which(char *filename, list_path *ogP);

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
void exitz(char **arr);
void env(char **arr);
void _setenv(char **arr);
void _unsetenv(char **arr);

void freearr(char **arr);
void free_list(list_path *ogP);
void sig_handler(int sig_num);
void _EOF(int len, char *buff);
void _isatty(void);

#endif
