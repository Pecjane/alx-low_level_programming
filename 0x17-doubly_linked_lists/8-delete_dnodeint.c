#include "lists.h"

/**
 * delete_dnodeint_at_index - deletes the node at index index
 * of a dlistint_t linked list.
 * @head: pointer to the pointer head of the list.
 * @index: index of the node that should be deleted, starts at 0.
 * Return: 1 if it succeeded, -1 if it failed.
 */

int delete_dnodeint_at_index(dlistint_t **head, unsigned int index)
{
	unsigned int n = 0;
	dlistint_t *ptr = *head;

	if (!head | !*head)
		return (-1);
	if (index == 0)
	{
		if (ptr->next)
			ptr->next->prev = NULL;
		*head = ptr->next;
		free(ptr);
		return (1);
	}

	while (ptr->next && index != n)
	{
		ptr = ptr->next;
		n++;
	}
	if (index > n)
		return (-1);

	ptr->prev->next = ptr->next;
	if (ptr->next)
		ptr->next->prev = ptr->prev;
	free(ptr);

	return (1);
}
