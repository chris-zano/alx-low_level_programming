#include "main.h"

/**
 * _strlen_recursion - return the length of a string
 * @s: string or pointer to first memory
 * Return: type=int Success = Length of the string else 0
 */
int _strlen_recursion(char *s)
{
	int count = 0;

	if (*s == '\0')
	{
		return (count);
	}
	else
	{
		count = count + 1;
		count = count + _strlen_recursion(s + 1);
	}
	return (count);
}
