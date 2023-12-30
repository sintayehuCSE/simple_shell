#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
ssize_t _getline(char **lineptr, size_t *size, FILE *stream);

int main(int argc, char *argv[])
{
	char *line_read = NULL;
	size_t line_size = 30;
	FILE *file_ptr;

	if (argc < 2)
	{
		printf("Command file not provided\n");
		exit(EXIT_FAILURE);
	}
	file_ptr = fopen(argv[1], "r");
	if (!file_ptr)
		perror("Error: "), exit(0);
	_getline(&line_read, &line_size, file_ptr);
	printf("%s", line_read);
	free(line_read);
	if ((fclose(file_ptr) != 0))
		perror("Error: ");
	return (0);
}
ssize_t _getline(char **lineptr, size_t *size, FILE *stream)
{
	size_t line_size = 1;
	char check_buf[1];
	long off_set;

	if (!stream)
		return (-1);
	fseek(stream, 0L, SEEK_END);
	off_set = ftell(stream);
	if (!off_set)
	{
		write(STDOUT_FILENO, "File is empty\n", 14);
		return (-1);
	}
	fseek(stream, 0L, SEEK_SET);
	fread(check_buf, 1, 1, stream);
	while (check_buf[0] != '\n')
	{
		fread(check_buf, 1, 1, stream);
		line_size++;
	}
	if (fseek(stream, 0L, SEEK_SET))
	{
		perror("Error: ");
		return (-1);
	}
	if (!*lineptr && !*size)
	{
		*lineptr = malloc(sizeof(char) * line_size);
		*size = line_size;
	}
	else if (*size < line_size || *size > line_size)
	{
		*size = line_size;
		*lineptr = realloc(*lineptr, *size);
	}
	else
	{
		*size = line_size;
		*lineptr = malloc(sizeof(char) * (*size));
	}
	if (!*lineptr)
	{
		perror("Error: ");
		return (-1);
	}
	fread(*lineptr, 1, line_size, stream);
	return (line_size);
}
