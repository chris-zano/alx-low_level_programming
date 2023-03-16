#include "main.h"
#include <stdlib.h>
#include <stdio.h>
/**
 * malloc_checked -  a function that allocates memory using malloc
 * @b: size
 * Return: pointer to the allocated memory
 * if malloc fails, the malloc_checked function
 * should cause normal process termination with a status value of 98
 */
void *malloc_checked(unsigned int b)
{
	unsigned int *ptr;

	ptr = malloc(b);
	if (ptr == NULL)
		exit(98);
	return (ptr);
}
