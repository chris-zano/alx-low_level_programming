#include <stdio.h>
/** print_alphabets - definition of print_alphabets prototype
 * Return: void
 */

void print_alphabet(void)
{
	char c = 'a';

	while (c <= 'z')
	{
		putchar(c);
		c++;
	}
	putchar('\n');
}
