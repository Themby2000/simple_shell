#include "simple.h"
#include <stdio.h>
#include <stdlib.h>

void handle_eof(data_shell *datash)
{
	if (datash->interactive)
	{
		printf("\n");
		printf("#cisfun$ ");
		fflush(stdout);
	}
	datash->in_shell = false;
}
