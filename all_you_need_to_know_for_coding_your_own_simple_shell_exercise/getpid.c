#include <stdio.h>
#include <unistd.h>
int main()
{
	printf("I am %u process. a child of %u\n", getpid(), getppid());
	return (0);
}
