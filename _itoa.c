#include "main.h"

/**
 * _itoa - Function to convert integer to string
 *@index : input integer
 *
 *Return: pointer to converted input string
 */

char *_itoa(int index)
{
	int n = 0;
	char output[32];

	if (index == 0)
		output[n++] = '0';
	else
	{
		while (index > 0)
		{
			output[n++] = (index % 10) + '0';
			index = index / 10;
		}
	}
	output[n] = '\0';
	str_rev(output, n);
	return (strdup(output));
}

/**
 * str_rev - Function to reverse a string
 *@output : input string
 *@l : length of iput string
 *
 */

void str_rev(char *output, int l)
{
	char hold;
	int i = 0;
	int j = l - 1;

	while (i < j)
	{
		hold = output[i];
		output[i] = output[j];
		output[j] = hold;
		i++;
		j--;
	}
}

