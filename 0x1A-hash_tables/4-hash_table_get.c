#include "hash_tables.h"

/**
 * hash_table_get - retrieves a value associated with a key.
 * @ht: the hash table you want to look into.
 * @key: key you are looking for.
 * Return: value associated with the element,
 * or NULL if key couldn’t be found.
 */

char *hash_table_get(const hash_table_t *ht, const char *key)
{
	unsigned long int index;
	hash_node_t *item;

	if (!ht)
		return (NULL);

	index = key_index((const unsigned char *)key, ht->size);
	item = ht->array[index];

	if (item == NULL)
		return (NULL);

	if (strcmp(item->key, key) == 0)
		return (item->value);

	while (item->next)
	{
		item = item->next;
		if (strcmp(item->key, key) == 0)
			return (item->value);
	}
	return (NULL);
}
