#include "main.h"

/**
 * path_find - Code for finding the complete path for the input command
 *@comm : input command
 *
 *Description : Code for finding the complete path for the input command
 *
 *Return: complete path, Null if not found
 */

char *path_find(char *comm)
{
	char *token, *file_path = NULL, *path_tot = NULL;
	char *path_copy = NULL, *result = NULL;
	int n = 0;
	struct stat st;

	for (n = 0; comm[n]; n++)
	{
		if (comm[n] == '/')
		{
			if (stat(comm, &st) == 0)
			{   result = strdup(comm);
				goto cleanup;
			}
			goto cleanup;
		}
	}
	path_tot = getenv("PATH");

	if (!path_tot)
		return (NULL);
	path_copy = strdup(path_tot);

	token = strtok(path_copy, ":");
	while (token != NULL)
	{   file_path = malloc(strlen(token) + strlen(comm) + 2);
		strcpy(file_path, token);
		strcat(file_path, "/");
		strcat(file_path, comm);
		if (stat(file_path, &st) == 0)
		{   result = file_path;
			goto cleanup;
		}
		else
		{   free(file_path);
			token = strtok(NULL, ":");
		}
	}
cleanup:
	free(path_copy);
	return (result);
}

