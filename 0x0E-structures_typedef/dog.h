#ifndef DOG_H
#define DOG_H

/**
 *  struct dog - constructors of a dog
 * @name: name
 * @age: age
 * @owner: owner
 * Description: structure for info about dogs
 */

struct dog
{
	char *name;
	char *owner;
	float age;
};

void init_dog(struct dog *d, char *name, float age, char *owner);
void print_dog(struct dog *d);

#endif