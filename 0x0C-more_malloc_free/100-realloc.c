#include "main.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * _realloc - reallocates a memory block using malloc and free
 * @ptr: pointer to the memory previously allocated
 * @old_size: is the size, in bytes, of the allocated space for ptr
 * @new_size: is the new size, in bytes of the new memory block
 * Return: ptr
 */

void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	void *p1;
	char *ptr2;
	char *a;
	unsigned int i;

	if (new_size == old_size)
	{
		return (ptr);
	}
	if (ptr == NULL)
	{
		p1 = malloc(new_size);
		if (p1 == NULL)
			return (NULL);
		return (ptr);
	}
	if (new_size == 0)
	{
		if (ptr != NULL)
		{
			free(ptr);
			return (NULL);
		}
		else if (ptr == NULL)
		{
			return (NULL);
		}
	}
	ptr2 = ptr;
	p1 = malloc(sizeof(*ptr2) * new_size);
	if (p1 == NULL)
	{
		free(ptr);
		return (NULL);
	}
	a = p1;
	for (i = 0; i < old_size && i < new_size; i++)
		a[i] = *ptr2++;
	free(ptr);
	return (ptr);
}
