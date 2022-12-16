#include "binary_trees.h"

/**
 * bst_search - Finds a node with a given value in a binary search tree.
 * @tree: The binary search tree.
 * @value: The value of the node.
 *
 * Return: A pointer to the found node, otherwise NULL.
 */
bst_t *bst_search(const bst_t *tree, int value)
{
	bst_t *node = NULL;

	if (tree != NULL)
	{
		if (tree->left != NULL)
			node = tree->left->parent;
		if ((node == NULL) && (tree->right != NULL))
			node = tree->right->parent;
		while (node != NULL)
		{
			if (node->n < value)
				node = node->right;
			else if (node->n > value)
				node = node->left;
			else
				break;
		}
	}
	return (node);
}
