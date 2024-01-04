#include <shell.h>
/**
 * Create singly linked list of environment variable of the shell command
 * @info: Information about the shell session of current command.
 *
 * Return: 0 on success, -1 on failure
 */
int populate_env_list(info_t *info)
{
	list_t *node = NULL;
	size_t i;

	for (i = 0; environ[i]; i++)
		add_node_end(&node, environ[i], 0);
	info->env = node;
	return (0);
}
