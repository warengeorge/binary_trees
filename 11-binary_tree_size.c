#include "binary_trees.h"

/**
 * node_counter - Computes the number of nodes in a binary tree.
 * @tree: The binary tree.
 * @n: A pointer to the tree's node count value.
 */
void node_counter(const binary_tree_t *tree, size_t *n)
{
	if (tree != NULL)
	{
		if (n != NULL)
			(*n)++;
		node_counter(tree->left, n);
		node_counter(tree->right, n);
	}
}

/**
 * binary_tree_size - Computes the number of nodes in a binary tree.
 * @tree: The binary tree.
 *
 * Return: The number of nodes in the given binary tree.
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
	size_t n = 0;

	node_counter(tree, &n);
	return (n);
}
