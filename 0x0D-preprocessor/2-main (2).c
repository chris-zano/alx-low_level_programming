#include <stdio.h>
/**
 * main - a program that prints the name of the file it was compiled from
 * Return: ALways 0 (success)
 */

int main(void)
{
	printf("%s\n", __FILE__);
	return (0);
}
