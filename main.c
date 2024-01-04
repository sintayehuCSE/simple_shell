#include "shell.h"
/**
 * main - Shell entry point
 * @ac: Command line argument count
 * @av: Command line argument to the shell program
 *
 * Return: 0 on success, 1 on error
 */
int main(int ac, char *av[])
{
	info_t info[] = { SHELL_INIT };
	int fd = 2;

	if (ac == 2)
	{
		fd = open(av[1], O_RDONLY);
		info->read = fd;
	}
	populate_env_list(info);
}
