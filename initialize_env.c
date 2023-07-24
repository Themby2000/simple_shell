#include "shell.h"

/**
 * _setenv - Initialize a new environment variable, or modify an existing one
 * @arr: array of words
 */
void _setenv(char **arr)
{
	int i, j, k;

	if (!arr[1] || !arr[2])
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
	k = 0;
	while (arr[2][k])
	{
	environ[i][j + 1 + k] = arr[2][k];
	k++;
	}
	environ[i][j + 1 + k] = '\0';
	return;
	}
	}
	}
	if (!environ[i])
	{

	environ[i] = concat_all(arr[1], "=", arr[2]);
	environ[i + 1] = '\0';
	}
}
