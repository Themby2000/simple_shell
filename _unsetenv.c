#include "shell.h"

/**
 * _unsetenv - Remove an environment variable
 * @arr: array of words
 */
void _unsetenv(char **arr)
{
	int i, j;

	if (!arr[1])
	{
		perror(_getenv("_"));
		return;
	}
	for (i = 0; environ[i]; i++)
	{
		j = 0;
		if (arr[1][j] == environ[i][j])
		{
			while (arr[1][j])
			{
				if (arr[1][j] != environ[i][j])
					break;
				j++;
			}
			if (arr[1][j] == '\0')
			{
				free(environ[i]);
				environ[i] = environ[i + 1];
				while (environ[i])
				{
					environ[i] = environ[i + 1];
					i++;
				}
				return;
			}
		}
	}
}
