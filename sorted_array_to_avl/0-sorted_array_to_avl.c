#include <stdlib.h>
#include "binary_trees.h"

typedef binary_tree_t avl_t;

/**
 * create_node - creates a new AVL tree node
 * @parent: pointer to the parent node
 * @value: Value for the new node
 * 
 * Return: Pointer to the new node, or NULL on failure
 */
avl_t *create_node(avl_t *parent, int value)
{
	avl_t *node = malloc(sizeof(avl_t));
	if (!node)
		return (NULL);
	node->n = value;
	node->parent = parent;
	node->left = NULL;
	node->right = NULL;
	return (node);
}
/**
 * build_avl - Recursively build an AVL tree from a sorted array.
 * @arrray: pointer to the first element of the array.
 * @start: starting index of the current subarray.
 * @end: ending index of the current subarray.
 * @parent: pointer to the parent node.
 * 
 * Return: pointer to the root of the subtree, or NULL on failure
 */
avl_t *build_avl(int *array, int start, int end, avl_t *parent)
{
	if (start > end)
		return (NULL);
	int mid = (start + end) / 2;
	avl_t *root = create_node(parent, array[mid]);
	if (!root)
		return (NULL);
	
	root->left = build_avl(array, start, mid - 1, root);
	root->right = build_avl(array, mid +1, end, root);
	return (root);
}
/**
 * sorted_array_to_avl - Builds an AVL tree from a sorted array.
 * @arrray: pointer to the first element of the array to be connverted.
 * @size: Number of elements in the array.
 * 
 * Return: pointer to the root node of the created AVL tree, or NULL on failure.
 */
avl_t *sorted_array_to_avl(int *array, size_t size)
{
	if (!array || size == 0)
		return (NULL);
	return (build_avl(array, 0, size - 1, NULL));
}
