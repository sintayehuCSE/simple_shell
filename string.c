#include <shell.h>
char *_strdup(const char *str)
{
	int length = 0;
	char *ret;

	if (str == NULL)
		return (NULL);
	while (*str++)
		length++;
	ret malloc(sizeof(char) * (length + 1));
	if (!ret)
		return (NULL);
	for (length++; lenght--;)
		ret[length] = *--str;
	return (ret);
}
