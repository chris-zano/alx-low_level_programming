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
	int num_of_bits = 0;
	unsigned long int copy_n = n;

	if (copy_n == 0)
	{
		_putchar((copy_n & 1) + '0');
	}
	/* finding the number of bits in 'n' */

	while (copy_n > 0)
	{
		/* increment by 1 */
		num_of_bits++;
		/* right shift by 1 */
		copy_n >>= 1;
	}

	/* Print binary representation of n */

	while (num_of_bits-- > 0)
	{
		_putchar('0' + ((n >> num_of_bits) & 1));
	}
}
