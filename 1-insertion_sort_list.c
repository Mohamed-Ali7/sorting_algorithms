#include "sort.h"
#include <stdio.h>

/**
 * insertion_sort_list - Sorts a doubly linked list of integers
 * in ascending order using the Insertion sort algorithm
 *
 * @list: Is a pointer to the pointer to the first element of the list
 * Return: void
*/

void insertion_sort_list(listint_t **list)
{
	listint_t *key = *list;
	listint_t *cur = NULL;

	if (!list || !*list)
		return;

	while (key->next != NULL)
	{
		cur = key;
		key = key->next;
		while (cur != NULL && key->n < cur->n)
		{
			key->prev = cur->prev;
			cur->next = key->next;

			if (key->next)
				key->next->prev = cur;

			key->next = cur;
			if (cur->prev)
			{
				cur->prev->next = key;
				cur->prev = key;
			}
			else
			{
				key->next = *list;
				(*list)->prev = key;
				*list = key;
				key->prev = NULL;
			}

			cur = key->prev;
			print_list(*list);
		}
	}
}
