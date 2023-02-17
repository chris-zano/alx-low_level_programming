#include <stdio.h>
/**
 * main -Entry point for the program
 * Return: 0 (success)
 */

int main(void)
{
	char c = 'a';

	for (c = 'a'; c <= 'z'; c++)
	{
		if ((c != 'e' && c != 'q') && c <= 'z')
			putchar(c);
	}
	putchar('\n');
	return (0);
}
