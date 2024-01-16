#include "shell.h"
/**
 * main - Simple shell entry point
 * @ac: Count the command line argument to the shell
 * @argv: The command line argument of the shell
 *
 * Return: 0 on success -1 otherwise
 */
int main(int ac, char *argv[])
{
	if (ac == 2)
		execve(argv[1], argv, NULL);
	display_prompt(argv);
	return (0);
}
