#include <stdlib.h>
#include "binary_trees.h"
/**
 * binary_tree_insert_left -inserts a node as the left-child of another node.
 * @parent: pointer to the parent node of the node to create
 * @value: value to put in the new node
 * Return: pointer to the created node, or NULL on failure or if parent is NULL
 **/
binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value)
{
binary_tree_t *new, *tmp;

	if (parent == NULL)
		return (NULL);

	new = malloc(sizeof(binary_tree_t));
	if (new == NULL)
		return (NULL);

	new->n = value;
	if (parent->left == NULL)
	{
		parent->left = new;
		new->right = NULL;
		new->left = NULL;
		new->parent = parent;
	}
	else
	{
		tmp = parent->left;
		parent->left = new;
		new->left = tmp;
		new->right = NULL;
		new->parent = parent;
		tmp->parent = new;
	}
		return (new);
}
