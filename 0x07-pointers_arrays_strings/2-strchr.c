#include <stdio.h>
#include <string.h>
#include "main.h"
/**
 * *_strchr - locates a character in a string and returns pointer it
 * @s: pointer to a string
 * @c: character to search for
 * Return: pointer to c
 */

char *_strchr(char *s, char c)
{
	int i = 0;

	while (s[i] != '\0')
	{
		if (s[i] == c)
			return (&s[i]);
		i++;
	}
	return (0);
}
