#include <stdio.h>
#include <stdlib.h>
#include "sort.h"
/**
 * insertion_sort_list - C function to insert node via sort
 * @list: Double pointer to list of struct listint_t type
 * Return: Return sorted list
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *swap_node = NULL, *next_swap = NULL;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;
	swap_node = *list;
	while (swap_node != NULL)
	{
		next_swap = swap_node;
		while (next_swap->prev != NULL && next_swap->n < next_swap->prev->n)
		{
			next_swap->prev->next = next_swap->next;
			if (next_swap->next != NULL)
				next_swap->next->prev = next_swap->prev;
			next_swap->next = next_swap->prev;
			next_swap->prev = next_swap->prev->prev;
			next_swap->next->prev = next_swap;
			if (next_swap->prev == NULL)
				*list = next_swap;
			else
				next_swap->prev->next = next_swap;
			print_list(*list);
		}
		swap_node = swap_node->next;
	}
}
