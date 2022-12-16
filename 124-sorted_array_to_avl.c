#include "binary_trees.h"

/**
 * tree_builder - Builds an AVL tree from a sorted array.
 * @parent: The AVL tree's parent.
 * @array: The sorted array of integers.
 * @size: The length of the given array.
 *
 * Return: A pointer to the root of thhe AVL tree, otherwise NULL.
 */
avl_t *tree_builder(avl_t *parent, int *array, int size)
{
	int *array_l = NULL, *array_r = NULL;
	int size_l = 0, size_r = 0, len = 0;
	avl_t *p = NULL, *l = NULL, *r = NULL;

	if ((size > 0) && (array != NULL))
	{
		p = malloc(sizeof(avl_t));
		if (p != NULL)
		{
			len = size - 1;
			size_l = (len / 2);
			size_r = len - (len / 2);
			if (size_l > 0)
			{
				array_l = array;
				l = tree_builder(p, array_l, size_l);
			}
			if (size_r > 0)
			{
				array_r = array + size_l + 1;
				r = tree_builder(p, array_r, size_r);
			}
			p->parent = parent;
			p->left = l;
			p->right = r;
			p->n = *(array + (size / 2) - (size % 2 == 0 ? 1 : 0));
		}
	}
	return (p);
}

/**
 * sorted_array_to_avl - Builds an AVL tree from a sorted array.
 * @array: The sorted array of integers.
 * @size: The length of the given array.
 *
 * Return: A pointer to the root of thhe AVL tree, otherwise NULL.
 */
avl_t *sorted_array_to_avl(int *array, size_t size)
{
	avl_t *root = NULL;

	if (array != NULL)
	{
		root = tree_builder(root, array, (int)size);
	}
	return (root);
}
