#include "search.h"

/**
 * linear_skip - search in a sorted skip list
 * @list: pointer to head
 * @value: desired value
 *
 * Return: Null or pointer to value
 */
skiplist_t *linear_skip(skiplist_t *list, int value)
{
	skiplist_t *cnt_node, *n_m;
	size_t cnt_val;

	if (!list)
		return (NULL);

	cnt_node = list, n_m = list;

	while (cnt_node && cnt_node->next && (cnt_node->n) < value)
	{
		n_m = cnt_node;

		if (cnt_node->express)
		{
			cnt_node = cnt_node->express;
			printf("Value checked at index [%lu] = [%d]\n",
				   cnt_node->index, cnt_node->n);
		}
		else
			while (cnt_node->next)
				cnt_node = cnt_node->next;
	}

	printf("Value found between indexes [%lu] and [%lu]\n",
		   n_m->index, cnt_node->index);

	for (cnt_val = n_m->index;
		 cnt_val <= (cnt_node->index) && (n_m->n <= value);
		 cnt_val++, n_m = n_m->next)
	{
		printf("Value checked at index [%lu] = [%d]\n", cnt_val, n_m->n);
		if (n_m && (n_m->n) == value)
			return (n_m);
	}

	if (n_m)
		printf("Value checked at index [%lu] = [%d]\n", cnt_val, n_m->n);

	return (NULL);
}
