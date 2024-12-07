#include "search.h"

/**
 * linear_skip - search for value in skip list of integers
 * @list: pointer
 * @value: int
 * Return: pointer or NULL
 */
skiplist_t *linear_skip(skiplist_t *list, int value)
{
	skiplist_t *current, *node, *temp;

	if (list == 0)
		return (NULL);
	current = list;
	while (current)
	{
		if (current->express == NULL)
		{
			node = current->express;
			for (temp = list; temp; temp = temp->next)
				if (temp->next == NULL)
				{
					printf("Value found between indexes [%lu] and [%lu]\n",
						current->index, temp->index);
					break;
				}
			break;
		}
		if (current->express->n >= value)
		{
			node = current->express;
			printf("Value checked at index [%lu] = [%d]\n", node->index, node->n);
			printf("Value found between indexes [%lu] and [%lu]\n",
				current->index, node->index);
			break;
		}
		current = current->express;
		printf("Value checked at index [%lu] = [%d]\n", current->index, current->n);
	}

	while (current)
	{
		printf("Value checked at index [%lu] = [%d]\n", current->index, current->n);
		if (current->n == value)
			return (current);
		current = current->next;
	}
	return (NULL);
}