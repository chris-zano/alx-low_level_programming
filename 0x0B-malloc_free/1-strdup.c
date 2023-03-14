#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * _strdup - returns a pointer to a newly allocated space in memory
 * which contains a copy of the string given as a parameter.
 * @str: string to be copied
 * Return: pointer to malloc
 */

char *_strdup(char *str)
{
	int l;
	int i;
	char *ptr;

	l = strlen(str);
	ptr = (char *) malloc(l * sizeof(char));

	if (str == NULL)
		return (NULL);
	if (ptr == NULL)
		return (NULL);
	for (i = 0; i < l; i++)
		ptr[i] = str[i];
	return (ptr);
}
