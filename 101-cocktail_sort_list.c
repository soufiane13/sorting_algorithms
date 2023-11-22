#include "sort.h"

void swap_node_ahead(listint_t **list, listint_t **tail_c, listint_t **shaker_c);
void swap_node_behind(listint_t **list, listint_t **tail_c, listint_t **shaker_c);
void cocktail_c_sort_list(listint_t **list);

/**
 * swap_node_ahead - Swap a node in a listint_t doubly-linked list.
 * @list: A pointer to the head .
 * @tail_c: A pointer to the tail_c .
 * @shaker_c: A pointer to the current swapping node .
 */
void swap_node_ahead(listint_t **list, listint_t **tail_c, listint_t **shaker_c)
{
	listint_t *tmp = (*shaker_c)->next;

	if ((*shaker_c)->prev != NULL)
		(*shaker_c)->prev->next = tmp;
	else
		*list = tmp;
	tmp->prev = (*shaker_c)->prev;
	(*shaker_c)->next = tmp->next;
	if (tmp->next != NULL)
		tmp->next->prev = *shaker_c;
	else
		*tail_c = *shaker_c;
	(*shaker_c)->prev = tmp;
	tmp->next = *shaker_c;
	*shaker_c = tmp;
}

/**
 * swap_node_behind - Swap a node in a listint_t doubly-linked
 * @list: A pointer to the head .
 * @tail_c: A pointer to the tail_c .
 * @shaker_c: A pointer to the current swapping node .
 */
void swap_node_behind(listint_t **list, listint_t **tail_c, listint_t **shaker_c)
{
	listint_t *tmp = (*shaker_c)->prev;

	if ((*shaker_c)->next != NULL)
		(*shaker_c)->next->prev = tmp;
	else
		*tail_c = tmp;
	tmp->next = (*shaker_c)->next;
	(*shaker_c)->prev = tmp->prev;
	if (tmp->prev != NULL)
		tmp->prev->next = *shaker_c;
	else
		*list = *shaker_c;
	(*shaker_c)->next = tmp;
	tmp->prev = *shaker_c;
	*shaker_c = tmp;
}

/**
 * cocktail_c_sort_list - Sort a listint_t doubly-linked list of integers 
 * @list: A pointer to the head .
 */
void cocktail_c_sort_list(listint_t **list)
{
	listint_t *tail_c, *shaker_c;
	bool shaken_not_stirred = false;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	for (tail_c = *list; tail_c->next != NULL;)
		tail_c = tail_c->next;

	while (shaken_not_stirred == false)
	{
		shaken_not_stirred = true;
		for (shaker_c = *list; shaker_c != tail_c; shaker_c = shaker_c->next)
		{
			if (shaker_c->n > shaker_c->next->n)
			{
				swap_node_ahead(list, &tail_c, &shaker_c);
				print_list((const listint_t *)*list);
				shaken_not_stirred = false;
			}
		}
		for (shaker_c = shaker_c->prev; shaker_c != *list;
				shaker_c = shaker_c->prev)
		{
			if (shaker_c->n < shaker_c->prev->n)
			{
				swap_node_behind(list, &tail_c, &shaker_c);
				print_list((const listint_t *)*list);
				shaken_not_stirred = false;
			}
		}
	}
}
