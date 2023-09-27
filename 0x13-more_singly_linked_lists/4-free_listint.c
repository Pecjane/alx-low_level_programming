#include "lists.h"
/**
 * free_listint - it frees a linked list
 * @head: list to be free
 */
void free_listint(listint_t *head)
{
	listint_t *temp;

	while (head)
	{
		temp = head->next;
		free(head);
		head = temp;
	}
}
