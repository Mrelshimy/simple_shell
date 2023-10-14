#include "main.h"

/**
 * main - Simple Shell , Entry point
 *@ac : Number of input arguments
 *@av : Input arguments vector
 *
 *Description : C program for mimicing shell operation
 *
 *Return: Same as shell exit status
 */

int main(int ac, char **av)
{
	char *inbuffer = NULL, **comm_vec = NULL;
	int ret = 0, index = 0, *p = &ret;

	(void)ac;

	while (1)
	{
		inbuffer = get_ipcomm();
		if (inbuffer == NULL)
		{
			if (isatty(STDIN_FILENO))
				write(STDOUT_FILENO, "\n", 1);
			return (ret);
		}
		index++;
		comm_vec = token_gen(inbuffer);
		if (!comm_vec)
			continue;

		if (bin_fn(comm_vec[0]))
			exec_bin(comm_vec, av, p, index);
		else
			ret = exec_comm(comm_vec, av, index);
	}
}
