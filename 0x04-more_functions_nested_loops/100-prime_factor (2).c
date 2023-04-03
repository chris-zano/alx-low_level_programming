#include <stdio.h>
#include <limits.h>
/**
 * main - return largest prime among factors
 * Return: Always 0
 */

int main(void)
{
	long int number = 612852475143;
	long int large_factor = 0;
	long int i = 2;

	while (number != 1)
	{
		if (number % i == 0)
		{
			while (number % i == 0)
			{
				number /= i;
			}
			large_factor = i;
		}
		i++;
	}
	printf("%ld\n", large_factor);
	return (0);
}
