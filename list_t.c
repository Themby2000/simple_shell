#include "shell.h"

/**
 * free_list - frees a list_t
 *@ogP: pointer to our linked list
 */
void free_list(list_path *ogP)
{
	list_path *storage;

	while (ogP)
	{
		storage = ogP->p;
		free(ogP->dir);
		free(ogP);
		ogP = storage;
	}

}
