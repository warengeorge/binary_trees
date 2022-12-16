#include "binary_trees.h"

/**
 * binary_tree_uncle - Finds the uncle of a binary tree's node.
 * @node: The node in the binary tree.
 *
 * Return: The uncle of the given node.
 */
binary_tree_t *binary_tree_uncle(binary_tree_t *node)
{
	binary_tree_t *left = NULL;
	binary_tree_t *right = NULL;
	binary_tree_t *parent = (node != NULL ? node->parent : NULL);

	if ((parent != NULL) && (parent->parent != NULL))
	{
		left = parent->parent->left;
		right = parent->parent->right;
	}
	return (left == parent ? right : left);
}
