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
	int k;

	if (size <= 0)
	{
		_putchar('\n');
	}
	else
	{
		for (i = 1; i <= size ; i++)
		{
			for (j = size; j > 0; j--)
			{
				if (j == i)
				{
					for (k = i; k > 0; k--)
					{
						_putchar('#');
					}
				}	
				else if (j > i)
				{
					_putchar(' ');
				}
			}
			_putchar('\n');
		}
	}
}
