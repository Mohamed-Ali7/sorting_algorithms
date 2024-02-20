#include "deck.h"
#include <string.h>
 #include <stdlib.h>
int is_digit(char c);
char *cast_value(const char *value);


/**
 * swap_nodes - Swaps to nodes of a doubly linked list
 * @list: Is a pointer the list to swap it's nodes
 * @cur: Is the first node to swap
 * @next: Is the second node to swap
 * Return: void
*/
void swap_nodes(deck_node_t **list, deck_node_t *cur, deck_node_t *next)
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
 * sort_deck - Sorts a doubly linked list that represent a deck of cards
 * @deck: Is a pointer to the pointer to the first node of the list
 * Return: void
*/

void sort_deck(deck_node_t **deck)
{
	deck_node_t *temp;
	deck_node_t *cur;
	char *cur_value;
	char *next_value;

	if (!deck || !*deck || !(*deck)->next)
		return;
	temp = *deck;
	while (temp)
	{
		cur = *deck;
		while (cur->next)
		{
			cur_value =  cast_value(cur->card->value);
			next_value =  cast_value(cur->next->card->value);

			if (cur->card->kind > cur->next->card->kind)
			{
				swap_nodes(deck, cur, cur->next);
			}
			else if (cur->card->kind == cur->next->card->kind)
			{
				if (atoi(cur_value) > atoi(next_value))
					swap_nodes(deck, cur, cur->next);
				else
					cur = cur->next;
			}
			else
				cur = cur->next;
		}
		temp = temp->next;
	}
}

/**
 * cast_value - Casts the value of the card to a number value
 * if it's not a number for example: if the value (Ace, Jack, Queen, or King)
 *
 * @value: Is the value to cast
 * Return: The new string number value
*/
char *cast_value(const char *value)
{
	char *new_value = (char *) value;

	if (!is_digit(*value))
	{
		if (strcmp(value, "Ace") == 0)
			new_value = "1";
		else if (strcmp(value, "Jack") == 0)
			new_value = "11";
		else if (strcmp(value, "Queen") == 0)
			new_value = "12";
		else if (strcmp(value, "King") == 0)
			new_value = "13";
	}
	return (new_value);
}

/**
 * is_digit - Checks if a character is a digit or not
 * @c: Is the character to check
 * Return: 1 if the character is digit otherwise returns 0
*/
int is_digit(char c)
{
	return (c >= '0' && c <= '9');
}
