#include "binary_trees.h"

/**
 * parent_counter - Computes the number of non-leaf nodes in a node.
 * @tree: The binary tree.
 * @n: A pointer to the tree's non-leaf node value.
 */
void parent_counter(const binary_tree_t *tree, size_t *n)
{
	if (tree != NULL)
	{
		if ((tree->left != NULL) || (tree->right != NULL))
		{
			if (n != NULL)
			{
				(*n)++;
				parent_counter(tree->left, n);
				parent_counter(tree->right, n);
			}
		}
	}
}

/**
 * binary_tree_nodes - Computes the number of non-leaf nodes \
 * in a binary tree.
 * @tree: The binary tree.
 *
 * Return: The number of non-leaf nodes in the given binary tree.
 */
size_t binary_tree_nodes(const binary_tree_t *tree)
{
	size_t n = 0;

	parent_counter(tree, &n);
	return (n);
}
