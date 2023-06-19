#include <stdio.h>

int add(int a, int b);
int sub(int a, int b);
int mul(int a, int b);
int div(int a, int b);
int mod(int a, int b);

/**
 * add - adds two integers
 * @a: int a
 * @b: int b
 *
 * Return: the sum of a and b
 */
int add(int a, int b)
{
	return (a + b);
}

/**
 * sub - subtracts two numbers
 * @a: int a
 * @b: int b
 *
 * Return: the dfference of a and b
 */
int sub(int a, int b)
{
	return (a - b);
}

/**
 * mul - multiplies two numbers
 * @a: int a
 * @b: int b
 *
 * Return: product of a and b
 */
int mul(int a, int b)
{
	return (a * b);
}

/**
 * div - divides two numbers
 * @a: int a
 * @b: int b
 *
 * Return: the quotient of a and b
 */
int div(int a, int b)
{
	return (a / b);
}

/**
 * mod - finds the mod on two numbers
 * @a: int a
 * @b: int b
 *
 * Return: the modulo of a and b
 */
int mod(int a, int b)
{
	return (a % b);
}
