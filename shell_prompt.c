#include "shell.h"
int display_prompt(info_t *info, char *argv[])
{
	ssize_t return_stat = 0;

	while (return_stat != -1)
	{
		_puts("$ ");
		return_stat = read_cmd(info);
		if (return_stat != -1)
		{
			execute_command(info, argv);
		}
	}
	return (0);
}
void execute_command(info_t *info, char **argv)
{
	fork_cmd(info, argv);
}
void fork_cmd(info_t *info, char **argv)
{
	pid_t pid;
	int status;

	pid = fork();
	if (pid == -1)
		perror("Error: ");
	if (pid == 0)
	{
		if (execve(*(info->cmd_buf), argv, environ) == -1)
			perror("Error");
	}
	else
	{
		wait(&status);
		printf("Here");
		free(*(info->cmd_buf));
	}
}
