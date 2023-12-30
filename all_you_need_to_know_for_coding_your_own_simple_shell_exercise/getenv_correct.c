#include <stdio.h>
#include "_strtok_correct.c"
char *getenv(const char *);
extern char **environ;

int main(void)
{
	char *env;
	int i = 0;

	while (environ[i])
	{
		env = getenv(environ[i]);
		if (env)
			printf("%s\n", env);
		i++;
	}
	return (0);
}
char *getenv(const char *env)
{
	int i = 0;
	char *env_value;

	while (environ[i])
	{
		if (environ[i] == env)
		{
			env_value = _strtok(environ[i], "=");
			return (env_value = _strtok(NULL, "="));
		}
		else
		{
			i++;
		}
	}
	printf("%s: No Such user environment variable!\n", env);
	exit(EXIT_FAILURE);
	return (NULL);
}
