#include "main.h"

/**
 * token_gen - Function for tokenizing the input arguments
 *@inbuffer : input arguments line
 *
 *Description : C code for tokenizing the input buffer
 *
 *Return: 2d string containing the input buffer
 */

char **token_gen(char *inbuffer)
{
	char *token = NULL, *inbuf_cpy, **argv = NULL;
	int n = 0, arg_cnt = 0;

	inbuf_cpy = strdup(inbuffer);
	token = strtok(inbuf_cpy, " \t\n");
	if (token == NULL)
	{   free(inbuf_cpy);
		free(inbuffer);
		return (NULL);
	}
	while (token)
	{   arg_cnt++;
		token = strtok(NULL, " \t\n");
	}
	free(inbuf_cpy);

	argv = malloc(sizeof(char *) * (arg_cnt + 1));
	if (!argv)
	{   free(inbuffer);
		return (NULL);
	}

	token = strtok(inbuffer, " \t\n");
	while (token)
	{
		if (token[0] == '#')
			goto finish;
		argv[n] = strdup(token);
		n++;
		token = strtok(NULL, " \t\n");
	}
finish:
	free(inbuffer);
	argv[n] = NULL;
	return (argv);
}
