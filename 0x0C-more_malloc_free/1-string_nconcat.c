#include "main.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
/**
 * find_s2 - finds the n bytes of s2
 * @s2: ptr to s2
 * @n: number of bytes of s2
 * @i: iterator
 * Return: pointer to s2
 */

char *find_s2(char *s2, unsigned int i, unsigned int n)
{
	unsigned int l2;
	char *str2;

	l2 = strlen(s2);
	if (n >= l2)
	{
		printf("n (%d) is greater or equal to length of s2 (%d)\n", n, l2);
		return (s2);
	}
	else
	{
		str2 = malloc(sizeof(*str2) * n);
		if (str2 == NULL)
			return (NULL);
		for (i = 0; i < n; i++)
			str2[i] = s2[i];
	}
	return (str2);
}

/**
 * string_nconcat - a function that concatenates two strings
 * @s1: pointer to first string
 * @s2: pointer to second string
 * @n: bytes of s2 to return
 * Return: ptr on success
 * if function fails return NULL
 * if n >= strlen(s2) use s2
 * if s1 || s2 == NULL pass ""
 */

char *string_nconcat(char *s1, char *s2, unsigned int n)
{
	int len, len1, len2, i, j;
	char *conStr;

	i = 0;
	s2 = find_s2(s2, i, n);
	if (s1 == NULL)
		s1 = "";
	if (s2 == NULL)
		s2 = "";
	for (len1 = 0; s1[len1] != '\0'; len1++)
		;
	for (len2 = 0; s2[len2] != '\0'; len2++)
		;
	len = len1 + len2;
	conStr = malloc(sizeof(char) * (len + 1));

	if (conStr == NULL)
	{
		free(conStr);
		return (NULL);
	}
	for (i = 0; i < len1; i++)
		conStr[i] = s1[i];
	j = len2;
	for (len2 = 0; len2 <= j; i++, len2++)
		conStr[i] = s2[len2];
	return (conStr);
}
