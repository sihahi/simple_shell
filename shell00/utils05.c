#include "shell.h"
/**
 * add_nod - adds a new node at the beginning of a list_t list.
 * @head: the linked list.
 * @s1: the string to add.
 * @s2: ...
 * Return: the address of the new list.
 */
l_u *add_nod(l_u **head, char *s1, char *s2)
{
	l_u *l1, *l2;

	if (head == NULL || s1 == NULL || s2 == NULL)
		return (NULL);
	l1 = _calloc(1, sizeof(l_u));
	if (l1 == NULL)
		return (NULL);
	l1->s1 = s1;
	l1->s2 = s2;
	l1->next = NULL;
	l2 = *head;
	if (l2 != NULL)
	{
		while (l2->next != NULL)
		{
			l2 = l2->next;
		}
		l2->next = l1;
	}
	else
		*head = l1;
	return (*head);
}
