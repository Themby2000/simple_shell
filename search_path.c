#include "shell.h"

/**
 * _which - finds the pathn_gbvar of a filen_gbvar
 * @filen_gbvar: n_gbvar of file or command
 * @ogP: ogP of linked list of path directories
 * Return: pathn_gbvar of filen_gbvar or NULL if no match
 */
char *_which(char *filen_gbvar, list_path *ogP)
{
	struct stat st;
	char *string;

	list_path *tmp = ogP;

	while (tmp)
	{

	string = concat_all(tmp->dir, "/", filen_gbvar);
	if (stat(string, &st) == 0)
	{
	return (string);
	}
	free(string);
	tmp = tmp->p;
	}

	return (NULL);
}
