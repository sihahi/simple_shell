#include "shell.h"
/**
 * freeList - frees list l_s used in env.
 * @head: the heard of linked list.
 */
void freeList(l_s **head)
{
	l_s *l1, *l2;

	if (head == NULL)
		return;
	if (*head == NULL)
		return;
	l1 = *head;
	while (l1 != NULL)
	{
		l2 = l1->next;
		/**
		 * invalid free() when using valgrind here??
		 * free(l2->s);
		 * free(l2);
		 */
		free(l1->s);
		free(l1);
		l1 = l2;
	}
	*head = NULL;
}
/**
 * handleSignal - handles the signal ctrl-c.
 * @n: the number of detected signal.
 */
void handleSignal(__attribute__((unused))int n)
{
	_puts("\n$ ");
	_putchar(-1);
}
/**
 * deleteCom - replaces the commentary '#'.
 * @s: the string to modify.
 */
void deleteCom(char *s)
{
	int i;

	for (i = 0; s[i] != '\0'; i++)
		if ((i == 0 || s[i - 1] == ' ') && s[i] == '#')
		{
			s[i] = '\0';
			break;
		}
}
/**
 * treat - if there something left in the buffer.
 * @ar: ...
 * @buffer: ...
 * @i: ...
 * @j: ...
 * @len: ...
*/
ssize_t treat(l_ar *ar, char *buffer, char **ptr, size_t i, size_t j, size_t len)
{
	char *s;

	s = buffer + i;
	if (ar->tcmd == 2)
	{
		if (!ar->st)
		{
			buffer[i] = 0;
			j = len;
		}
	}
	if (ar->tcmd == 1)
	{
		if (ar->st)
		{
			buffer[i] = 0;
			j = len;
		}
	}
	while (j < len)
	{
		if (delimiterExesit(ar, buffer, &j))
			break;
		j++;
	}
	j++;
	i = j;
	if (i >= len)
	{
		ar->tcmd = 0;
		i = 0;
		len = 0;
	}
	*ptr = s;
	return (_strlen(s));
}
/**
 * delimiterExesit - returns if exists delimiter or not.
 * @ar: the struct list_ar of arguments of shell.
 * @s: the buffer.
 * @n: the current posix in buffer (adress).
 * Return: ...
 */
int delimiterExesit(l_ar *ar, char *s, size_t *n)
{
	size_t r;

	r = *n;
	if (s[r] == '&' && s[r + 1] == '&')
	{
		ar->tcmd = 1;
		s[r] = 0;
		r++;
	}
	else if (s[r] == '|' && s[r + 1] == '|')
	{
		ar->tcmd = 2;
		s[r] = 0;
		r++;
	}
	else if (s[r] == ';')
	{
		ar->tcmd = 3;
		s[r] = 0;
	}
	else
		return (0);
	*n = r;
	return (1);
}
