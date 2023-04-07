#include "main.h"
#include <stdio.h>
/**
 * clear_bit - sets the value of a bit to 0 at a given index.
 * @n: address of unsigned decimal number
 * @index: position of binary_of(n) we want to change its value
 * Return: value at index, -1 if an error occured
 */

int clear_bit(unsigned long int *n, unsigned int index)
{
	int bit;
	unsigned int curr_pos;

	/* finding the index whose bit we want to flip */

	for (curr_pos = 0; curr_pos < 32; curr_pos++)
	{

		/**
		 * at each index - the bit at the current positiion in the
		 *		number is asigned to the bit variable
		 */

		bit = ((*n) >> curr_pos) & 1;
		if (curr_pos == index)
		{
			/**
			 * if current position matches index
			 * sets the value of the bit at curr_pos to 0
			 */

			*n &= ~ (1UL << curr_pos);

			/* return 1 */
			return (bit | 1);
		}
	}
	return (-1);
}
