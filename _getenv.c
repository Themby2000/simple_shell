#include "shell.h"


/**
 * _getenv - the value of the global variable
 * @n_gbvar: n_gbvar of the global variable
 * Return: string of value
 */
char *_getenv(const char *n_gbvar)
{
	int i, b;
	char *value;

	if (!n_gbvar)
		return (NULL);
	for (i = 0; environ[i]; i++)
	{
		b = 0;
		if (n_gbvar[b] == environ[i][b])
		{
			while (n_gbvar[b])
			{
				if (n_gbvar[b] != environ[i][b])
					break;

				b++;
			}
			if (n_gbvar[b] == '\0')
			{
				value = (environ[i] + b + 1);
				return (value);
			}
		}
	}
	return (0);
}
