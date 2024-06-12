#include <stdio.h>
#include <stdlib.h>
#include "lists.h"

/**
 * reverse_listint - reverse a singly linked list
 * @head: pointer to the head of the list
 * Return: pointer to the first node of the reversed list
 */
listint_t *reverse_listint(listint_t **head)
{
	listint_t *prev = NULL;
	listint_t *current = *head;
	listint_t *next = NULL;

	while (current != NULL)
	{
		next = current->next;
		current->next = prev;
		prev = current;
		current = next;
	}

	*head = prev;
	return (*head);
}

/**
 * is_palindrome - checks if a singly linked list is a palindrome
 * @head: double pointer to head of list
 * Return:  if it is a palindrome,  if it is not
 */
int is_palindrome(listint_t **head)
{
	listint_t *slow = *head, *fast = *head, *second_half, *prev_slow = *head;
	listint_t *mid_node = NULL;
	int result = 1;

	if (*head == NULL || (*head)->next == NULL)
		return (1);

	while (fast != NULL && fast->next != NULL)
	{
		fast = fast->next->next;
		prev_slow = slow;
		slow = slow->next;
	}

	if (fast != NULL)
	{
		mid_node = slow;
		slow = slow->next;
	}
	second_half = slow;
	prev_slow->next = NULL;
	reverse_listint(&second_half);

	result = compare_lists(*head, second_half);

	reverse_listint(&second_half);
	if (mid_node != NULL)
	{
		prev_slow->next = mid_node;
		mid_node->next = second_half;
	}
	else
	{
		prev_slow->next = second_half;
	}
	return (result);
}

/**
 * compare_lists - compares two singly linked lists for equality
 * @head1: pointer to head of the first list
 * @head2: pointer to head of the second list
 * Return: 1 if lists are equal, 0 otherwise
 */
int compare_lists(listint_t *head1, listint_t *head2)
{
	listint_t *temp1 = head1;
	listint_t *temp2 = head2;

	while (temp1 && temp2)
	{
		if (temp1->n == temp2->n)
		{
			temp1 = temp1->next;
			temp2 = temp2->next;
		}
		else
		{
			return (0);
		}
	}
	if (temp1 == NULL && temp2 == NULL)
		return (1);
	return (0);
}
