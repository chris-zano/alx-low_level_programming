#include "main.h"
#include <stdio.h>
/**
 * flip_bits - count of bits to flip to get from n to m
 * @n: base number
 * @m: destination number
 * Return: count of bits flipped
 */
unsigned int flip_bits(unsigned long int n, unsigned long int m)
{
	unsigned long int n_xor_m;
	unsigned long int counter;
	unsigned long int bit_length, index;

	n_xor_m = n ^ m;
	bit_length = (sizeof(n_xor_m) * 8);
	counter = 0;

	for (index = 0; index < bit_length; index ++)
	{
		counter = counter + (n_xor_m & 1);
		n_xor_m >>= 1;
	}

	return (counter);
}
