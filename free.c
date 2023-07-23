#include "shell.h"

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

