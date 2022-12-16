#include "binary_trees.h"

/**
 * binary_search_tree_checker - Checks if a binary tree is \
 * a binary search tree.
 * @tree: The binary tree.
 * @min: The minimum value of the tree.
 * @max: The mazimum value of the tree.
 * @is_bst: A pointer to the tree's validation flag.
 */
void binary_search_tree_checker(const binary_tree_t *tree,
	int min, int max, int *is_bst)
{
	if (tree != NULL)
	{
		if ((tree->n > min) && (tree->n < max))
		{
			binary_search_tree_checker(tree->left, min, tree->n, is_bst);
			binary_search_tree_checker(tree->right, tree->n, max, is_bst);
		}
		else
		{
			if (is_bst != NULL)
			{
				*is_bst = 0;
			}
		}
	}
}

/**
 * binary_tree_is_bst - Checks if a binary tree is binary search tree.
 * @tree: The binary tree.
 *
 * Return: The 1 if the binary tree is binary search tee, otherwise 0.
 */
int binary_tree_is_bst(const binary_tree_t *tree)
{
	int is_bst = 0;

	if (tree != NULL)
	{
		is_bst = 1;
		binary_search_tree_checker(tree, INT_MIN, INT_MAX, &is_bst);
	}
	return (is_bst);
}
