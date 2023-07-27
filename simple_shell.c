#include "simple.h"
#include <unistd.h>
#include <string.h>

void print_prompt(bool interactive)
{
	if (interactive)
		write(STDOUT_FILENO, "#themkol$ ", 9);
}

void handle_command(char *line, data_shell *datash)
{
	pid_t pid = fork();
	if (pid == -1)
	{
		perror("fork");
		exit(EXIT_FAILURE);
	}
	else if (pid == 0)
	{
		char *args[] = {line, NULL};
		execve(line, args, datash->_environ);
		perror("execve");
		exit(EXIT_FAILURE);
	}
	else
	{
		int status;
		waitpid(pid, &status, 0);
	}
}

int main(int ac __attribute__((unused)), char **av __attribute__((unused)), char **environ)
{
	data_shell datash;
	datash.in_shell = true;
	datash.interactive = isatty(STDIN_FILENO);
	datash._environ = environ;

	print_prompt(datash.interactive);

	while (datash.in_shell)
	{
		char *line = NULL;
		size_t len = 0;
		ssize_t chars_read;

		chars_read = getline(&line, &len, stdin);
		if (chars_read == -1)
		{
			handle_eof(&datash);
			continue;
		}

		if (is_all_delims(line, " \n"))
		{
			free(line);
			print_prompt(datash.interactive);
			continue;
		}

		line[strcspn(line, "\n")] = '\0';

		handle_command(line, &datash);

		free(line);
		print_prompt(datash.interactive);
	}

	return (0);
}
