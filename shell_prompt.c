#include "shell.h"
int display_prompt(info_t *info, char *argv[])
{
	ssize_t return_stat = 0;

	while (return_stat != -1)
	{
		_puts("$ ");
		return_stat = read_cmd(info_t *info);
		if (r != -1)
		{
			execute_command(info, argv);
		}
	}
	return (0);
}
void execute_command(info_t *info)
{
	if (execve(info-> *cmd_buf, argv, environ) == -1)
		perror("Error: ");
}
