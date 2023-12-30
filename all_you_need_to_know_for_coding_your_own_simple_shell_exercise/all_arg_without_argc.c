#include <stdio.h>
int main(int argc, char *argv[])
{
	int i = 0;
	(void)(argc);

	while (argv[i])
	{
		printf("%s ", argv[i]);
		i++;
	}
	putchar(10);
	return (0);
}
