#include "variadic_functions.h"
#include <stdio.h>
#include <stdarg.h>

/**
 * print_numbers - prints number followed by a separator
 * @separator: character that separates the numbers
 * @n: count of args
 * @...: arg params
 * Return: void
 */
void print_numbers(const char *separator, const unsigned int n, ...)
{
	va_list ap;
	unsigned int i;

	if (n == 0)
		return;
	va_start(ap, n);

	if (separator != NULL)
	{
		for (i = 0; i < n; i++)
		{
			printf("%d", va_arg(ap, int));
			if (i != (n - 1))
				printf("%s", separator);
		}
	}
	for (i = 0; i < n; i++)
	{
		printf("%d", va_arg(ap, int));
		if (i != (n-1) && separator != NULL)
			printf("%s", separator);
	}
	va_end(ap);
	printf("\n");
}
