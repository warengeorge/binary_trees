#include "binary_trees.h"

/**
 * tree_height - Computes the height of a binary tree.
 * @tree: The binary tree.
 * @n: The accumulated height of the current tree.
 * @height: A pointer to the tree's maximum height value.
 */
void tree_height(const binary_tree_t *tree, int n, int *height)
{
	if (tree != NULL)
	{
		if ((tree->left == NULL) && (tree->right == NULL))
		{
			if (n > *height)
			{
				*height = n;
			}
		}
		else
		{
			tree_height(tree->left, n + 1, height);
			tree_height(tree->right, n + 1, height);
		}
	}
}

/**
 * binary_tree_balance - Computes the balance factor of a binary tree.
 * @tree: The binary tree.
 *
 * Return: The balance factor of the given binary tree.
 */
int binary_tree_balance(const binary_tree_t *tree)
{
	int balance_factor = 0;
	int left_height = 0;
	int right_height = 0;

	if (tree != NULL)
	{
		tree_height(tree->left, 1, &left_height);
		tree_height(tree->right, 1, &right_height);
	}
	balance_factor = left_height - right_height;
	return (balance_factor);
}
