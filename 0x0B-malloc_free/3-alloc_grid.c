#include "main.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * alloc_grid - returns a pointer to a 2 dimensional array of integers.
 * @width: number of rows
 * @height: number of columns
 * Return: return pointer to 2d array
 * return null on failure
 * if width or height is zero or negative return null
 */

int **alloc_grid(int width, int height)
{
	int i;
	int **ptr;

	ptr = (int **) malloc(width * sizeof(int *));

	if (width <= 0 || height <= 0)
		return (NULL);
	if (ptr == NULL)
		return (NULL);
	for (i = 0; i < width; i++)
		ptr[i] = (int *) malloc(height * sizeof(int));
	return (ptr);
}
