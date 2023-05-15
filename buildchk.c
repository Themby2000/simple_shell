#include "shell.h"

/**
* chkbuild - checks for built-in comands
* @arr: array of arguments
* Return: pointer to function that takes arr and returns void
*/
void(*chkbuild(char **arr))(char **arr)
{
	int i, j;
	mybuild T[] = {
		{"exit", exitz},
		{"env", env},
		{"setenv", _setenv},
		{"unsetenv", _unsetenv},
		{NULL, NULL}
	};

	for (i = 0; T[i].name; i++)
	{
		j = 0;
		if (T[i].name[j] == arr[0][j])
		{
			for (j = 0; arr[0][j]; j++)
			{
				if (T[i].name[j] != arr[0][j])
					break;
			}
			if (!arr[0][j])
				return (T[i].func);
		}
	}
	return (0);
}
