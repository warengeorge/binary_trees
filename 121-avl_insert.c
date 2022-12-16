#include "binary_trees.h"

/**
 * bst_insert_helper - Inserts a node into a binary search tree.
 * @tree: A pointer to the binary search tree.
 * @value: The value of the new node.
 *
 * Return: A pointer to the created node, otherwise NULL.
 */
bst_t *bst_insert_helper(bst_t **tree, int value)
{
	bst_t *new_node = NULL, *parent = NULL;

	if (tree != NULL)
	{
		parent = *tree;
		if (*tree == NULL)
		{
			new_node = binary_tree_node(*tree, value);
			*tree = new_node;
		}
		else
		{
			while (parent != NULL)
			{
				if ((parent->n > value) && (parent->left != NULL))
					parent = parent->left;
				else if ((parent->n < value) && (parent->right != NULL))
					parent = parent->right;
				else
					break;
			}
			if (parent->n < value)
			{
				new_node = binary_tree_node(parent, value);
				parent->right = new_node;
			}
			else if (parent->n > value)
			{
				new_node = binary_tree_node(parent, value);
				parent->left = new_node;
			}
		}
	}
	return (new_node);
}

/**
 * tree_height_2 - Computes the height of a binary tree.
 * @tree: The binary tree.
 *
 * Return: The height of the tree.
 */
int tree_height_2(const binary_tree_t *tree)
{
	int left = 0, right = 0;

	if (tree != NULL)
	{
		left = tree_height_2(tree->left);
		right = tree_height_2(tree->right);
	}
	return ((left > right ? left : right) + 1);
}

/**
 * adjust_balance - Adjusts the balance of an AVL tree by \
 * rotating the unbalanced subtree.
 * @root: A pointer to the address of the root of the tree.
 * @node: A pointer to the inserted node.
 */
void adjust_balance(avl_t **root, avl_t *node)
{
	avl_t *cur = node, *new_root = *root;
	int left_height = 0, right_height = 0, balance = 0;

	while (cur != NULL)
	{
		left_height = tree_height_2(cur->left);
		right_height = tree_height_2(cur->right);
		balance = left_height - right_height;
		if (!((balance >= -1) && (balance <= 1)))
		{
			if ((balance == 2) && (node->n < cur->left->n))
			{
				new_root = binary_tree_rotate_right(cur);
			}
			else if ((balance == 2) && (node->n > cur->left->n))
			{
				cur->left = binary_tree_rotate_left(cur->left);
				new_root = binary_tree_rotate_right(cur);
			}
			else if ((balance == -2) && (node->n > cur->right->n))
			{
				new_root = binary_tree_rotate_left(cur);
			}
			else if ((balance == -2) && (node->n < cur->right->n))
			{
				cur->right = binary_tree_rotate_right(cur->right);
				new_root = binary_tree_rotate_left(cur);
			}
			new_root = (cur == *root ? new_root : *root);
			break;
		}
		cur = cur->parent;
	}
	*root = new_root;
}

/**
 * avl_insert - Inserts a value into an AVL tree.
 * @tree: A pointer to the address of the root node.
 * @value: The value of the new node.
 *
 * Return: A pointer to the created node, otherwise NULL.
 */
avl_t *avl_insert(avl_t **tree, int value)
{
	avl_t *new_node = NULL;

	if (tree != NULL)
	{
		new_node = bst_insert_helper(tree, value);
		adjust_balance(tree, new_node);
	}
	return (new_node);
}
