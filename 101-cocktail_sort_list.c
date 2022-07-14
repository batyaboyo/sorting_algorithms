#include <stdio.h>
#include <stdlib.h>
#include "sort.h"
/**
  * cocktail_sort_list - doubly linked list of integers in ascending order
  * @list: doubly linked list
  */
void cocktail_sort_list(listint_t **list)
{
	listint_t *current, *nextnode, *prev;
	int finish_swapp = 0;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	current  = *list;
	while (!finish_swapp)
	{
		finish_swapp = 1;
		while (current->next != NULL)
		{
			nextnode = current->next;
			if (current->n > nextnode->n)
			{
				swap_node(current, nextnode, list);
				finish_swapp = 0;
			}

			else
				current = current->next;
		}
		while (current->prev != NULL)
		{
			prev = current->prev;
			if (current->n < prev->n)
			{
				swap_node(prev, current, list);
				finish_swapp = 0;
			}
			else
				current = current->prev;
		}
	}
}
/**
  * swap_node - swap 2 nodes in DLL
  * @prev: before node
  * @current: after node
  * @list: head of DLL
**/
void swap_node(listint_t *prev, listint_t *current, listint_t **list)
{
	listint_t *temp;

	temp = prev->prev;
	if (temp)
		temp->next = current;
	current->prev = temp;
	prev->prev = current;
	prev->next = current->next;
	current->next = prev;
	if (prev->next != NULL)
		prev->next->prev = prev;
	if (current->prev == NULL)
		*list = current;
	print_list(*list);
}
