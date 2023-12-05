#include "hash_tables.h"

/**
 * hash_table_set -  adds an element to the hash table.
 * @ht: hash table you want to add or update the key/value to.
 * @key: the key and cannot be an empty string.
 * @value: the value associated with the key.
 * Return: 1 if it succeeded, 0 otherwise
 */

int hash_table_set(hash_table_t *ht, const char *key, const char *value)
{
	unsigned long int index;
	hash_node_t *item_ptr;
	hash_node_t *new_item;

	if (!ht)
		return (0);

	if (!key || strcmp(key, "") == 0)
		return (0);

	index = key_index((const unsigned char *)key, ht->size);
	new_item = create_item(key, value);

	if (!new_item)
		return (0);

	item_ptr = ht->array[index];

	if (!item_ptr)
	{
		ht->array[index] = new_item;
		return (1);
	}

	if (strcmp(item_ptr->key, key) == 0)
	{
		strcpy(item_ptr->value, value);
		return (1);
	}
	else
	{
		ht->array[index] = new_item;
		new_item->next = item_ptr;
		return (1);
	}

	return (1);
}

/**
 * create_item - creates a hash_node_t item.
 * @key: the key.
 * @value: the value associated with the key.
 * Return: the pointer to the item.
 */

hash_node_t *create_item(const char *key, const char *value)
{
	hash_node_t *item = malloc(sizeof(hash_node_t));

	if (!item)
		return (NULL);

	item->key = malloc(strlen(key) + 1);
	item->value = malloc(strlen(value) + 1);
	strcpy(item->key, key);
	strcpy(item->value, value);
	item->next = NULL;

	return (item);
}
