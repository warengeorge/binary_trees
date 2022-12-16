#include "binary_trees.h"

/**
 * find_node - Finds a node with a given value in a binary search tree.
 * @root: The root of the binary search tree.
 * @value: The value of the node.
 *
 * Return: A pointer to the found node, otherwise NULL.
 */
bst_t *find_node(bst_t *root, int value)
{
	bst_t *node = NULL;

	if (root != NULL)
	{
		if (root->left != NULL)
			node = root->left->parent;
		if ((node == NULL) && (root->right != NULL))
			node = root->right->parent;
		while (node != NULL)
		{
			if (node->n < value)
				node = node->right;
			else if (node->n > value)
				node = node->left;
			else
				break;
		}
	}
	return (node);
}

/**
 * replace_with_successor - Replaces a node with its inorder \
 * successor in a binary search tree.
 * @node: A pointer to the node in the binary search tree.
 *
 * Return: A pointer to the node's inorder successor node.
 */
bst_t *replace_with_successor(bst_t **node)
{
	bst_t *new_node;

	new_node = (*node)->right;
	while ((new_node != NULL) && (new_node->left != NULL))
		new_node = new_node->left;
	if ((new_node != NULL) && (new_node == (*node)->right))
	{
		new_node->parent = (*node)->parent;
		new_node->left = (*node)->left;
		if ((*node)->left != NULL)
			(*node)->left->parent = new_node;
		if ((*node)->parent != NULL)
		{
			if ((*node)->parent->left == *node)
				(*node)->parent->left = new_node;
			if ((*node)->parent->right == *node)
				(*node)->parent->right = new_node;
		}
	}
	else if (new_node != NULL)
	{
		new_node->parent->left = new_node->right;
		if (new_node->right != NULL)
			new_node->right->parent = new_node->parent;
		new_node->parent = (*node)->parent;
		new_node->left = (*node)->left;
		new_node->right = (*node)->right;
		(*node)->left->parent = new_node;
		(*node)->right->parent = new_node;
		if ((*node)->parent != NULL)
		{
			if ((*node)->parent->left == *node)
				(*node)->parent->left = new_node;
			if ((*node)->parent->right == *node)
				(*node)->parent->right = new_node;
		}
	}
	return (new_node);
}

/**
 * bst_remove - Removes a node with a given value in a binary search tree.
 * @root: The binary search tree.
 * @value: The value of the node.
 *
 * Return: A pointer to the tree's root node, otherwise NULL.
 */
bst_t *bst_remove(bst_t *root, int value)
{
	bst_t *node = NULL, *new_root = root, *new_node = NULL;

	if (new_root != NULL)
	{
		node = find_node(root, value);
		if ((node != NULL) && (node->n == value))
		{
			if ((node->left == NULL) && (node->right == NULL))
			{
				if (node->parent != NULL)
				{
					if (node->parent->left == node)
						node->parent->left = NULL;
					if (node->parent->right == node)
						node->parent->right = NULL;
				}
			}
			else if ((node->left != NULL) ^ (node->right != NULL))
			{
				new_node = (node->left != NULL ? node->left : node->right);
				if (node->parent != NULL)
				{
					if (node->parent->left == node)
						node->parent->left = new_node;
					else if (node->parent->right == node)
						node->parent->right = new_node;
				}
				new_node->parent = node->parent;
			}
			else
			{
				new_node = replace_with_successor(&node);
			}
			new_root = (node->parent == NULL ? new_node : root);
			free(node);
		}
	}
	return (new_root);
}
