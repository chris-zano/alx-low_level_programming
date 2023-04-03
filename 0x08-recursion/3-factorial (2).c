#include "main.h"

/**
 * factorial - prints the factorial of a number
 * @n: parameter of type int
 * Return: type=int Success= factorial of n else (0)
 */

int factorial(int n)
{
	if (n < 0)
		return (-1);
	else if (n == 0 || n == 1)
		return (1);
	else
		return (n * factorial(n - 1));
}
