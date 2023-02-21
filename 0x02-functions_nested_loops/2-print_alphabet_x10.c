#include "main.h"

/**
 * print_alphabet_x10 - prints the alphabet ten times
 * Return: void 0 (success)
 */

void print_alphabet_x10(void)
{
	int i;

	for (i = 1; i <= 10; i++)
	{
		char c;

		for (c = 'a'; c <= 'z'; c++)
		{
			_putchar(c);
		}
		_putchar('\n');
	}
}
