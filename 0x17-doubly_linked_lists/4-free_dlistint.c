#include "lists.h"

/**
 * free_dlistint - frees a doubly linked list.
 *
 * @head: pointer to the head of the list.
 *
 * Return: void.
 */

void free_dlistint(dlistint_t *head)
{
	if (head == NULL)
		return;

	if (head->prev == NULL)
	{
		while (head->next != NULL)
		{
			head = head->next;
			free(head->prev);
		}
		free(head);
	}
}
