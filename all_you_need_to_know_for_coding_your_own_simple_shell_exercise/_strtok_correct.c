#include <stdio.h>
#include <stdlib.h>
int str_len(const char *);
char *tokenize(char *, int, int);
/**
 * _strtok - A function that will convert a string into sequence of
 * zero or more non-empty tokens.
 * @a_str: A string to be tokenized.
 * @delim: Token delimeter
 *
 * Return: A pointer to each token of a string.
*/

char *_strtok(char *a_str, const char *delim)
{
	static char *str, *token;
	static int i = 0, len;
	int delim_len, found_end = 0, start, end, d;

	if (a_str)
	{
		str = a_str;
		i = 0;
		len = str_len(str);
	}
	else
	{
		free(token);
	}
	if (i == len)
	{
		i = 0;
		return (NULL);
	}
	delim_len = str_len(delim);
	for (; i < len;)
	{
		for (d = 0; d < delim_len;)
		{
			if (str[i] == delim[d])
			{
				i++;
				d = 0;
				continue;
			}
			if (str[i] == '\0')
			{
				i = 0;
				return (NULL);
			}
			d++;
		}
		start = i;
		break;
	}
	for (; i < len; i++)
	{
		for (d = 0; d < delim_len; d++)
		{
			if (str[i] == delim[d])
			{
				end = i;
				found_end = 1;
				break;
			}
		}
		if (found_end)
		{
			i++;
			break;
		}
	}
	if (str[i] == '\0' && !found_end)
		end = i;
	return (token = tokenize(str, start, end));
}
/**
 * str_len - Calculates a length of a string.
 * @str: A string whose lenght is to be calculated.
 *
 * Return: Lenght of a string.
 */
int str_len(const char *str)
{
	int len = 0;

	while (str && str[len])
		len++;
	return (len);
}
/**
 * tokenize - Exract the token from a given string.
 * @str: The string to yield a token.
 * @start: The start of the token within a string;
 * @end: The end of the token within the string
 *
 * Return: The extracted/mined token.
 */
char *tokenize(char *str, int start, int end)
{
	int i = 0;
	char *token;

	token = malloc(sizeof(char) * ((end - start) + 1));
	if (!token)
		perror("Error: ");
	for (; start < end; start++)
	{
		token[i] = str[start];
		i++;
	}
	token[i] = '\0';
	return (token);
}
