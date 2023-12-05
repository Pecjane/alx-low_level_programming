#include "hash_tables.h"

/**
 * hash_table_delete - deletes a hash table.
 * @ht: the hash table
 * Return: Nothing
 */

void hash_table_delete(hash_table_t *ht)
{
	unsigned long int i;
	hash_node_t *item;
	hash_node_t *temp;

	if (ht)
	{
		for (i = 0; i < ht->size; i++)
		{
			item = ht->array[i];
			if (item)
			{
				temp = item;
				while (temp)
				{
					temp = item->next;
					free(item->key);
					free(item->value);
					free(item);
					item = temp;
				}

			}
		}
		free(ht->array);
		free(ht);
	}
}
