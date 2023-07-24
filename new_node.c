#include "shell.h"

/**
 * new_node - a new node at the end of a list_t list
 * @ogP: pointer to pointer to our linked list
 * @str: pointer to string in previous first node
 * Return: address of the new element/node
 */

list_path *new_node(list_path **ogP, char *str)
{
	list_path *tmp;
	list_path *new;

	new = malloc(sizeof(list_path));

	if (!new || !str)
	{
	return (NULL);
	}
	new->dir = str;

	new->p = '\0';
	if (!*ogP)
	{
	*ogP = new;
	}
	else
	{
	tmp = *ogP;
	while (tmp->p)
	{
	tmp = tmp->p;
	}
	tmp->p = new;
	}
	return (*ogP);
}

