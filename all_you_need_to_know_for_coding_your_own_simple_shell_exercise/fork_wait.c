#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main(void)
{
	int wstatus;
	pid_t child_id;

	child_id = fork();
	if (child_id == -1)
	{
		perror("Error:");
	}
	if (child_id == 0)
	{
		printf("I am the child of this process PID = %u, Dad please wait, let me finish running\n", getpid());
	}
	else
	{
		wstatus = 3;
		wait(&wstatus);
		printf("Okay son I am waiting PID = %u, tell me if you are done with running\n", getpid());
	}
	if (child_id == 0)
		printf("Dad, I am done. You can continue your running\n");
	printf("Who am I? ID is: %u\n", getpid());
	return (0);
}
