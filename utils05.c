#include "shell.h"
/**
 * _strcat - concatenates two strings.
 * @s1: the input string to append too.
 * @s2: the input string to be appended.
 * Return: the resulting string.
 */
char *_strcat(char *s1, char *s2)
{
	char *r;

	r = s1;
	while (*s1)
		s1++;
	while (*s2)
		*s1++ = *s2++;
	*s1 = *s2;
	return (r);
}
/**
 * getArray - returns an array of strings.
 * @head: the head of the linked list.
 * Return: ...
 */
char **getArray(l_s *head)
{
	size_t i = 0, j;
	char *s, **t;
	l_s *l = head;

	while (head)
	{
		head = head->next;
		i++;
	}
	if (i == 0 || l == NULL)
		return (NULL);
	t = malloc(sizeof(char *) * (i + 1));
	if (t == NULL)
		return (NULL);
	for (i = 0; l; l = l->next, i++)
	{
		s = malloc(_strlen(l->s) + 1);
		if (s == NULL)
		{
			for (j = 0; j < i; j++)
				free(t[j]);
			free(t);
			return (NULL);
		}
		s = _strcpy(s, l->s);
		t[i] = s;
	}
	t[i] = NULL;
	return (t);
}
/**
 * _strcpy - copy the string.
 * @s1: the destination of the string.
 * @s2: the source of the string.
 * Return: the copieed string.
 */
char *_strcpy(char *s1, char *s2)
{
	int i = 0;

	if (s1 == s2 || s2 == 0)
		return (s1);
	while (s2[i])
	{
		s1[i] = s2[i];
		i++;
	}
	s1[i] = '\0';
	return (s1);
}
/**
 * freeArgShell - frees argv and path fields in shell args.
 * @ar: the struct list_arg of argument about the shell.
 */
void freeArgShell(l_ar *ar)
{
	char **s = ar->argv;

	if (ar->argv)
	{
		while (*ar->argv)
			free(*ar->argv++);
		free(s);
	}
	ar->argv = NULL;
	ar->path = NULL;
}
/**
 * freeAllArgShell - frees all fields shell args.
 * @ar: the struct list_arg of argument about the shell.
 */
void freeAllArgShell(l_ar *ar)
{
	char **s = ar->envr, **c = ar->bcmd;

	freeArgShell(ar);
	if (ar->env)
		freeList(&(ar->env));
	if (ar->envr)
	{
		while (*ar->envr)
			free(*ar->envr++);
		free(s);
	}
	if (ar->bcmd)
	{
		while (*ar->bcmd)
			free(*ar->bcmd++);
		free(c);
	}
	ar->envr = NULL;
	ar->bcmd = NULL;
	if (ar->file_in > 2)
		close(ar->file_in);
	ar->filename = NULL;
	_putchar(-1);
}
