#include "main.h"
#include "union.h"
#include <stdio.h>
#include <stdlib.h>
/**
 * get_endianness - checks endianness
 * Return: 0 if big endian, else 1
 */
int get_endianness(void)
{
	/* set n at struct endian to 1 */
	endian.n = 1;

	if (endian.c[0] == 1)
		/*if the first bit is 1, then its a LE*/
		return (1);
	return (0);
}
