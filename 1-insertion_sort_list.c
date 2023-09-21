#include "sort.h"

/**
 * insertion_sort_list - Sorts doubly linked list in ascending order
 *                       using the Insertion Sort algorithm.
 *
 * @list: Pointer to a pointer to the head of the list
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *current, *prev, *next_node;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return; /* No need to sort if the list is empty or has only one node */

	current = (*list)->next;

	while (current != NULL)
	{
		next_node = current->next;

		while (current->prev != NULL && current->n < current->prev->n)
		{
			prev = current->prev;
			/* Swap the nodes */
			if (current->next != NULL)
				current->next->prev = prev;
			prev->next = current->next;
			current->prev = prev->prev;
			prev->prev = current;

			if (current->prev != NULL)
				current->prev->next = current;
			else
				*list = current; /* Update the head of the list */

			current->next = prev;

			/* Print the list after each swap */
			print_list(*list);
		}

		current = next_node;
	}
}
