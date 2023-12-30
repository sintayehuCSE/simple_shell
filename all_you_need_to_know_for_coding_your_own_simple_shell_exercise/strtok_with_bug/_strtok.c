#include <stdio.h>
#include <stdlib.h>
int str_len(const char *);
char *token(char *);

char *_strtok(char *a_str, const char *delim)
{
	static int len, i, j, d, end_of_str;
	static char *word;
	static char *str;
	static char *token_var;
	int len_delim = 0;

	if (!delim)
		exit(EXIT_FAILURE);
	len_delim = str_len(delim);
	if (a_str)
	{
		str = a_str;
		i = 0;
		len = str_len(str);
		word = malloc(sizeof(char) * (len + 1));
		if (!word)
			perror("Error: ");
	}
	else
	{
		free(token_var);
	}
	if (end_of_str)
	{
		free(word);
		exit(EXIT_SUCCESS);
	}
	for (j = 0; i < len; i++)
	{
		for (d = 0; d < len_delim; d++)
		{
			if (str[i] == delim[d])
			{
				word[j] = '\0';
				i++;
				return (token_var = token(word));
			}
		}
		word[j] = str[i];
		j++;
	}
	if (str[i] == '\0')
	{
		word[j] = '\0';
		end_of_str = 1;
		i = 0;
		return (token_var = token(word));
	}
	exit(EXIT_SUCCESS);
	return (NULL);
}
int str_len(const char *str)
{
	int len = 0;
	while (str[len] && str)
		len++;
	return (len);
}
char *token(char *word)
{
	int len, i;
	char *token;

	len = str_len(word);
	token = malloc(sizeof(char) * (len + 1));
	if (!token)
		perror("Error: ");
	for (i = 0; i < len; i++)
	{
		token[i] = word[i];
		if (token[i] == '\0')
			return (token);
	}
	token[i] = '\0';
	if (token[0] == '\0')
		exit(EXIT_SUCCESS);
	return (token);
}
