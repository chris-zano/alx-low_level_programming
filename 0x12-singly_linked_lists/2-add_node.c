#include "lists.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

/**
 * add_node - adds a new node at the beginning of a list_t list.
 * @head: head of list
 * @str: string to add
 * Return: pointer to new node || null, if failed
 */

list_t *add_node(list_t **head, const char *str)
{
	unsigned int len;
	list_t *new;

	len = strlen(str);
	new = (list_t *) malloc(sizeof(list_t));

	if (new == NULL)
		return (NULL);

	new->str = strdup(str);
	new->len = len;
	new->next = *head;
	*head = new;

	return (new);
}
