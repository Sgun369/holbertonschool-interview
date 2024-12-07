#include "search.h"
/**
 * linear_skip - searches for a value in a sorted skip list of integers.
 * @list:a pointer to the head of the skip list to search in
 * @value:the value to search for
 * Return:a pointer on the first node where value is located
 */
skiplist_t *linear_skip(skiplist_t *list, int value)
{
	skiplist_t *temp = list, *prev = NULL;

	if (!list)
		return (NULL);
	while (temp->express)
	{
		printf("Value checked at index [%lu] = [%d]\n", temp->index, temp->n);
		if (temp->n >= value)
			break;
		prev = temp;
		temp = temp->express;
	}
	if (!temp->express && temp->n < value)
	{
		prev = temp;
		while (temp->next)
			temp = temp->next;
	}
	printf("Value found between indexes [%lu] and [%lu]\n",
	prev ? prev->index : temp->index, temp->index);
	while (prev && prev->index <= temp->index)
	{
		printf("Value checked at index [%lu] = [%d]\n", prev->index, prev->n);
		if (prev->n == value)
			return (prev);
		prev = prev->next;
	}
	return (NULL);
}