#include "main.h"

/**
 * free_arr - Function to free 2D array
 *@arr : input 2D array
 *
 *Description : C code for freeing 2D array and it's elements
 *
 */

void free_arr(char **arr)
{
	int i;

	if (!arr)
		return;

	for (i = 0; arr[i]; i++)
	{
		free(arr[i]);
		arr[i] = NULL;
	}
	free(arr);
	arr = NULL;

}

