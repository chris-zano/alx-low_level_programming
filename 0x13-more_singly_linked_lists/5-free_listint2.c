#include "lists.h"
#include <stdio.h>
#include <stdlib.h>
/**
 * free_listint - frees a listint_t list
 * @head: head node of the list
 * Return: void
 */

void free_listint2(listint_t **head)
{
	listint_t *temp;

	if (head == NULL)
		return;

	while (*head)
	{
		temp = (*head)->next;
		free(*head);
		*head = temp;
	}
	head = NULL;
}
