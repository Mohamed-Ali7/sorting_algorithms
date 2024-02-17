#include "sort.h"
/**
 * swap_nodes - Swaps to nodes of a doubly linked list
 * @list: Is a pointer the list to swap it's nodes
 * @cur: Is the first node to swap
 * @next: Is the second node to swap
 * Return: void
*/
void swap_nodes(listint_t **list, listint_t *cur, listint_t *next)
{
	cur->next = next->next;
	next->prev = cur->prev;

	if (next->next)
		next->next->prev = cur;
	next->next = cur;

	if (cur->prev)
	{
		cur->prev->next = next;
		cur->prev = next;
	}
	else
	{
		cur->prev = next;
		*list = next;
	}
}

/**
 * cocktail_sort_list - Sorts a doubly linked list of integers
 * in ascending order using the Cocktail sort algorithm
 *
 * @list: Is a pointer to the pointer to the first element of the list
 * Return: void
*/

void cocktail_sort_list(listint_t **list)
{
	listint_t *node;
	int swapped = 1;

	if (!list || !*list)
		return;

	while (swapped)
	{
		swapped = 0;
		node = *list;
		while (node->next)
		{
			if (node->n > node->next->n)
			{
				swap_nodes(list, node, node->next);
				print_list(*list);
				swapped = 1;
			}
			else
				node = node->next;
		}

		if (!swapped)
			break;

		while (node->prev)
		{
			if (node->n < node->prev->n)
			{
				swap_nodes(list, node->prev, node);
				print_list(*list);
			}
			else
				node = node->prev;
		}
	}
}
