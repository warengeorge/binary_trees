#include <stdlib.h>
#include "binary_trees.h"
/**
* binary_tree_height -function that measures the height of a binary tree
* @tree:  pointer to the root node of the tree to measure the height.
* Return: If tree is NULL, your function must return 0
**/
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t left_size = 0, right_size = 0;

	if (tree == NULL)
		return (0);
	if (tree->left != NULL)
		left_size = 1 + binary_tree_height(tree->left);
	if (tree->right != NULL)
		right_size = 1 + binary_tree_height(tree->right);
	if (left_size > right_size)
		return (left_size);
	return (right_size);
}
/**
* binary_tree_balance - measures the balance factor of a binary tree
* @tree:  pointer to the root node of the tree to measure the balance factor.
* Return: If tree is NULL, function return 0
**/
int binary_tree_balance(const binary_tree_t *tree)
{
	int height_left = 0, height_right = 0, balance_factor = 0;

	if (tree == NULL)
		return (0);
	if (tree->left == NULL)
		height_left = -1;
	else
	{
	height_left = binary_tree_height(tree->left);
	}
	if (tree->right == NULL)
		height_right = -1;
	else
	{
	height_right = binary_tree_height(tree->right);
	}
	balance_factor = height_left - height_right;
	return (balance_factor);
}
