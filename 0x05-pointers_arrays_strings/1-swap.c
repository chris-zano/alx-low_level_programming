#include "main.h"

/**
 * swap_int - function that swaps two numbres
 * @a: integer number
 * @b: interger number
 * Return: Void
 */

void swap_int(int *a, int *b)
{
	*a = *a + *b;
	*b = *a - *b;
	*a = *a - *b;
}
