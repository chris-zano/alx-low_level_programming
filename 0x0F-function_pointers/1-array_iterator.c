#include "function_pointers.h"
#include <stdlib.h>
#include <stddef.h>

/**
 * array_iterator - a function that executes a function given
 * as a parameter on each element of an array
 * @array: array of integers
 * @size: size of the array
 * @action: function pointer, pointing to func that takes int args
 * Return: void
 */

void array_iterator(int *array, size_t size, void (*action)(int))
{
	size_t i;

	if (array == NULL)
		return;
	if (action == NULL)
		return;

	for (i = 0; i < size; i++)
		action(array[i]);
}
