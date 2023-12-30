#ifndef SHELL_HEADER
#define SHELL_HEADER
#define SHELL_INIT {NULL, NULL, NULL, 0, 0, 0, 0, NULL, NULL, NULL, NULL, NULL\
		, 0, 0, NULL, 0, 0, 0}

#include <stdio.h>

/**
 * struct list_s - Defines a singly linked list
 * @num: An integer data member
 * @str: String data member
 * @next: Pointer to next list node
 */
typedef struct list_s
{
	int num;
	char *str;
	struct list_s *next;
} list_t;
/**
 * struct shell_info - A structure for storing and manipulating shell
 * command information
 * @arg: Coming soon...!
 * @argv: Coming soon...!
 * @path: Coming soon...!
 * @argc: Coming soon...!
 * @line_count: Coming soon...!
 * @err_num: Coming soon...
 * @linecount_flag: Coming soon...!
 * @fname: Coming soon...!
 * @env: Coming soon...!
 * @history: Coming soon...!
 * @alias: Coming soon...!
 * @environ: Coming soon...!
 * @env_changed: Coming soon...!
 * @status: Coming soon...!
 * @cmd_buf: Coming soon...!
 * @cmd_buf_type: Coming soon...!
 * @readfd: Coming soon...!
 * @histcount: Coming soon...!
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
	list_t  *history;
	list_t *alias;
	char **environ;
	int env_changed;
	int status;
	char **cmd_buf;
	int cmd_buf_type;
	int readfd;
	int histcount;
} info_t;

#endif /** SHELL_HEADER */
