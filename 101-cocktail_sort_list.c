#include "sort.h"
#include <stdio.h>

/**
 * swap - swaps a node with the next node in the list
 * @list: double pointer to the beginning of the list
 * @node: node to swap
 *
 * Return: void
 */
void swap(listint_t **list, listint_t *node)
{
	node->next->prev = node->prev;
	if (node->prev)
		node->prev->next = node->next;
	else
		*list = node->next;
	node->prev = node->next;
	node->next = node->next->next;
	node->prev->next = node;
	if (node->next)
		node->next->prev = node;
}

/**
 * cocktail_sort_list - sorts a doubly linked list of integers in ascending
 * order using the Cocktail shaker sort algorithm
 * @list: Double pointer to the head of the doubly linked list
 *
 * Return: void
 */
void cocktail_sort_list(listint_t **list)
{
	char swapped = 1;
	listint_t *tmp;

	if (list == NULL || *list == NULL)
		return;
	tmp = *list;
	while (swapped != 0)
	{
		swapped = 0;
		while (tmp->next != NULL)
		{
			if (tmp->next->n < tmp->n)
			{
				swap(list, tmp);
				swapped = 1;
				print_list(*list);
			}
			else
				tmp = tmp->next;
		}
		if (swapped == 0)
			break;
		swapped = 0;
		while (tmp->prev != NULL)
		{
			if (tmp->prev->n > tmp->n)
			{
				swap(list, tmp->prev);
				swapped = 1;
				print_list(*list);
			}
			else
				tmp = tmp->prev;
		}
	}
}
