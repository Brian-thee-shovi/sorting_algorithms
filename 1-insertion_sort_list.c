#include "sort.h"

/**
 * listlen - returns length of Dlinked list
 * @h: pointer to the head list
 * Return: length of the list
 */
int listlen(listint_t *h)
{
	int l_length = 0;

	while (h != NULL)
	{
		l_length++;
		h = h->next;
	}
	return (l_length);
}
/**
 * insertion_sort_list - sorts a Dlinked list in ascending order
 * @list: Dpointer to the list being sorted
 * Return: nothing
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *my_current = NULL, *_1 = NULL;
	listint_t *_2 = NULL, *_3 = NULL, *_4 = NULL;

	if (!list || !(*list) || listlen(*list) < 2)
		return;
	my_current = *list;

	while (my_current)
	{
		if (my_current->prev && my_current->n < my_current->prev->n)
		{
			_1 = my_current->prev->prev;
			_2 = my_current->prev;
			_3 = my_current;
			_4 = my_current->next;

			_2->next = _4;
			if (_4)
				_4->prev = _2;
			_3->next = _2;
			_3->prev = _1;
			if (_1)
				_1->next = _3;
			else
				*list = _3;
			_2->prev = _3;
			my_current = *list;
			print_list(*list);
			continue;
		}
		else
			my_current = my_current->next;
	}
}


