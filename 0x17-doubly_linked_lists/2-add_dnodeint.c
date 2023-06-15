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
	new->prev = NULL;
	new->next = NULL;

	while(head != NULL)
	{
		printf("%d\n", temp->n);
		head = *head->prev;
	}
	new->next = *head;
	temp = new;
	while (temp != NULL)
	{
		printf("%d\n", temp->n);
		temp = temp->next;
	}
	return (new);
}
