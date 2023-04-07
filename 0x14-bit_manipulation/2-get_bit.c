#include "main.h"
#include <stdio.h>
/**
 * get_bit - returns the value of a bit at a given index
 * @n: unsigned decimal number
 * @index: position of binary_of(n) we want to return its value
 * Return: value at index, -1 if an error occured
 */

int get_bit(unsigned long int n, unsigned int index)
{
	int bit;
	unsigned int curr_pos;

	for (curr_pos = 0; curr_pos < 32; curr_pos++)
	{
		bit = (n >> curr_pos) & 1;
		if (curr_pos == index)
		{
			return (bit);
		}
	}
	return (-1);
}
