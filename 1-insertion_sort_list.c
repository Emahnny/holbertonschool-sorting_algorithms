#include "sort.h"

/**
 * insertion_sort_list - Function that sorts a doubly linked lsit
 * of integers in ascending order using the insertion sort algorithm.
 *
 * @list: List with integers to sort.
 */


void insertion_sort_list(listint_t **list)
{
	listint_t *current, *temp, *temp_prev;

	if (!list || !*list || !(*list)->next)
	{
		return;
	}
	for (current = (*list)->next; current != NULL; current = current->next)
	{
		temp = current;
		temp_prev = temp->prev;
		while (temp_prev && temp->n < temp_prev->n)
		{
			temp->prev->next = temp->next;
			if (temp->next != NULL)
			{
				temp->next->prev = temp->prev;
			}
			temp->next = temp_prev;
			temp->prev = temp_prev->prev;
			if (temp->prev != NULL)
			{
				temp->prev->next = temp;
			}
			else
			{
				*list = temp;
			}
			temp->next->prev = temp;
			temp_prev = temp->prev;
			print_list(*list);
		}
	}
}

