#include "binary_trees.h"

/**
 * heapify_down - Restores the Max Heap property by sifting a node down.
 * @node: Pointer to the current node.
 */
void heapify_down(heap_t *node)
{
	heap_t *largest = node;
	int temp;

	while (1)
	{
		if (node->left && node->left->n > largest->n)
			largest = node->left;
		if (node->right && node->right->n > largest->n)
			largest = node->right;

		if (largest == node)
			break;

		temp = node->n;
		node->n = largest->n;
		largest->n = temp;

		node = largest;
	}
}

/**
 * get_last_node - Finds the last node in level-order traversal.
 * @root: Pointer to the root of the heap.
 * Return: Pointer to the last node.
 */
heap_t *get_last_node(heap_t *root)
{
	heap_t **queue;
	heap_t *last;
	size_t front = 0, rear = 0;

	queue = malloc(1024 * sizeof(heap_t *));
	if (!queue)
		return (NULL);

	queue[rear++] = root;
	while (front < rear)
	{
		last = queue[front++];
		if (last->left)
			queue[rear++] = last->left;
		if (last->right)
			queue[rear++] = last->right;
	}

	free(queue);
	return (last);
}

/**
 * heap_extract - Extracts the root node of a Max Binary Heap.
 * @root: Double pointer to the root node of the heap.
 * Return: Value stored in the root node, or 0 on failure.
 */
int heap_extract(heap_t **root)
{
	heap_t *last, *parent;
	int value;

	if (!root || !*root)
		return (0);

	value = (*root)->n;

	last = get_last_node(*root);
	if (last == *root)
	{
		free(*root);
		*root = NULL;
		return (value);
	}

	/* Replace root with the last node */
	(*root)->n = last->n;

	parent = last->parent;
	if (parent->left == last)
		parent->left = NULL;
	else
		parent->right = NULL;

	free(last);

	/* Restore the Max Heap property */
	heapify_down(*root);

	return (value);
}
