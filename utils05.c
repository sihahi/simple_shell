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
	l1->s1 = _strdup(s1);
	l1->s2 = _strdup(s2);
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
/**
 * _getlinev2 - ...
 * @s: ...
 * @sf: ...
 * Return: ...
 */
ssize_t _getlinev2(char **s, int sf)
{
	static char lbuffer[BUF_SIZE];
	ssize_t fd = 0, l1 = 0, l2 = 0, i = 0, r = 0;

	fd = read(sf, lbuffer, 1024 - 1);
	while (l2 == 0 && fd)
	{
		i = 0;
		if (fd == -1)
			return (-1);
		lbuffer[fd] = '\0';
		while (lbuffer[i] != '\0')
		{
			if (lbuffer[i] == '\n')
				l2 = 1;
			i++;
		}
		if (l1 == 0)
		{
			fd++;
			*s = malloc(sizeof(char) * fd);
			r = fd;
			l1 = 1;
			*s = _strcpy(*s, lbuffer);
		}
		else
		{
			*s = _strcat(*s, lbuffer);
			r += fd;
		}
	}
	return (r);
}
/**
 * _strdup - returns a pointer to a newly allocated
 * space in memory, which contains a copy.
 * of the string given as a parameter.
 * @s: input string.
 * Return: pointer to duplicated string.
 */
char *_strdup(char *s)
{
	int i = 0, j = 0;
	char *a;

	if (s == NULL)
		return (NULL);
	while (s[j])
		j++;
	/**
	 *  valgrind error here a should be freed later
	 */
	a = malloc((j + 1));
	if (!a)
		return (NULL);
	while (i < j)
	{
		a[i] = s[i];
		i++;
	}
	a[i] = '\0';
	return (a);
}
