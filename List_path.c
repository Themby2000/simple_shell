#include "shell.h"

/**
 * linkpath - creates a linked list for path directories
 * @path: string of path value
 * Return: pointer to the created linked list
 */
list_path *linkpath(char *path)
{
	list_path *head = '\0';
	char *token;
	char *cpath = _strdup(path);

	token = strtok(cpath, ":");
	while (token)
	{
		head = add_node_end(&head, token);
		token = strtok(NULL, ":");
	}
	return (head);
}

/**
 * _which - finds the pathn_gbvar of a filen_gbvar
 * @filen_gbvar: n_gbvar of file or command
 * @head: head of linked list of path directories
 * Return: pathn_gbvar of filen_gbvar or NULL if no match
 */
char *_which(char *filen_gbvar, list_path *head)
{
	struct stat st;
	char *string;

	list_path *tmp = head;

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
