#include "shell.h"
/**
 * get_cmd - Buffer a chained commands
 * @info: Parameter structure
 * @buf: Address of the buffer
 * @len: Address of length variable
 *
 * Return: Bytes read or -1 on error
 */
ssize_t get_cmd(info_t *info, char **buf, size_t *len)
{
	ssize_t r = 0;
	size_t len_p = 0;

	if (!*len)
	{
		r = getline(buf, &len_p, stdin);
		if (r> 0)
			if ((*buf)[r - 1] == '\n')
			{
				(*buf)[r - 1] == '\0';
				r--;
			}
		*len = r;
		info->cmd_buf = buf;
	}
	return (r);
}
/**
 * read_cmd - Read the command from command input/command file or stdin/
 * @info: The command information structure
 *
 * Return: The bytes read or on error -1
 */
ssize_t read_cmd(info_t *info)
{
	static char *buf;
	static size_t len;
	ssize_t r = 0;

	_putchar(FLUSH_BUF);
	r = get_cmd(info, &buf, &len);
	if (r == -1)
		return (r);
	return (r);
}
