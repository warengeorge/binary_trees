#include "binary_trees.h"

/**
 * binary_tree_rotate_right - Rotates a node to the right.
 * @tree: A pointer to the node to rotate.
 *
 * Return: The new root node.
 */
binary_tree_t *binary_tree_rotate_right(binary_tree_t *tree)
{
	binary_tree_t *root;
	binary_tree_t *new_root;
	binary_tree_t *new_root_rc;

	if (tree == NULL)
		return (NULL);
	root = tree;
	new_root = root->left;
	if (new_root != NULL)
	{
		new_root->parent = root->parent;
		new_root_rc = new_root->right;
		new_root->right = root;
		if (root->parent != NULL)
		{
			if (root->parent->left == root)
				root->parent->left = new_root;
			if (root->parent->right == root)
				root->parent->right = new_root;
		}
		root->left = new_root_rc;
		root->parent = new_root;
		if (new_root_rc != NULL)
		{
			new_root_rc->parent = root;
		}
	}
	return (new_root);
}
