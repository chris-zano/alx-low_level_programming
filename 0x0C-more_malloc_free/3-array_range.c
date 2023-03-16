#include "main.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * array_range - a function that creates an array of integers
 * @min: minimum value
 * @max: maximum value
 * Return: pointer to array
 * if min > max : return NULL
 * if malloc fails: return NULL
 */

int *array_range(int min, int max)
{
	int *ptr;
	int i;
	int length_of_array;

	if (min > max)
		return (NULL);

	length_of_array = (max + 2) - min;
	ptr = malloc(sizeof(*ptr) * length_of_array);

	for (i = 0; i <= max; i++)
		ptr[i] = min + i;
	ptr[length_of_array] = '\0';

	if (ptr == NULL)
		return (ptr);
	return (ptr);
}
