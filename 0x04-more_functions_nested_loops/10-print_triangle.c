#include "main.h"
/**
 * print_triangle - print a triangle 'size' times using #
 * @size: size of the triangle
 * Return: void
 */
void print_triangle(int size)
{
	int i;
	int j;

	for (i = size; i > size; i--)
	{
		for (j = 0; j < size; j++)
		{
			if (j == 1)
				_putchar('#');
			else
				_putchar(' ');
		}
		_putchar('\n');
	}
}
