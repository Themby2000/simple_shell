#include "shell.h"

/**
 * exitz - exits the shell with or without a return of status
 * @arr: array of words of the entered line
 */
void exitz(char **arr)
{
	int i, m;

	if (arr[1])
	{
		m = _atoi(arr[1]);
		if (m <= -1)
			m = 2;
		freearr(arr);
		exit(m);
	}
	for (i = 0; arr[i]; i++)
		free(arr[i]);
	free(arr);
	exit(0);
}
