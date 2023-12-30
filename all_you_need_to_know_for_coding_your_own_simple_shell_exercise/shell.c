#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <sys/wait.h>
int len_buffer(char *);

int main(void)
{
	char *buffer = NULL;
	size_t buf_size = 0, i = 0;
	char *token;
	char **argv;
	pid_t child_id;
	int wstatus = 3;

	while (1)
	{
		write(1, "CisFun$ ", 8);
		getline(&buffer, &buf_size, stdin);
		argv = malloc(sizeof(char *) + len_buffer(buffer));
		token = strtok(buffer, " \t\n");
		while (token)
		{
			argv[i] = token;
			i++;
			token = strtok(NULL, " \t\n");
		}
		argv[i] = NULL;
		i = 0;
		child_id = fork();
		if (child_id == -1)
			printf("Failed to create child process");
		else if (child_id == 0)
		{
			if (execve(argv[i], argv, NULL) == -1)
				perror("Error: ");
		}
		else
		{
			wait(&wstatus);
			free(buffer);
			free(argv);
		}
	}
	return (0);
}
int len_buffer(char *buffer)
{
	int len = 0;
	while (buffer && buffer[len])
		len++;
	return (len);
}
