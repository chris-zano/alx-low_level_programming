#include "function_pointers.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * int_index -  a function that searches for an integer.
 * @array: array of integers
 * @size: size of array
 * @cmp: pointer to a function that compares
 * Return: Index of res of cmp(array[i])
 * if array or cmp == NULL return NULL
 * if size <=0 return -1
 * if no element is found, return -1
 */

int int_index(int *array, int size, int (*cmp)(int))
{
	int i, retval;

	if (array == NULL)
		return (-1);
	if (cmp == NULL)
		return (-1);
	if (size <= 0)
		return (-1);

	for (i = 0; i < size; i++)
	{
		if (cmp(array[i]))
		{
			retval = i;
			return (retval);
		}
	}
	return (-1);
}
