#include <stdio.h>
#include <unistd.h>

int main(void)
{
	pid_t child_id;

	printf("Before call to fork\n");
	child_id = fork();
	if (child_id == -1)
	{
		perror("Error:");
	}
	printf("After call to fork\n");
	printf("Parent ID is: %u\n", getpid());
	return (0);
}
