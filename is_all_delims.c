#include <string.h>

int is_all_delims(const char *str, const char *delims)
{
	size_t i;
	for (i = 0; str[i]; i++)
	{
		if (strchr(delims, str[i]) == NULL)
		{
			return 0;
		}
	}
	return 1;
}
