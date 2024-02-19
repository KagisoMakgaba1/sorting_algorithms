#include "sort.h"

void cocktail_sort_list(listint_t **list);
void swap_nodes(listint_t **list, listint_t *node);

/**
 * swap_nodes - Swaps two nodes in a doubly linked list.
 * @list: Double pointer to the head of the doubly linked list.
 * @node: Node to be swapped.
 */

void swap_nodes(listint_t **list, listint_t *node)
{
	if (node->prev)
		node->prev->next = node->next;
	else
		*list = node->next;

	if (node->next)
		node->next->prev = node->prev;

	node->prev = node->next;
	node->next = node->next->next;

	if (node->prev->next)
		node->prev->next->prev = node;

	node->prev->next = node;
}

/**
 * cocktail_sort_list - Sorts a doubly linked list of integers in ascending
 * order using the Cocktail Shaker Sort algorithm.
 * @list: Double pointer to the head of the doubly linked list
 */

void cocktail_sort_list(listint_t **list)
{
	int swapped = 1;
	listint_t *start = *list;
	listint_t *end = NULL;

	while (swapped)
	{
		swapped = 0;

		while (start && start->next != end)
		{
			if (start->n > start->next->n)
			{
				swap_nodes(list, start);
				swapped = 1;
				print_list(*list);
			}
			else
				start = start->next;
		}

		if (!swapped)
			break;

		swapped = 0;
		end = start;

		while (start && start->prev != end)
		{
			if (start->n < start->prev->n)
			{
				swap_nodes(list, start);
				swapped = 1;
				print_list(*list);
			}
			else
				start = start->prev;
		}
	}
}
