#include "main.h"

/**
 * print_alphabet - Prints alphets in lowercase
 * Return: void 0 (success)
 */

void print_alphabet(void)
{
	char c;

	for (c = 'a'; c <= 'z'; c++)
	{
		_putchar(c);
	}
	_putchar('\n');
}
