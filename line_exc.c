#include "shell.h"

/**
 * execute - executes a command
 * @argv: array of arguments
 */

void execute(char **argv)
{

	int d, status;

	if (!argv || !argv[0])
		return;
	d = fork();
	if (d == -1)
	{
		perror(_getenv("_"));
	}
	if (d == 0)
	{
		execve(argv[0], argv, environ);
			perror(argv[0]);
		exit(EXIT_FAILURE);
	}
	wait(&status);
}

/**
 * _realloc - Reallocates memory block
 * @prvptr: previous pointer
 * @oldsz: old size of previous pointer
 * @newsz: new size for our pointer
 * Return: New resized Pointer
 */

void *_realloc(void *prvptr, unsigned int oldsz, unsigned int newsz)
{
	char *new;
	char *old;

	unsigned int i;

	if (prvptr == NULL)
		return (malloc(newsz));

	if (newsz == oldsz)
		return (prvptr);

	if (newsz == 0 && prvptr != NULL)
	{
		free(prvptr);
		return (NULL);
	}

	new = malloc(newsz);
	old = prvptr;
	if (new == NULL)
		return (NULL);

	if (newsz > oldsz)
	{
		for (i = 0; i < oldsz; i++)
			new[i] = old[i];
		free(prvptr);
		for (i = oldsz; i < newsz; i++)
			new[i] = '\0';
	}
	if (newsz < oldsz)
	{
		for (i = 0; i < newsz; i++)
			new[i] = old[i];
		free(prvptr);
	}
	return (new);
}

/**
 * freearr - frees the array of pointers.
 *@arr: array of pointers
 */

void freearr(char **arr)
{
	int i;

	for (i = 0; arr[i]; i++)
		free(arr[i]);
	free(arr);
}
