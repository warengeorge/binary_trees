#include <stdlib.h>
#include "binary_trees.h"
/**
* binary_tree_size -measures the size of a binary tree
* @tree:  pointer to the root node of the tree to measure the size.
* Return: If tree is NULL, function return 0
**/
size_t binary_tree_size(const binary_tree_t *tree)
{
	size_t bt_size = 0;

	if (tree == NULL)
		return (0);
	if (tree->left != NULL)
		bt_size = bt_size + binary_tree_size(tree->left);
	if (tree->right != NULL)
		bt_size = bt_size + binary_tree_size(tree->right);
	bt_size = bt_size + 1;
	return (bt_size);
}


/**
 * binary_tree_is_perfect - function that checks if a tree is perfect
 * @tree: pointer to the root
 * Return: 1 if true or 0 if false
 */

int binary_tree_is_perfect(const binary_tree_t *tree)
{
	int left_size, right_size;

	if (tree == NULL)
		return (0);
	left_size = binary_tree_size(tree->left);
	right_size = binary_tree_size(tree->right);
	if (left_size == right_size)
		return (1);
	return (0);
}
