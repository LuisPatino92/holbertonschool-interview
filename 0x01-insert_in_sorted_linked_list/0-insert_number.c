#include "lists.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * insert_node - Insert a number in a SLL
 * @head: DP to SLL head
 * @number: Number to be inserted
 * Return: NULL or inserted node direction
 */

listint_t *insert_node(listint_t **head, int number)
{
	listint_t *cnt;
	listint_t *tmp;
	listint_t *to_insert;

	cnt = *head;

	to_insert = malloc(sizeof(listint_t));

	if (!to_insert)
		return (NULL);

	to_insert->n = number;
	to_insert->next = NULL;

	if (*head == NULL)
	{
		*head = to_insert;
	}
	else
	{
		if (to_insert->n < cnt->n)
		{
			to_insert->next = cnt;
			*head = to_insert;
		}
		else
		{
			while (cnt->next != NULL)
			{
				if (cnt->next->n > to_insert->n)
				{
					tmp = cnt->next;
					cnt->next = to_insert;
					to_insert->next = tmp;
					break;
				}
				cnt = cnt->next;
			}
		}

		if (to_insert->n > cnt->n)
			cnt->next = to_insert;
	}

	return (to_insert);
}