#include "lists.h"

/**
 * check - Checks if a SLL is a palindrome
 * @l: head
 * @r: head
 *
 * Return: 0 if not palindrome, 1 if palindrome
 */

int check(listint_t **l, listint_t *r)
{
	int val;

	if (r == NULL)
		return (1);

	val = check(l, r->next);

	if (val == 0)
		return (0);

	val = (r->n == (*l)->n);

	*l = (*l)->next;

	return (val);
}


/**
 * is_palindrome - Checks if a SLL is a palindrome
 * @head: head
 *
 * Return: 0 if not palindrome, 1 if palindrome
 */

int is_palindrome(listint_t **head)
{
	if (!head)
		return (0);
	return (check(head, *head));
}
