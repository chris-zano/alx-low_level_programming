#include "lists.h"

/**
 * sum_dlistint - returns the sum of all the n data in a linked list.
 *
 * @head: pointer to the head of the linked list.
 *
 * Return: the sum of all the values, else 0.
 */

int sum_dlistint(dlistint_t *head)
{
	int sum = 0;

	if (head == NULL)
		return (sum);

	while (head->next != NULL)
	{
		sum += head->n;
		head = head->next;
	}
	sum += head->n;
	return (sum);
}
