#include "binary_trees.h"

/**
 * get_path - Finds the path to the root of a binary tree's node.
 * @tree_node: The node in the binary tree.
 * @depth: A pointer to the path's depth value.
 *
 * Return: The path to the root of the given node.
 */
binary_tree_t *get_path(void *tree_node, int *depth)
{
	binary_tree_t *path = NULL;
	binary_tree_t *new_node;
	binary_tree_t *path_node = (binary_tree_t *)tree_node;
	int i = 0;

	while (path_node != NULL)
	{
		new_node = malloc(sizeof(binary_tree_t));
		if (new_node == NULL)
			return (NULL);
		new_node->left = NULL;
		new_node->right = path;
		new_node->n = i;
		new_node->parent = path_node;
		if (path != NULL)
		{
			path->left = new_node;
		}
		path = new_node;
		path_node = path_node->parent;
		i++;
	}
	if (depth != NULL)
	{
		(*depth) = i;
	}
	return (path);
}

/**
 * free_path - Frees the path created from a binary tree.
 * @path: The path from a binary tree.
 */
void free_path(binary_tree_t *path)
{
	binary_tree_t *tmp0 = path;
	binary_tree_t *tmp1;

	while ((tmp0 != NULL))
	{
		tmp1 = tmp0->right;
		free(tmp0);
		tmp0 = tmp1;
	}
}

/**
 * binary_trees_ancestor - Finds the lowest common ancestor \
 * of two binary tree nodes.
 * @first: The first node in the binary tree.
 * @second: The second node in the binary tree.
 *
 * Return: The lowest common ancestor of the given nodes, otherwise NULL.
 */
binary_tree_t *binary_trees_ancestor(
	const binary_tree_t *first, const binary_tree_t *second)
{
	binary_tree_t *tmp0;
	binary_tree_t *tmp1;
	binary_tree_t *first_path = NULL;
	binary_tree_t *second_path = NULL;
	binary_tree_t *ancestor = NULL;
	int f_depth = 0, s_depth = 0, min_depth, i;

	if ((first == NULL) || (second == NULL))
		return (ancestor);
	first_path = get_path((void *)first, &f_depth);
	second_path = get_path((void *)second, &s_depth);
	min_depth = f_depth < s_depth ? f_depth : s_depth;
	tmp0 = first_path;
	tmp1 = second_path;
	for (i = 0; i < min_depth; i++)
	{
		if (tmp0->parent == tmp1->parent)
			ancestor = tmp0->parent;
		tmp0 = tmp0->right;
		tmp1 = tmp1->right;
	}
	free_path(first_path);
	free_path(second_path);
	return (ancestor);
}
