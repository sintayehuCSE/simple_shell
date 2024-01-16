#include "shell.h"
int len(char *);
int display_prompt(char *argv[])
{
	char *line_buf = NULL;
	size_t line_size = 0;
	pid_t child_pid;
	int status = 3;

	while (1)
	{
		write(1, "#cisfun$ ", 9);
		getline(&line_buf, &line_size, stdin);
		child_pid = fork();
		if (child_pid == -1)
			perror("Error: ");
		if (child_pid == 0)
		{
			if (execve(line_buf, argv, NULL) == -1)
			{
				write(1, argv[0], len(argv[0]));
				perror(": ");
			}
		}
		else
		{
			wait(&status);
			free(line_buf);
		}
	}
	return (0);
}
int len(char *str)
{
	int len = 0;

	while (str && str[len])
		len++;
	return (len);
}
