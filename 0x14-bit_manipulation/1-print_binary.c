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

	printf("%lu\n", (n & 1));
}
