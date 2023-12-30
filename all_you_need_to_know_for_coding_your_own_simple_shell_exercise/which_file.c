#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
void check_file_existence(char *);

int main(void)
{
	char *buffer;
	size_t buffer_size = 0;
	char *token;

	while (1)
	{
		write(1, "CisFun$ ", 8);
		getline(&buffer, &buffer_size, stdin);
		token = strtok(buffer, " \n\t");
		if (token && strcmp(token, "which") == 0)
		{
			token = strtok(NULL, " \n\t");
			if (!token)
			{
				printf("which expects atleast one argument. 0 found\n");
			}
			while (token)
			{
				check_file_existence(token);
				token = strtok(NULL, " \n\t");
			}
		}
		else
		{
			if (token)
				printf("%s: Invalid command\n", token);
		}
	}
	free(buffer);
	return (0);
}

void check_file_existence(char *token)
{
	if (access(token, F_OK) == 0)
		printf("%s: Found the file\n", token);
	else
		printf("%s: File not found\n", token);
}
