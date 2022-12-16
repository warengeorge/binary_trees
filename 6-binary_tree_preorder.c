#include "binary_trees.h"

/**
 * binary_tree_preorder - Performs a preorder traversal on a tree.
 * @tree: The tree to traverse.
 * @func: The function to handle the traversed node's value.
 */
void binary_tree_preorder(const binary_tree_t *tree, void (*func)(int))
{
	if ((tree != NULL) && (func != NULL))
	{
		func(tree->n);
		binary_tree_preorder(tree->left, func);
		binary_tree_preorder(tree->right, func);
	}
}
