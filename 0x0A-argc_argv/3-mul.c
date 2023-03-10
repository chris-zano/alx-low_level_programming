#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
/**
 * main - a program that multiples two arguments
 * @argc: argument counter - returns number of args in cl
 * @argv: argument vector - returns pointer to array of strings
 * Return: Always (0)
 */

int main(int argc, char *argv[])
{
	int result;

	if (argc < 3 || argc > 3)
	{
		int a = atoi(argv[1]);
		int b = atoi(argv[2]);

		result = a * b;
		printf("%d\n", result);
	}
	else
	{
		printf("Error\n");
		return (1);
	}
	return (0);
}
