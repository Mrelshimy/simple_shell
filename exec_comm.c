#include "main.h"

/**
 * exec_comm - Function to excute commmand
 *@comm : input command
 *@argv : input command arguments vector
 *@index : index of the input command
 *
 *Description : Code for excuting the input tokenized command
 *
 *Return: excuted command exit status
 */

int exec_comm(char **comm, char **argv, int index)
{
	pid_t pid;
	int ret = 0;
	char *file_path;

	file_path = path_find(comm[0]);
	if (file_path == NULL)
	{
		err_format(argv[0], comm[0], index);
		free_arr(comm);
		return (127);
	}

	pid = fork();
	if (pid == 0)
	{
		if (execve(file_path, comm, environ) == -1)
		{
			free(file_path);
			free_arr(comm);
			exit(0);
		}
	}
	else
	{
		waitpid(pid, &ret, 0);
		free_arr(comm);
		free(file_path);
	}
	return (WEXITSTATUS(ret));
}

