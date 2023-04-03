#include "main.h"
/**
 * _puts - prints a string of characters to stdout
 * @str: pointer to string
 * Return: Void
 */

void _puts(char *str)
{
	while (*str != '\0')
	{
		_putchar(*str++);
	}
	_putchar('\n');
}
