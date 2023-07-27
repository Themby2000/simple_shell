#ifndef SIMPLE_H
#define SIMPLE_H

#include <stdbool.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <signal.h>

typedef struct data
{
	bool in_shell;
	bool interactive;
	char **_environ;
}data_shell;

void handle_eof(data_shell *datash);
int is_all_delims(const char *str, const char *delims);

#endif
