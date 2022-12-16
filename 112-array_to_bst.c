#include "binary_trees.h"

/**
 * array_to_bst - Creates a binary search tree from an array.
 * @array: The array of values.
 * @size: The length of the array.
 *
 * Return: A pointer to the binary search tree, otherwise NULL.
 */
bst_t *array_to_bst(int *array, size_t size)
{
	size_t i;
	bst_t *root = NULL;

	if (array != NULL)
	{
		for (i = 0; i < size; i++)
		{
			bst_insert(&root, *(array + i));
		}
	}
	return (root);
}
