#include "main.h"
#include <stdio.h>
/**
 * main - a program that prints its name followed by a newline
 * @argc: argument counter - returns number of args in cl
 * @argv: argument vector - returns pointer to array of strings
 * Return: Always (0)
 */

int main(int argc, char *argv[])
{
	int i;

	for (i = 0; i < argc; i++)
		puts(argv[i]);
	return (0);
}
