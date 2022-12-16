#include "binary_trees.h"

/**
 * enqueue_item_3 - Adds an item to a queue.
 * @queue_h: A pointer to the queue's head.
 * @queue_t: A pointer to the queue's tail.
 * @n: A pointer to the queue's size value.
 * @item: The item to add to the queue.
 */
void enqueue_item_3(heap_t **queue_h, heap_t **queue_t,
	int *n, void *item)
{
	heap_t *new_node;
	heap_t *node = (heap_t *)item;

	if ((queue_h != NULL) && (queue_t != NULL))
	{
		new_node = malloc(sizeof(heap_t));
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
 * dequeue_item_3 - Removes an item from a queue.
 * @queue_h: A pointer to the queue's head.
 * @queue_t: A pointer to the queue's tail.
 * @n: A pointer to the queue's size value.
 *
 * Return: The value of the removed queue.
 */
heap_t *dequeue_item_3(heap_t **queue_h,
	heap_t **queue_t, int *n)
{
	heap_t *tmp0;
	heap_t *tmp1;
	heap_t *node = NULL;

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
 * get_insert_position - Gets the next available insertion position \
 * for a node in a max binary heap tree.
 * @root: The root of the max binary heap tree.
 *
 * Return: The insertion position, otherwise NULL.
 */
heap_t *get_insert_position(const heap_t *root)
{
	heap_t *head = NULL, *tail = NULL;
	heap_t *parent_node = NULL, *current = NULL;
	int n = 0;

	if (root != NULL)
	{
		enqueue_item_3(&head, &tail, &n, (void *)root);
		while (n > 0)
		{
			current = head;
			if (current->parent != NULL)
			{
				if (current->parent->left != NULL)
				{
					enqueue_item_3(&head, &tail, &n, (void *)(current->parent->left));
					if (current->parent->right != NULL)
					{
						enqueue_item_3(&head, &tail, &n, (void *)(current->parent->right));
					}
					else
					{
						parent_node = current->parent;
						break;
					}
				}
				else
				{
					parent_node = current->parent;
					break;
				}
			}
			dequeue_item_3(&head, &tail, &n);
		}
		while (n > 0)
			dequeue_item_3(&head, &tail, &n);
	}
	return (parent_node);
}

/**
 * swap_tree_node_with_parent - Swaps a node in a \
 * max binary heap tree with its parent.
 * @node: A pointer to the node's address.
 * @root: A pointer to the root of the tree.
 */
void swap_tree_node_with_parent(heap_t **node, heap_t **root)
{
	heap_t *node_copy, *p, *tmp0, *l, *r;

	if ((node != NULL) && ((*node)->parent != NULL) && (root != NULL))
	{
		p = (*node)->parent, node_copy = *node, tmp0 = (*node)->parent->parent;
		l = (*node)->left, r = (*node)->right;
		if ((*node)->parent->left != *node) /* swap from the right */
		{
			if ((tmp0 != NULL) && (tmp0->left == (*node)->parent))
				tmp0->left = *node;
			if ((tmp0 != NULL) && (tmp0->right == (*node)->parent))
				tmp0->right = *node;
			if ((*node)->parent->left != NULL)
				(*node)->parent->left->parent = node_copy;
			(*node)->parent = tmp0, (*node)->left = p->left, (*node)->right = p;
			p->parent = node_copy, p->left = l, p->right = r;
		}
		else /* swap from the left */
		{
			if ((tmp0 != NULL) && (tmp0->left == p))
				tmp0->left = *node;
			if ((tmp0 != NULL) && (tmp0->right == p))
				tmp0->right = *node;
			if ((*node)->parent->right != NULL)
				(*node)->parent->right->parent = *node;
			(*node)->parent = tmp0, (*node)->right = p->right, (*node)->left = p;
			p->parent = node_copy, p->left = l, p->right = r;
		}
		if (l != NULL)
			l->parent = p;
		if (r != NULL)
			r->parent = p;
		if (tmp0 == NULL)
			*root = node_copy;
	}
}

/**
 * heap_insert - Inserts a value into a max binary heap tree.
 * @root: A pointer to the root of the tree.
 * @value: The value to insert.
 *
 * Return: A pointer to the inserted node.
 */
heap_t *heap_insert(heap_t **root, int value)
{
	heap_t *new_node = NULL, *parent = NULL;

	if (root != NULL)
	{
		parent = get_insert_position(*root);
		new_node = malloc(sizeof(heap_t));
		if (new_node == NULL)
			return (new_node);
		new_node->left = NULL;
		new_node->right = NULL;
		new_node->parent = parent;
		new_node->n = value;
		if (parent == NULL)
		{
			*root = new_node;
		}
		else
		{
			if (parent->left == NULL)
				parent->left = new_node;
			else
				parent->right = new_node;
			while (new_node->parent != NULL)
			{
				if (new_node->n > new_node->parent->n)
					swap_tree_node_with_parent(&new_node, root);
				else
					break;
			}
		}
	}
	return (new_node);
}
