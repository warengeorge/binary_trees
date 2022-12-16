#include "binary_trees.h"

/**
 * is_tree_full - Checks if a binary tree is full.
 * @tree: The binary tree.
 * @is_full: A pointer to the tree's full flag.
 */
void is_tree_full(const binary_tree_t *tree, int *is_full)
{
	if (tree != NULL)
	{
		if ((tree->left != NULL) ^ (tree->right != NULL))
		{
			if (is_full != NULL)
			{
				*is_full = 0;
			}
		}
		else
		{
			is_tree_full(tree->left, is_full);
			is_tree_full(tree->right, is_full);
		}
	}
}

/**
 * binary_tree_is_full - Checks if a binary tree is full.
 * @tree: The binary tree.
 *
 * Return: 1 if the tree is full, otherwise 0.
 */
int binary_tree_is_full(const binary_tree_t *tree)
{
	int is_full = (tree != NULL ? 1 : 0);

	is_tree_full(tree, &is_full);
	return (is_full);
}
