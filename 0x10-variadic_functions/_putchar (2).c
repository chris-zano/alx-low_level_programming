#include <unistd.h>
#include "variadic_functions.h"

/**
 * _putchar - prints a character to standard output
 * @c: character to print
 * Return: @c
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}
