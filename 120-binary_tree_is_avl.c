#include "binary_trees.h"

/**
 * bst_checker - Checks if a binary tree is a binary search tree.
 * @tree: The binary tree.
 * @min: The minimum value of the tree.
 * @max: The mazimum value of the tree.
 * @is_bst: A pointer to the tree's validation flag.
 */
void bst_checker(const binary_tree_t *tree, int min, int max, int *is_bst)
{
	if (tree != NULL)
	{
		if ((tree->n > min) && (tree->n < max))
		{
			bst_checker(tree->left, min, tree->n, is_bst);
			bst_checker(tree->right, tree->n, max, is_bst);
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
 * tree_height_1 - Computes the height of a binary tree.
 * @tree: The binary tree.
 * @n: The accumulated height of the current tree.
 * @height: A pointer to the tree's maximum height value.
 */
void tree_height_1(const binary_tree_t *tree, int n, int *height)
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
			tree_height_1(tree->left, n + 1, height);
			tree_height_1(tree->right, n + 1, height);
		}
	}
}

/**
 * avl_tree_balance - Recursively checks the balance of a binary tree and \
 * its nodes and sets the balanced flag to 0 if it isn't all balanced.
 * @tree: The binary tree.
 * @is_balanced: A pointer to the balanced flag's value.
 */
void avl_tree_balance(const binary_tree_t *tree, int *is_balanced)
{
	int balance_factor = 0;
	int left_height = 0;
	int right_height = 0;

	if (tree != NULL)
	{
		tree_height_1(tree->left, 1, &left_height);
		tree_height_1(tree->right, 1, &right_height);
		balance_factor = left_height - right_height;
		if (!((balance_factor >= -1) && (balance_factor <= 1)))
		{
			if (is_balanced != NULL)
			{
				*is_balanced = 0;
			}
		}
		else
		{
			avl_tree_balance(tree->left, is_balanced);
			avl_tree_balance(tree->right, is_balanced);
		}
	}
}

/**
 * binary_tree_is_avl - Checks if the given tree is an AVL tree.
 * @tree: The tree to check.
 *
 * Return: 1 if the tree is an AVL tree, otherwise 0.
 */
int binary_tree_is_avl(const binary_tree_t *tree)
{
	int is_bst = 0;
	int is_avl = 0;

	if (tree != NULL)
	{
		is_bst = 1;
		bst_checker(tree, INT_MIN, INT_MAX, &is_bst);
		if (is_bst == 1)
		{
			is_avl = 1;
			avl_tree_balance(tree, &is_avl);
		}
	}
	return (is_avl);
}
