#include "shell.h"

/**
* chkbuild - checks for built-in comands
* @arr: array of arguments
* Return: pointer to function that takes arr and returns void
*/
void(*chkbuild(char **arr))(char **arr)
{
	int i, q;
	buildD T[] = {
		{"exit", exitz},
		{"env", env},
		{"setenv", _setenv},
		{"unsetenv", _unsetenv},
		{NULL, NULL}
	};

	for (i = 0; T[i].name; i++)
	{
		q = 0;
		if (T[i].name[q] == arr[0][q])
		{
			for (q = 0; arr[0][q]; q++)
			{
				if (T[i].name[q] != arr[0][q])
					break;
			}
			if (!arr[0][q])
				return (T[i].func);
		}
	}
	return (0);
}
