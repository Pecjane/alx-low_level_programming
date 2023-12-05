#include "hash_tables.h"

/**
 * shash_table_create - creates a hash table.
 * @size: size of the array.
 * Return: pointer to the newly created hash table.
 */

shash_table_t *shash_table_create(unsigned long int size)
{
	shash_table_t *table = malloc(sizeof(shash_table_t));

	if (!table)
		return (NULL);

	table->size = size;
	table->array = malloc(sizeof(shash_node_t *) * size);
	table->shead = NULL;
	table->stail = NULL;

	return (table);
}


/**
 * shash_table_set - adds an element to the hash table.
 * @ht: hash table you want to add or update the key/value to.
 * @key: the key and cannot be empty.
 * @value: he value associated with the key. value must be duplicated.
 * value can be an empty string
 * Return: 1 if it succeeded, 0 otherwise
 */

int shash_table_set(shash_table_t *ht, const char *key, const char *value)
{
	unsigned long int index;
	shash_node_t *item;
	shash_node_t *current;
	shash_node_t *temp;


	if (!ht || strcmp(key, "") == 0)
		return (0);

	index = key_index((const unsigned char *)key, ht->size);
	current = ht->array[index];
	item = create_shash_node(key, value);
	temp = NULL;

	if (!item)
	{
		return (0);
	}

	if (!ht->shead || !ht->stail)
	{
		ht->shead = item;
		ht->stail = item;
	}
	else
	{
		temp = ht->shead;
		if (strcmp(item->key, temp->key) <= 0)
		{
			item->snext = temp;
			temp->sprev = item;
			ht->shead = item;
		}
		else if (strcmp(item->key, ht->stail->key) > 0)
		{
			ht->stail->snext = item;
			item->sprev = ht->stail;
			ht->stail = item;
		}
		else
		{
			while (temp->snext)
			{
				temp = temp->snext;
				if (strcmp(item->key, temp->key) <= 0)
				{
					item->sprev = temp->sprev;
					item->snext = temp;
					temp->sprev->snext = item;
					temp->sprev = item;
					break;
				}
			}
		}
	}

	if (!current)
	{
		ht->array[index] = item;
		return (1);
	}

	if (current)
	{
		/*Updating the value if the keys match.*/
		if (strcmp(current->key, key) == 0)
		{
			strcpy(current->value, value);
			return (1);
		}
		item->next = current;
		ht->array[index] = item;
		return (1);
	}
	return (1);
}

/**
 * create_shash_node - creates a new node.
 * @key: the unique key.
 * @value: the value associated with the value.
 * Return: pointer to the node or NULL if unsuccessful.
*/

shash_node_t *create_shash_node(const char *key, const char *value)
{
	shash_node_t *item = malloc(sizeof(shash_node_t));

	if (!item)
		return (NULL);

	item->key = malloc(sizeof(char) * strlen(key) + 1);
	item->value = malloc(sizeof(char) * strlen(value) + 1);

	strcpy(item->key, key);
	strcpy(item->value, value);
	item->next = NULL;
	item->sprev = NULL;
	item->snext = NULL;

	return (item);
}

/**
 * shash_table_get - retrieves a value associated with a key.
 * @ht: pointer to the table.
 * @key: the unique key.
 * Return: the value associated with key.
*/

char *shash_table_get(const shash_table_t *ht, const char *key)
{
	unsigned long int index;
	shash_node_t *current;

	index = key_index((const unsigned char *)key, ht->size);
	current = ht->array[index];

	if (!current)
		return (NULL);

	while (current)
	{
		if (strcmp(current->key, key) == 0)
			return (current->value);
		current = current->next;
	}
	return (NULL);
}

/**
 * shash_table_print - prints the hash table using the sorted linked list.
 * @ht: pointer to the hash table.
 * Return: nothing.
*/

void shash_table_print(const shash_table_t *ht)
{
	int count = 0;
	shash_node_t *ptr = ht->shead;

	printf("{");

	while (ptr)
	{
		count++;
		if (count == 1)
		{
			printf("'%s': '%s'", ptr->key, ptr->value);
		}
		else
		{
			printf(", '%s': '%s'", ptr->key, ptr->value);
		}

		ptr = ptr->snext;
	}
	printf("}\n");
}

/**
 * shash_table_print_rev - prints the hash tables key/value
 * pairs in reverse order using the sorted linked list.
 * @ht: pointer to the hash table.
 * Return: nothing.
*/

void shash_table_print_rev(const shash_table_t *ht)
{
	int count = 0;
	shash_node_t *ptr = ht->stail;

	printf("{");

	while (ptr)
	{
		count++;
		if (count == 1)
		{
			printf("'%s': '%s'", ptr->key, ptr->value);
		}
		else
		{
			printf(", '%s': '%s'", ptr->key, ptr->value);
		}

		ptr = ptr->sprev;
	}
	printf("}\n");
}

/**
 * shash_table_delete - deletes a hash table.
 * @ht: a pointer to the hash table.
 * Return: nothing.
*/

void shash_table_delete(shash_table_t *ht)
{
	unsigned long int i;
	shash_node_t *current;
	shash_node_t *temp;

	if (ht)
	{
		for (i = 0; i < ht->size; i++)
		{
			current = ht->array[i];
			temp = current;
			while (temp)
			{
				temp = current->next;
				free(current->key);
				free(current->value);
				free(current);
				current = temp;
			}
		}
		free(ht->array);
		free(ht);
	}
}
