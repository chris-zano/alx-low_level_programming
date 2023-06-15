#include "lists.h"

/**
 * get_dnodeint_at_index - returns the nth node of a dlistint_t linked list.
 *
 * @head: pointer to the head of the list.
 *
 * @index: the index of the node, starting from 0.
 *
 * Return: the node if it exists, else NULL.
 */

dlistint_t *get_dnodeint_at_index(dlistint_t *head, unsigned int index)
{
	unsigned int count = 0;

	if (index == 0)
	{
		if (head == NULL)
			return (NULL);
		return (head);
	}

	while (head->next != NULL)
	{
		head = head->next;
		count++;
		if (count == index)
			return (head);
	}

	return (NULL);
}
