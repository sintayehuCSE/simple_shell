#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>

int main(void)
{
	int i = 0;
	int wstatus = 3;
	pid_t child_id;
	char *argv[] = {"/bin/ls", "-l", "/tmp", NULL};

	for (; i < 5; i++)
	{
		child_id = fork();
		if (child_id == 0)
		{
			printf("......I am %u on round %i.....\n", getpid(), i);
			if (execve(argv[0], argv, NULL) == -1)
			{
				perror("Erro:\n");
				exit(EXIT_FAILURE);
			}
		}
		else
			wait(&wstatus);
	}
	return (0);
}
