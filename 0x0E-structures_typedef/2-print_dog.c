#include "dog.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * print_dog - function that prints a struct dog
 * @d: pointer to a location for struct dog
 * Return: 0
 */
void print_dog(struct dog *d)
{
	if (d == NULL)
		free(d);
	if (d -> name == NULL)
		printf("Name: (nil)\n");
	if (d -> owner == NULL)
		printf("Owner: (nil)\n");
	printf("Name: %s\nAge: %f\nOwner: %s\n", d -> name, d -> age, d -> owner);
}
