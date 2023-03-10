#include <stdio.h>
/**
 * main - returns number of arguments passed
 * @argc: argument count
 * @argv: argument vector
 * Return: Always (0) success
 */

int main(int argc, char *argv[])
{
	if (*argv[argc - 1] != '\0')
		printf("%d\n", argc - 1);
	return (0);
}
