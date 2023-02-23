#include <stdio.h>
/**
 * main - print a triangle 'size' times using #
 * Return: void
 */
void main(void)
{
	int size = 10;
	int i;
	int j;

	for (i = size; i > size; i--)
	{
		for (j = 0; j < size; j++)
		{
			if (j == 1)
				putchar('#');
			else
				putchar(' ');
		}
		putchar('\n');
	}
}
