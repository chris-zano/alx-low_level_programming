#include "main.h"
#include <stdio.h>
#include <stdlib.h>
/**
 * print_binary - convert decimal to binary and print it
 * @n: decimal number
 * Return: void
 */
void print_binary(unsigned long int n)
{
	printf("%lu\n", n);

	if (n > 1)
		print_binary(n >> 1);

	printf("%lu + %d => %lu\n", (n & 1), '0', ((n & 1) + '0'));
	_putchar((n & 1) + '0');
}
