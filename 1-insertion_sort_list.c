#include "sort.h"

/**
 * swap_my_nodes - Swaps 2 nodes in a listint_t doubly-linked list.
 * @hp: A pointer to the head.
 * @na1: A pointer to the first node.
 * @na2: The second node.
 */
void swap_my_nodes(listint_t **hp, listint_t **na1, listint_t *na2)
{
	(*na1)->next = na2->next;
	if (na2->next != NULL)
		na2->next->prev = *na1;
	na2->prev = (*na1)->prev;
	na2->next = *na1;
	if ((*na1)->prev != NULL)
		(*na1)->prev->next = na2;
	else
		*hp = na2;
	(*na1)->prev = na2;
	*na1 = na2->prev;
}

/**
 * insertion_sort_list - Sorts a doubly linked list of ints
 *                       using the insertion sort.
 * @list: A pointer to the head of a doubly-linked list.
 *
 * Description: Prints the list being processed after each swap.
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *iterlst, *insertlst, *tmplst;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	for (iterlst = (*list)->next; iterlst != NULL; iterlst = tmplst)
	{
		tmplst = iterlst->next;
		insertlst = iterlst->prev;
		while (insertlst != NULL && iterlst->n < insertlst->n)
		{
			swap_my_nodes(list, &insertlst, iterlst);
			print_list((const listint_t *)*list);
		}
	}
}
