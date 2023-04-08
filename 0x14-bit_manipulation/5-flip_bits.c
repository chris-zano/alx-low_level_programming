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

	/* XOR m with x to flip the bits so they match */
	n_xor_m = n ^ m;
	/* find the number of bits in n_xor_m */
	bit_length = (sizeof(n_xor_m) * 8); /* x8 - 8 bits in a byte */
	counter = 0;

	/* at each bit position */
	for (index = 0; index < bit_length; index++)
	{
		/* count number of bits to be flipped using >> and & */
		counter = counter + (n_xor_m & 1);
		/* right sift n_xor_m by 1 bit */
		n_xor_m >>= 1;
	}
	/* return the count */
	return (counter);
}
