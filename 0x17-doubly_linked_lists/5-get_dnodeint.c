#include "lists.h"

/**
 * get_dnodeint_at_index - returns the nth node of a dlistint_t linked list.
 * @head: head pointer to the list.
 * @index: index of the node, starting from 0.
 * Return: nth node or NULL if it doesn't exist.
 */

dlistint_t *get_dnodeint_at_index(dlistint_t *head, unsigned int index)
{
	dlistint_t *ptr = head;
	unsigned int n = 0;

	if (head == NULL)
		return (NULL);

	while (ptr->next && index != n)
	{
		n++;
		ptr = ptr->next;
	}
	if (index > n)
		return (NULL);

	return (ptr);
}
