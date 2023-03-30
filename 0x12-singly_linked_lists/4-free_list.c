#include "lists.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * free_list - frees a list_t list.
 * @head: head node
 * Return: void
 */
void free_list(list_t *head)
{
	list_t *tmp;

	while (head)
	{
		tmp = head->next;
		free(head->str);
		free(head);
		head = tmp;
	}
}
