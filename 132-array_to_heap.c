#include "binary_trees.h"

/**
 * array_to_heap - Creates a max binary heap tree from an array.
 * @array: T=A pointer to the array of values.
 * @size: The length of the array.
 *
 * Return: A pointer to the max binary heap tree, otherwise NULL.
 */
heap_t *array_to_heap(int *array, size_t size)
{
	size_t i;
	heap_t *root = NULL;

	if (array != NULL)
	{
		for (i = 0; i < size; i++)
		{
			heap_insert(&root, *(array + i));
		}
	}
	return (root);
}
