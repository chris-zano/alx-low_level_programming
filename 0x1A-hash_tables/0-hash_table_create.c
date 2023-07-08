#include "hash_tables.h"

/**
 * hash_table_create - creates a hash table
 * @size: size of the table
 * Return: a ointer to the newly created table else, NULL
 */
hash_table_t *hash_table_create(unsigned long int size)
{
	hash_table_t *table = NULL;
	hash_node_t **arr = NULL;
	unsigned long int i = 0;


	table =  malloc(sizeof(hash_table_t));
	if (!table)
		return (NULL);

	arr = malloc(sizeof(hash_node_t *) * size);
	if (!arr)
		return (NULL);

	for (; i < size; ++i)
		arr[i] = NULL;

	table->size = size;
	table->array = arr;

	return (table);
}
