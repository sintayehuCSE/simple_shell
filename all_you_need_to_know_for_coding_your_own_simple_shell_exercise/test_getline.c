#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

int main(void)
{
	int fd, i = 0, c_stat;
	ssize_t rturn = -1;
	char read_buf[1];
	char array[1024];

	fd = open("text.txt", O_RDONLY);
	if (fd == -1)
		perror("Error: ");
	array[0] = '1';
	i++;
	while (array[i - 1] != '\n' && rturn != 0)
	{
		rturn = read(fd, read_buf, 1);
		if (rturn == -1)
		{
			perror("Error: ");
			exit(EXIT_FAILURE);
		}
		array[i] = read_buf[0];
		i++;
	}
	array[i] = '\0';
	i = 1;
	while (array[i])
	{
		printf("%c", array[i]);
		i++;
	}
	c_stat = close(fd);
	if (c_stat == -1)
		perror("Error: ");
	return (0);
}
