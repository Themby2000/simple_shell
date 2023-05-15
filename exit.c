#include "shell.h"

/**
 * exitz - exits the shell with or without a return of status n
 * @arr: array of words of the entered line
 */
void exitz(char **arr)
{
	int i, n;

	if (arr[1])
	{
		n = _atoi(arr[1]);
		if (n <= -1)
			n = 2;
		freearr(arr);
		exit(n);
	}
	for (i = 0; arr[i]; i++)
		free(arr[i]);
	free(arr);
	exit(0);
}
