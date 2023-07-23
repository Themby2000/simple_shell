#include "shell.h"
#include <stddef.h>

/**
 * _realloc - Reallocates memory block
 * @prvptr: previous pointer
 * @oldsz: old size of previous pointer
 * @newsz: new size for our pointer
 * Return: New resized Pointer
 */

void *_realloc(void *prvptr, unsigned int oldsz, unsigned int newsz)
{
	void *new;
	char *new_ptr;
	char *old_ptr;

	unsigned int i;

	if (prvptr == NULL)
	return (malloc(newsz));

	if (newsz == oldsz)
	return (prvptr);

	if (newsz == 0 && prvptr != NULL)
	{
	free(prvptr);
	return (NULL);
	}

	new = malloc(newsz);
	if (new == NULL)
	return (NULL);

	new_ptr = new;
	old_ptr = prvptr;

	for (i = 0; i < oldsz && i < newsz; i++)
	{
	new_ptr[i] = old_ptr[i];
	}

	free(prvptr);
	return (new);
	}

