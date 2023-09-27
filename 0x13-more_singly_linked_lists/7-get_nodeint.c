#include "lists.h"
/**
 * get_nodeint_at_index - function to produce any needed node
 * @head: beginning node in the linked list
 * @index: index node to return
 * Return: pointer to node
 */
listint_t *get_nodeint_at_index(listint_t *head, unsigned int index)
{
	unsigned int i = 0;
	listint_t *temp = head;

	while (temp && i < index)
	{
		temp = temp->next;
		i++;
	}
	return (temp ? temp : NULL);
}
