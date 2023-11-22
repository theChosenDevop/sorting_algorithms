#include "sort.h"

/**
 * insertion_sort_list - sorts a doubly linked list of integers
 *			in ascending order
 * @list: doubly linked list of integers
 * Return: void
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *curr, *temp, *sorted;

	if (*list == NULL || (*list)->next == NULL)
		return;

	sorted = NULL;
	while (*list != NULL)
	{
		curr = *list;
		*list = (*list)->next;

		if (sorted == NULL || curr->n < sorted->n)
		{
			curr->next = sorted;
			curr->prev = NULL;
			if (sorted != NULL)
				sorted->prev = curr;
			sorted = curr;
		}
		else
		{
			temp = sorted;
			while (temp->next != NULL && temp->next->n < curr->n)
				temp = temp->next;
			curr->next = temp->next;
			if (temp->next != NULL)
				temp->next->prev = curr;
			curr->prev = temp;
			temp->next = curr;
		}
	}
	print_list(sorted);
	*list = sorted;
}
