#include "main.h"

/**
 * bin_fn - Function to check the if command is built-in
 *@comm : input command
 *
 *Return: 1 if built-in , 0 if not
 */

int bin_fn(char *comm)
{
	int n;
	char *bin_comms[4] = {
		"cd", "exit", "env", NULL
	};
	for (n = 0; bin_comms[n]; n++)
	{
		if (strcmp(comm, bin_comms[n]) == 0)
			return (1);
	}
	return (0);
}


/**
 * exec_bin - Function to execute b-in functions
 *@comm : input command
 *@argv : input arguments vector
 *@ret : return value
 *@index : command index
 *
 */

void exec_bin(char **comm, char **argv, int *ret,  int index)
{
	int i;

	if (strcmp(comm[0], "exit") == 0)
		exit_fn(comm, argv, ret,  index);

	else if (strcmp(comm[0], "env") == 0)
	{
		for (i = 0; environ[i]; i++)
		{
			write(STDOUT_FILENO, environ[i], strlen(environ[i]));
			write(STDOUT_FILENO, "\n", 1);
		}
		free_arr(comm);
		ret = 0;
	}

	else if (strcmp(comm[0], "cd") == 0)
		cd_fn(comm, argv, ret, index);
}

/**
 * exit_fn - Function to execute exit command
 *@comm : input command
 *@argv : input arguments vector
 *@ret : return value
 *@index : command index
 *
 */

void exit_fn(char **comm, char **argv, int *ret,  int index)
{
	int ex_num = (*ret);

	if (comm[1])
	{
		if (pos_num(comm[1]))
		{
			ex_num = atoi(comm[1]);
			free_arr(comm);
			exit(ex_num);
		}
		else
		{
			char *s_index = _itoa(index);

			write(STDERR_FILENO, argv[0], strlen(argv[0]));
			write(STDERR_FILENO, ": ", 2);
			write(STDERR_FILENO, s_index, strlen(s_index));
			write(STDERR_FILENO, ": ", 2);
			write(STDERR_FILENO, "exit: Illegal number: ", 22);
			write(STDERR_FILENO, comm[1], strlen(comm[1]));
			write(STDERR_FILENO, "\n", 1);
			free(s_index);
			(*ret) = 2;
			free_arr(comm);
			return;
		}
	}
	free_arr(comm);
	exit(ex_num);
}

/**
 * cd_fn - Function to execute cd command
 *@comm : input command
 *@argv : input arguments vector
 *@ret : return value
 *@index : command index
 *
 */

void cd_fn(char **comm, char **argv, int *ret,  int index)
{
	DIR *op_dir = NULL;

	if (!getenv("HOME"))
	{	free_arr(comm);
		return;
	}

	if (comm[1] == NULL)
	{	chdir(getenv("HOME"));
		free_arr(comm);
		(*ret) = 0;
		return;
	}
	else
	{	op_dir = opendir(comm[1]);
		if (!op_dir)
		{	cd_err_format(argv[0], comm[1], index);
			free_arr(comm);
			free(op_dir);
			(*ret) = 2;
		}
		else
		{	chdir(comm[1]);
			free_arr(comm);
			free(op_dir);
			(*ret) = 0;
		}
		return;
	}
}


/**
 * pos_num - Function to chack if input is positive number
 *@buff : input buffer
 *
 *Return: 1 if success, 0 if fail
 */
int pos_num(char *buff)
{
	int n;

	if (!buff)
		return (0);
	for (n = 0; buff[n]; n++)
	{
		if (buff[n] < '0' || buff[n] > '9')
			return (0);
	}
	return (1);
}

