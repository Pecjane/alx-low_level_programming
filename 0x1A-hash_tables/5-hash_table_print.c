#include "hash_tables.h"
#include <stdio.h>

/**
 * hash_table_print - prints the key/value in the order that
 * they appear in the array of hash table.
 * @ht: the hash table.
 * Return: nothing.
 */

void hash_table_print(const hash_table_t *ht)
{
	unsigned long int i;
	hash_node_t *item;
	unsigned long int count = 0;
	/*str1 = malloc(sizeof(char) * 1024);*/

	if (ht)
	{
		printf("{");
		for (i = 0; i < ht->size; i++)
		{
			item = ht->array[i];
			if (item)
			{
				if (count == 0)
					printf("'%s': '%s'", item->key, item->value);
				else
					printf(", '%s': '%s'", item->key, item->value);
				count++;

				while (item->next)
				{
					item = item->next;
					printf(", '%s': '%s'", item->key, item->value);
				}
			}
		}
		printf("}\n");
	}
}
