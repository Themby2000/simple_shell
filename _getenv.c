#include "shell.h"

/**
 * _getenv - gets the value of the global variable
 * @n_gbvar: n_gbvar of the global variable
 * Return: string of value
 */
char *_getenv(const char *n_gbvar)
{
	int i, j;
	char *value;

	if (!n_gbvar)
		return (NULL);
	for (i = 0; environ[i]; i++)
	{
		j = 0;
		if (n_gbvar[j] == environ[i][j])
		{
			j = 0;
			if (n_gbvar[j] == environ[i][j])
			{
				while (n_gbvar[j])
				{
					if (n_gbvar[j] != environ[i][j])
						break;
					j++;
				}
				if (n_gbvar[j] == '\0')
				{
					value = (environ[i] + j + 1);
					return (value);
				}
			}
		}
		return (0);
	}
