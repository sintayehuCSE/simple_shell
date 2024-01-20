#ifndef SHELL_H
#define SHELL_H
#define INIT_SHELL {NULL, NULL, NULL, 0, 0, 0, 0, NULL, NULL, NULL, NULL, NULL\
		, 0, 0, NULL, 0, 0, 0}

#define BUF_SIZE 1024
#define FLUSH_BUF 1


#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
extern char **environ;

/**
 * typedef struct list_s - A singly linked list structure
 * @n: Index of the node
 * @str: A string value of the node
 * @next: Pointer to the next node in the list
 */
typedef struct list_s
{
	int num;
	char *str;
	struct list_s *next;
} list_t;
/**
 * typedef struct shell_info - Information about the shell commands
 * @arg: String of command and its arguments
 * @argv: An array pointer of arg strings
 * @path: A string path for the current command
 * @argc: The count of argument on cmd line
 * @line_count: The line in prgram where error happens
 * @err_num: The error code to exit with exit() functions
 * @linecount_flag: fdgudfg
 * @fname: The name of file that contain the command
 * @env: A local copy of environ as a linked list
 * @environ: A customized copy of built-in environ from env
 * @history: Linked list of executed command history
 * @alias: Linked list of command's alias node
 * @env_changed: Check the status of the environ and turn on if true/changed
 * @status: The return status of the last executed commad/program
 * @cmd_buf: Address of pointer to cmd_buf, on if chaining
 * @cmd_buf_type: The type of cmd, chained or not
 * @readfd: The file descriptor of open file to provide command of execution
 * @histcount: Count the number of line in the history linked list to modify
               history file
 */

typedef struct shell_info
{
	char *arg;
	char **argv;
	char *path;
	int argc;
	unsigned int line_count;
	int err_num;
	int linecount_flag;
	char *fname;
	list_t *env;
	list_t *history;
	list_t *alias;
	char **environ;
	int env_changed;
	int status;
	char **cmd_buf;
	int cmd_buf_type;
	int readfd;
	int histcount;
} info_t;

/**.......Display the never ending next command prompt of simple shell........*/
int display_prompt(info_t *, char **);
/**.......For string manipulation we use below functions......................*/
int len(char *);
int _puts(char *);
void _putchar(char );
/**...............Read and format input from command line.....................*/
ssize_t get_cmd(info_t *, char *, size_t *);
ssize_t read_cmd(info_t *info);
void execute_command(info_t *, char **);
void fork_cmd(info_t *, char **);
#endif /* SHELL_H */
