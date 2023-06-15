#include "lists.h"

/**
 * dlistint_len - returns the number of elements of a dlistint_t list.
 *
 * @h: pointer to head node.
 *
 * Return: The number of elements.
 */

size_t dlistint_len(const dlistint_t *h)
{
	size_t count = 0;

	if (h == NULL)
		return (0);

	while (h != NULL)
	{
		count++;
		h = h->next;
	}
	return (count);
}
