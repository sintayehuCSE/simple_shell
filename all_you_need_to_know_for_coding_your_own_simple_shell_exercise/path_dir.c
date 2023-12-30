#include <stdio.h>
#include <string.h>
#include "_strtok_correct.c"
extern char **environ;

int main(void)
{
	char *env;
	int i = 0;
	char *path = "PATH";

	while (environ[i])
	{
		env = _strtok(environ[i], "=");
		if (strcmp(env, path) == 0)
			break;
		i++;
	}
	while (env)
	{
		env = _strtok(NULL, ":");
		if (env)
			printf("%s\n", env);
	}
	return (0);
}
