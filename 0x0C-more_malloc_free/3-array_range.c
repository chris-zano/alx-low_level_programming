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

	length_of_array = max - min + 1;
	ptr = malloc(sizeof(*ptr) * length_of_array);

	if (ptr == NULL)
		return (NULL);

	for (i = 0; i < length_of_array; i++)
		ptr[i] = min++;
	return (ptr);
}
