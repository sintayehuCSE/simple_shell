#include "shell.h"
/**
* display_prompt - The road to display prompt
* command execution
* @info: Pointer to the shell info struct variable
* @argv: The command line argument to simple shell program
*
* Return: 0 on success otherwise -1
*/
int display_prompt(info_t *info, char *argv[])
{
	ssize_t read_stat = 0;

	while (read_stat != -1)
	{
		_puts("$ ");
		read_stat = read_cmd(info);
		if (read_stat != -1)
		{
			execute_command(info, argv);
		}
	}
	return (0);
}
/**
* execute_command - Call for execution of a command
* @info: Pointer to the shell_info struct variable
* @argv: Notnsdlkbjlsk;dklkjdf
*
* Return: Nothing
*/
void execute_command(info_t *info, char **argv)
{
	fork_cmd(info, argv);
}
/**
* fork_cmd - Used for executing a command in child process
* @info: Pointer to shell_info struct variable
* @argv: Not needed in future
*
* Return: Nothing
*/
void fork_cmd(info_t *info, char **argv)
{
	pid_t pid;
	int status;

	pid = fork();
	if (pid == -1)
		perror("Error: ");
	if (pid == 0)
	{
		if (execve(info->arg, argv, environ) == -1)
			perror("Error");
	}
	else
	{
		wait(&status);
		free(info->arg);
	}
}
