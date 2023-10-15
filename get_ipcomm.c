#include "main.h"

/**
 * get_ipcomm - Function for reading input command
 *
 *Description : Fnuction for reading the input command from user
 *
 *Return: pointer to the input string, Null if failed
 */

char *get_ipcomm(void)
{
	char *inbuffer = NULL;
	size_t inbufsize = 0;
	ssize_t	chars;

	if (isatty(STDIN_FILENO))
		write(STDOUT_FILENO, "$ ", 2);

	chars = getline(&inbuffer, &inbufsize, stdin);
	if (chars == -1)
	{
		free(inbuffer);
		return (NULL);
	}
	return (inbuffer);
}

