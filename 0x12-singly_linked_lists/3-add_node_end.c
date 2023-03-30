#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "lists.h"

/**
 * add_node_end - adds a new node at the end of a list_t list.
 * @head: head node
 * @str: value to be added
 * Return: address of new node || null if failed
 */
list_t *add_node_end(list_t **head, const char *str)
{
	unsigned int len;
	list_t *new, *temp;

	len = strlen(str);
	new = (list_t *) malloc(sizeof(list_t *));

	if (new == NULL)
		return (NULL);

	new->str = strdup(str);
	new->len = len;
	new->next = NULL;
	temp = *head;

	if (temp == NULL)
	{
		*head = new;
	}
	else
	{
		while (temp->next != NULL)
			temp = temp->next;
		temp->next = new;
	}

	return (*head);
}
