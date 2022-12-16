#include <stdlib.h>
#include "binary_trees.h"
/**
* binary_tree_depth -Measures the depth of a node in a binary tree
* @tree:  pointer to the root node of the tree to measure the depth.
* Return: If tree is NULL, function return 0
**/
size_t binary_tree_depth(const binary_tree_t *tree)
{
	size_t depth = 0;

	if (tree == NULL)
		return (0);
	if (tree->parent != NULL)
		depth = 1 + binary_tree_depth(tree->parent);
	return (depth);
}
