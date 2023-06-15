#include "lists.h"

/**
 * add_dnodeint_end - adds a new node at the end of the list.
 *
 * @head: head pointer, to the first element in the list.
 *
 * @n: integer number for newnode->n
 *
 * Return: the address of the new element, else NULL
 */

dlistint_t *add_dnodeint_end(dlistint_t **head, const int n)
{
	dlistint_t *new;
	dlistint_t *temp = *head;

	new = malloc(sizeof(dlistint_t));

	if (new == NULL)
		return (NULL);

	new->n = n;
	new->next = NULL;

	if (temp == NULL)
	{
		new->prev = NULL;
		temp = new;
		return (new);
	}

	while (temp->next != NULL)
		temp = temp->next;

	temp->next = new;
	new->prev = temp;
	
	return (new);
}
