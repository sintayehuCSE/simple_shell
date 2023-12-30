#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "_strtok.c"

int main(int argc, char *argv[])
{
	char *line_read = NULL;
	size_t line_size= 0;
	FILE *file_ptr;
	char *token;

	if (argc < 2)
	{
		printf("Command file not provided\n");
		exit(EXIT_FAILURE);
	}
	file_ptr = fopen(argv[1], "r");
	getline(&line_read, &line_size, file_ptr);
	printf("%s", line_read);

	printf("The start of string tokenization\n");
	token = _strtok(line_read, " \n\t");
	while (token)
	{
		printf("%s\n", token);
		token = _strtok(NULL, " \n\t");
	}
	free(line_read);
	return (0);
}
