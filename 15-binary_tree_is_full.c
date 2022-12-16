#include <stdlib.h>
#include "binary_trees.h"
/**
* binary_tree_is_full -function that  checks if a binary tree is full
* @tree:  pointer to the root node of the tree to check
* Return: If tree is NULL, return 0
**/
int binary_tree_is_full(const binary_tree_t *tree)
{
	int child_left = 0;
	int child_right = 0;

	if (tree == NULL)
		return (0);
	if ((tree->left == NULL) && (tree->right == NULL))
		return (1);
	if ((tree->left != NULL) && (tree->right != NULL))
	{
		child_left = binary_tree_is_full(tree->left);
		child_right = binary_tree_is_full(tree->right);
		if ((child_left == 1) && (child_right == 1))
			return (1);
	}
	return (0);
}
