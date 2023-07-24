#include "shell.h"

/**
 * linkpath - creates a linked list for path directories
 * @path: string of path value
 * Return: pointer to the created linked list
 */
list_path *linkpath(char *path)
{
	list_path *ogP = '\0';
	char *token;
	char *cpath = _strdup(path);

	token = strtok(cpath, ":");
	while (token)
	{
	ogP = new_node(&ogP, token);
	token = strtok(NULL, ":");
	}
	return (ogP);
}
