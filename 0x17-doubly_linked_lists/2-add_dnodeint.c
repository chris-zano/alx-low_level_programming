#include "lists.h"

/**
 * add_dnodeint - adds a node at the beginning of dlistint_t list.
 * @head: pointer to the head.
 * @n: integer n to add to the node.
 * Return: the address of the new element, or NULL if it failed
 */
dlistint_t *add_dnodeint(dlistint_t **head, const int n)
{
	dlistint_t *temp = *head;
	dlistint_t *new;

	if (temp == NULL)
		return (NULL);
	new = malloc(sizeof(dlistint_t));

	if (new == NULL)
		return (NULL);
	new->n = n;
	if (temp)
	{
		new->next = temp;
		new->prev = temp->prev;
		temp->prev = new;
		temp = new;
		return (temp);
	}
	new->next = temp;
	new->prev = NULL;
	temp = new;
	return (temp);
}
