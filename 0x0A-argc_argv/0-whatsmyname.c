#include "main.h"
/**
 * main - a program that prints its name followed by a newline
 * @argc: argument counter - returns number of args in cl
 * @argv: argument vector - returns pointer to array of strings
 * Return: Always (0)
 */

int main(int argc, char *argv[])
{
	int i;

	while (i < argc)
	{
		_puts(argv[i]);
		i++;
	}
	return (0);
}
