#include "main.h"
/**
 * _isupper - checks if character is uppercase or lower case
 * @c: integer value to be checked if upper or lower
 * Return: 1, if upper; 0, if lower
 */

int _isupper(int c)
{
	if (c >= 'A' && c <= 'Z')
		return (1);
	else
		return (0);
}
