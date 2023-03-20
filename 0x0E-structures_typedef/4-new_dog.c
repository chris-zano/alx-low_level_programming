#include "dog.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * new_dog - a function that creates a new dog
 * to store a copy of name and owner
 * @name: name
 * @age: age
 * @owner: owner
 * Return: dog_t
 */
dog_t *new_dog(char *name, float age, char *owner)
{
	dog_t *ptr;

	ptr = malloc(sizeof(dog_t));

	if (ptr == NULL)
		return (NULL);

	ptr->name = name;
	ptr->owner = owner;
	ptr->age = age;

	return (ptr);
}
