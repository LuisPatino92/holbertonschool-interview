#include "lists.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * check_cycle - Checks if there is a cycle in SLL
 * @list: Head
 *
 * Return: 1 if there is a cycle, 0 otherwise
 */
int check_cycle(listint_t *list)
{
	listint_t *slow, *fast;
	if (list == NULL)
		return 0;
	slow = list;
	fast = list;
	while (slow && fast && fast->next)
	{
		slow = slow->next;
		fast = fast->next->next;
		if (fast == slow)
			return 1;
	}
	return 0;
}
