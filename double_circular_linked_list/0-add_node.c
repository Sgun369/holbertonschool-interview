#include <stdlib.h>
#include <string.h>
#include "list.h"

/**
 * add_node_end - Add a new node to the end of double circular linked list
 * @list: Pointer to the list to modify
 * @str: The string to copy to the new node
 *
 * Return: Address of the new node, or NUll on ffailure
 */
List *add_node_end(List **list, char *str)
{
	List *new_node, *tail;

	if (!list || !str)
		return (NULL);

	new_node = malloc(sizeof(list));
	if (!new_node)
		return (NULL);

	new_node->str = strdup(str);
	if (!new_node->str)
	{
		free(new_node);
		return (NULL);
	}
	if (!*list)
	{
		new_node->next = new_node;
		new_node->prev = new_node;
		*list = new_node;
	}
	else
	{
		tail = (*list)->prev;
		tail->next = new_node;
		new_node->prev = tail;
		new_node->next = *list;
		(*list)->prev = new_node;
	}
	return (new_node);
}
/**
 * add_node_begin - Add a new node to the beginning
 * @list: Pointer to the list to modifiy
 * @str: The string to copy into the new node
 *
 * Return: Address of the new node, or NULL on failurre
 */
List *add_node_begin(List **list, char *str)
{
	List *new_node = add_node_end(list, str);

		if (new_node)
			*list = new_node;
		return (new_node);

}
