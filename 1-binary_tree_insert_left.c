#include "binary_trees.h"

/**
 * binary_tree_insert_left - Inserts a node to the left of a \
 * given binary tree node.
 * @parent: The parent of the new binary tree node.
 * @value: The value of the new node to be inserted.
 *
 * Return: A ponter to the created node, otherwise NULL.
 */
binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value)
{
	binary_tree_t *new_node = NULL;

	if (parent != NULL)
	{
		new_node = malloc(sizeof(binary_tree_t));
		if (new_node != NULL)
		{
			new_node->left = parent->left;
			new_node->right = NULL;
			new_node->parent = parent;
			new_node->n = value;
			if (parent->left != NULL)
			{
				parent->left->parent = new_node;
			}
			parent->left = new_node;
		}
	}
	return (new_node);
}
