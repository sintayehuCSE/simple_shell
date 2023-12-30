#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
	int i = 0;
	struct stat st;

	if (argc < 2)
	{
		printf("Provide atleast two file name\n");
		exit(EXIT_FAILURE);
	}
	while (argv[i])
	{
		if (stat(argv[i], &st) == 0)
		{
			printf("Found the file argv[%i]: %s >>>With below Information<<<\n\n", i, argv[i]);
			printf("%ld: ID of device containing the file\n", st.st_dev);
			printf("%ld: Inode number of the file\n", st.st_ino);
			printf("%d: File type and mode\n", st.st_mode);
			printf("%ld: Number of hard links to the file\n", st.st_nlink);
			printf("%d: User ID of file owner\n", st.st_uid);
			printf("%d: Group ID of file owner\n", st.st_gid);
			printf("%ld: Device ID (if special file)\n", st.st_rdev);
			printf("%ld: Total size of the file, in bytes\n", st.st_size);
			printf("%ld: Block size for filesystem I/O\n", st.st_blksize);
			printf("%ld: Number of 512B blocks allocated to the file\n\n", st.st_blocks);
		}
		else
			printf("Couldn't find the file argv[%i]: %s\n", i, argv[i]);
		i++;
	}
	return (0);
}
