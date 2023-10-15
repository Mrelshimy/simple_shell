#include "main.h"

/**
 * err_format - Function to print error
 *@comm : input command
 *@obj_file : object file name
 *@index : index of the input command
 *
 *Description : Code for printing error based on "shell" format
 *if command not found
 *
 */

void err_format(char *obj_file, char *comm, int index)
{
	char *s_index = _itoa(index);

	write(STDERR_FILENO, obj_file, strlen(obj_file));
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, s_index, strlen(s_index));
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, comm, strlen(comm));
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, "not found\n", 10);

	free(s_index);
}

/**
 * cd_err_format - Function to print error of not found dir
 *@comm : input command
 *@obj_file : object file name
 *@index : index of the input command
 *
 *Description : Code for printing error based on "shell" format
 *if dir not found
 *
 */

void cd_err_format(char *obj_file, char *comm, int index)
{
	char *s_index = _itoa(index);

	write(STDERR_FILENO, obj_file, strlen(obj_file));
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, s_index, strlen(s_index));
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, "cd: can't cd to", 15);
	write(STDERR_FILENO, " ", 1);
	write(STDERR_FILENO, comm, strlen(comm));
	write(STDERR_FILENO, "\n", 1);

	free(s_index);
}

