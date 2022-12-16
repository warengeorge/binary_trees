#include "binary_trees.h"

/**
 * tree_stats - Computes some statistics about a binary tree.
 * @tree: The binary tree.
 * @n: The accumulated height of the current path in the tree.
 * @leaves: A pointer to the tree's leaf count value.
 * @height: A pointer to the tree's maximum height value.
 */
void tree_stats(const binary_tree_t *tree, size_t n,
	size_t *leaves, size_t *height)
{
	if (tree != NULL)
	{
		if ((tree->left == NULL) && (tree->right == NULL))
		{
			if (leaves != NULL)
			{
				(*leaves)++;
			}
			if ((height != NULL) && (n > *height))
			{
				*height = n;
			}
		}
		else
		{
			tree_stats(tree->left, n + 1, leaves, height);
			tree_stats(tree->right, n + 1, leaves, height);
		}
	}
}

/**
 * binary_tree_is_perfect - Checks if a binary tree is perfect.
 * @tree: The binary tree.
 *
 * Return: 1 if the tree is perfect, otherwise 0.
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	size_t leaves_count = 0;
	size_t tree_height = 0;

	tree_stats(tree, 0, &leaves_count, &tree_height);
	return ((int)leaves_count == (1 << tree_height) ? 1 : 0);
}
