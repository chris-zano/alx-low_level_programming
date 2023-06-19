#include <stdio.h>
#include <string.h>
/**
 * *_memset - function to replace values at a pointer by a number of bytes
 * @s: string at which pointer is referencing
 * @b: value to replace with
 * @n: number of bytes to replace
 * Return: Always 0
 */

char *_memset(char *s, char b, unsigned int n)
{
	int i = 0;

	while (n > 0)
	{
		s[i] = b;
		i++;
		n--;
	}
	return (s);
}
