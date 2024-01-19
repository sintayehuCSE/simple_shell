#include "shell.h"
/**
 * len - Calculates the number of characters within a string
 * @str: String whose length is to be determined
 *
 * Return: The lenght of the string or 0
 */
int len(char *str)
{
	int len = 0;

	while (str && *str++)
		len++;
	return (len);
}
/**
 * _puts - Print a string to the output stream
 * @str: The string to be printed
 *
 * Return: The number of byte written
 */
int _puts(char *str)
{
	int written_byte = 0;

	while (str && *str++)
	{
		_putchar(*str);
		written_byte++;
	}
	return (written_byte);
}
/**
 * _putchar - Fill in buffer with character from string and print it to stdout
 * @c: The character to printed
 *
 * Return: No return value
 */
void _putchar(char c)
{
	static int i;
	static char buf[BUF_SIZE];

	if (c == FLUSH_BUF || i >= BUF_SIZE)
	{
		write(1, buf, i);
		i = 0;
	}
	if (c != FLUSH_BUF)
	{
		buf[i] = c;
		i++;
	}
}
