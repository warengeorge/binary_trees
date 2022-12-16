#include "binary_trees.h"

/**
 * node_height - Computes the height of a binary tree's node.
 * @tree: The binary tree.
 * @n: The accumulated height.
 * @height: A pointer to the maximum height in the node's tree.
 */
void node_height(const binary_tree_t *tree, size_t n, size_t *height)
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
			node_height(tree->left, n + 1, height);
			node_height(tree->right, n + 1, height);
		}
	}
}

/**
 * binary_tree_height - Computes the height of a binary tree.
 * @tree: The binary tree.
 *
 * Return: The height of the given binary tree.
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t height = 0;

	node_height(tree, 0, &height);
	return (height);
}
