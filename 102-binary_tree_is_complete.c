#include "binary_trees.h"

/**
 * enqueue_item_1 - Adds an item to a queue.
 * @queue_h: A pointer to the queue's head.
 * @queue_t: A pointer to the queue's tail.
 * @n: A pointer to the queue's size value.
 * @item: The item to add to the queue.
 */
void enqueue_item_1(binary_tree_t **queue_h, binary_tree_t **queue_t,
	int *n, void *item)
{
	binary_tree_t *new_node;
	binary_tree_t *node = (binary_tree_t *)item;

	if ((queue_h != NULL) && (queue_t != NULL))
	{
		new_node = malloc(sizeof(binary_tree_t));
		if (new_node == NULL)
			return;
		new_node->left = *queue_t;
		new_node->right = NULL;
		new_node->n = (node != NULL ? node->n : -1);
		new_node->parent = node;
		if (*queue_h == NULL)
			*queue_h = new_node;
		if (*queue_t != NULL)
			(*queue_t)->right = new_node;
		*queue_t = new_node;
		if (n != NULL)
			(*n)++;
	}
}

/**
 * dequeue_item_1 - Removes an item from a queue.
 * @queue_h: A pointer to the queue's head.
 * @queue_t: A pointer to the queue's tail.
 * @n: A pointer to the queue's size value.
 *
 * Return: The value of the removed queue.
 */
binary_tree_t *dequeue_item_1(binary_tree_t **queue_h,
	binary_tree_t **queue_t, int *n)
{
	binary_tree_t *tmp0;
	binary_tree_t *tmp1;
	binary_tree_t *node = NULL;

	if ((queue_h != NULL) && (queue_t != NULL))
	{
		tmp0 = *queue_h;
		if (tmp0 != NULL)
		{
			node = tmp0->parent;
			if (tmp0->right != NULL)
			{
				tmp1 = tmp0->right;
				tmp1->left = NULL;
				*queue_h = tmp1;
				free(tmp0);
			}
			else
			{
				free(tmp0);
				*queue_h = NULL;
				*queue_t = NULL;
			}
			if (n != NULL)
				(*n)--;
		}
	}
	return (node);
}

/**
 * binary_tree_is_complete - Checks if a binary tree is complete.
 * @tree: The binary tree.
 *
 * Return: 1 if the tree is complete, otherwise 0.
 */
int binary_tree_is_complete(const binary_tree_t *tree)
{
	binary_tree_t *queue_head = NULL;
	binary_tree_t *queue_tail = NULL;
	binary_tree_t *current = NULL;
	int n = 0, stop = 0;
	int is_complete = 0;

	if (tree != NULL)
	{
		is_complete = 1;
		enqueue_item_1(&queue_head, &queue_tail, &n, (void *)tree);
		while (n > 0)
		{
			current = queue_head;
			if (current->parent == NULL)
			{
				stop = 1;
			}
			else
			{
				if (stop == 1)
				{
					is_complete = 0;
					break;
				}
				else if (current->parent != NULL)
				{
					enqueue_item_1(
						&queue_head, &queue_tail, &n, (void *)(current->parent->left)
					);
					enqueue_item_1(
						&queue_head, &queue_tail, &n, (void *)(current->parent->right)
					);
				}
			}
			dequeue_item_1(&queue_head, &queue_tail, &n);
		}
		while (n > 0)
			dequeue_item_1(&queue_head, &queue_tail, &n);
	}
	return (is_complete);
}
