#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stddef.h>

/**
 * binary_to_uint - converts a binary number to an unsigned integer
 * @b: pointer to a strings of characters of 0's and 1's
 * Return: the converted number
 *	if there is one or more non 0 or 1 - return 0
 *	if b is NULL, return 0
 */
unsigned int binary_to_uint(const char *b)
{
	unsigned int length = strlen(b);
	unsigned int i = 0;
	unsigned int sum = 0;

	/* return 0 is the array is empty */
	if (b[i] == '\0')
		return (0);

	/* check for null input */
	if (b == NULL)
		return (0);
	/* loop through the array */
	for (i = 0; i < length; i++)
	{
		/* if the value is a 0 or 1*/
		if (b[i] == '0' || b[i] == '1')
		{
			/* shift sum 1 place to the left */
			sum <<= 1;
			/**
			 * b[i] is a char
			 * subtracting '0' from it will return
			 * its value from pos relative to 0
			 * add this to sum
			 */
			sum += b[i] - '0';
		}
		else
			return (0);
	}
	return (sum);
}
