#include "main.h"
#include <stdio.h>
/**
 * main - entry point of the program
 * @argc: argument count - store number of arguments in main, including main
 * @argv: argument vector - a character pointer to all arguments
 * Return: Always (0)
 */
int main(int argc, char *argv[])
{
	int a = 20;
	int b = 10;
	int i;

	printf("%d + %d = %d\n", a, b, add(a, b));
	printf("argc = %d\n", argc);
	for (i = 0; i < argc; i++)
		puts(argv[i]);
	return (0);
}
