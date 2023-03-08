#include <stdio.h>
#include <string.h>
/**
 * _sqrt_recursion - checks if n < 0, then calls sqrt_recursion2
 * @n: integer number to find sqrt of
 * @i: null
 * Return: sqrt_recursion(n)
 */
int sqrt_recursion2(int n, int i);

int _sqrt_recursion(int n)
{
	if (n < 0)
		return (-1);
	return (sqrt_recursion2(n, 0));
}
/**
 * sqrt_recursion2 - finds square root of a number
 * @n: integer number
 * @i: number to multiply to get n
 * Return: i - square root of n
 */
int sqrt_recursion2(int n, int i)
{
	if (i * i > n)
		return (-1);
	if (i * i == n)
		return (i);
	return (sqrt_recursion2(n, i + 1));
}
