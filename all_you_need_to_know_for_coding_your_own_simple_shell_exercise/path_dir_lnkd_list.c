#include <stdio.h>
#include <string.h>
#include "path_lnkd_strtok.c"
extern char **environ;
typedef struct path_dir
{
	char *dir;
	struct path_dir *next;
} path_dir_t;
path_dir_t *create_path_dir_lnkd_lst(char *);

int main(void)
{
	int i = 0;
	path_dir_t *head, *h, *tmp;
	char *path = "PATH";
	char *env;

	while (environ[i])
	{
		env = _strtok(environ[i], "=");
		if (strcmp(env, path) == 0)
			break;
		i++;
	}
	head = create_path_dir_lnkd_lst(environ[i]);
	h = head;
	while (head)
	{
		printf("%s\n", head->dir);
		head = head->next;
	}
	while (h)
	{
		tmp = h->next;
		free(h->dir);
		free(h);
		h = tmp;
	}
	return (0);
}
path_dir_t *create_path_dir_lnkd_lst(char *envir)
{
	path_dir_t *new_dir;
	path_dir_t *head_dir;
	path_dir_t *tail_dir;
	char *env, *path = "PATH";
	int first_iter = 1;

	env = _strtok(envir, "=");
	while (env)
	{
		new_dir = malloc(sizeof(path_dir_t));
		if (!new_dir)
			perror("Error: ");
		if (first_iter && strcmp(env, path) == 0)
		{
			head_dir = new_dir;
			tail_dir = new_dir;
		}
		env = _strtok(NULL, ":");
		if (env)
		{
			new_dir->dir = env;
			new_dir->next = NULL;
		}
		else
		{
			free(new_dir);
			break;
		}
		if (!first_iter)
		{
			tail_dir->next = new_dir;
			tail_dir = new_dir;
		}
		first_iter = 0;
	}
	return (head_dir);
}
