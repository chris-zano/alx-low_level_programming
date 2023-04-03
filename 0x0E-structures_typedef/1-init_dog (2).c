#include "dog.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/**
 * init_dog - a function that initialize a variable of type struct dog
 * @d: pointer to address of variable of type struct dog
 * @name: pointer to name of dog
 * @age: age of the dog
 * @owner: owner of dog
 * Return: Always 0
 */
void init_dog(struct dog *d, char *name, float age, char *owner)
{
	if (d == NULL)
		d = malloc(sizeof(struct dog));
	(*d).name = name;
	(*d).age = age;
	(*d).owner = owner;
}
