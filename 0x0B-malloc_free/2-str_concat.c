#include "main.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
/**
 * str_concat - a function that concatenates two strings
 * @s1: string one
 * @s2: string two
 * Return: pointer to new string, s1 followed by s2
 * return empty string if NULL is passed
 * return NULL on failure
 */

char *str_concat(char *s1, char *s2)
{
	int i, ls1, ls2, totlen;
	char *ptr;

	ls1 = strlen(s1);
	ls2 = strlen(s2);
	totlen = ls1 + ls2;
	ptr = (char *) malloc(totlen * sizeof(char));

	if (s1 == NULL)
		s1 = "";
	if (s2 == NULL)
		s2 = "";
	if (ptr == NULL)
		return (NULL);

	for (i = 0; i < (ls1); i++)
		ptr[i] = s1[i];
	for (i = 0; i < ls2; i++)
		ptr[(totlen - ls2) + i] = s2[i];
	return (ptr);
}
