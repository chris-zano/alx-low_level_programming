#include "function_pointers.h"
#include <stdlib.h>

/**
 * print_name - function that prints a name.
 * @name: name to be printed
 * @f: function pointer to char pointer
 * Return: void
 */

void print_name(char *name, void (*f)(char *))
{
	if (name == NULL)
		return;
	if (f == NULL)
		return;
	f(name);
}
