#include <stdio.h>
#include <unistd.h>

int main(void)
{
	char *argv[] = {"/bin/ls", "-l", NULL};
	if (execve(argv[0], argv, NULL) == -1)
		printf("Failed to run the program");
	printf("I won't be visited because of this execve");
	return (0);
}
