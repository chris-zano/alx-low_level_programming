#include <stdio.h>

void __attribute__((constructor)) foo(void);

/**
 * foo - prints strin before main
 * Return: void
 */

void foo(void)
{
	printf("You're beat! and yet, you must allow,\n"
			"I bore my house upon my back!\n");
}
