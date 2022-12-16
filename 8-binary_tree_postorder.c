#include "binary_trees.h"

/**
 * binary_tree_postorder - Performs a preorder traversal on a tree.
 * @tree: The tree to traverse.
 * @func: The function to handle the traversed node's value.
 */
void binary_tree_postorder(const binary_tree_t *tree, void (*func)(int))
{
	if ((tree != NULL) && (func != NULL))
	{
		binary_tree_postorder(tree->left, func);
		binary_tree_postorder(tree->right, func);
		func(tree->n);
	}
}
