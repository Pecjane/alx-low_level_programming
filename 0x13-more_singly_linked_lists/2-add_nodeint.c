#include "lists.h"
/**
 * add_nodeint - new node is added  at the beginning of a linked list
 * @head: it stores address in first node in the list
 * @n: inserting new data node
 *
 * Return: pointer to the new node, or NULL if it fails
 */
listint_t *add_nodeint(listint_t **head, const int n)
{
	listint_t *new;

	new = malloc(sizeof(listint_t));
	if (!new)
		return (NULL);
	new->n = n;
	new->next = *head;
	*head = new;
	return (new);
}
