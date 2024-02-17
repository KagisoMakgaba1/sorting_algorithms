#include "sort.h"

/**
 * insertion_sort_list - Sorts a doubly linked list in ascending order
 * using the Insertion sort algorithm.
 * @list: Pointer to the doubly linked list
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *current, *back, *next;

	if (list == NULL || *list == NULL)
		return;

	current = (*list)->next;
	while (current != NULL)
	{
		back = current->prev;
		next = current->next;
		while (back != NULL && back->n > current->n)
		{
			if (back->next != NULL)
				back->next->prev = current;

			if (current->prev != NULL)
				current->prev->next = current->next;

			current->next = back;
			current->prev = back->prev;

			if (back->prev != NULL)
				back->prev->next = current;

			back->prev = current;

			if (current->prev == NULL)
				*list = current;

			print_list(*list);
			back = current->prev;
		}

		current = next;
	}
}
