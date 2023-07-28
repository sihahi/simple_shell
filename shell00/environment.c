#include "shell.h"
/**
 * _getenv - ...
 * @env: ...
 * Return: ...
 */
l_u *_getenv(char **env)
{
	int i = 0;
	l_u *linked;
	char *s2;

	linked = NULL;
	s2 = " ";
	while (env[i])
	{
		add_nod(&linked, env[i], s2);
		i++;
	}
	return (linked);
}
/**
 * _getenvval - ...
 * @s: ...
 * @e: ...
 * Return: ...
 */
char *_getenvval(char *s, l_u *e)
{
	char *val = NULL;
	int i = 0, j, k, l = 0;

	while (e != NULL)
	{
		while (s[i] == (e->s1)[i])
			i++;
		if (s[i] == '\0' && (e->s1)[i] == '=')
			break;
		e = e->next;
	}
	i = 0;
	while ((e->s1)[i] != '=')
		i++;
	i++;
	j = i;
	while ((e->s1)[i] != '\0')
		i++;
	val = malloc(sizeof(char) * (i - j + 2));
	if (val == NULL)
		return (NULL);
	for (k = j; k < i + 1; k++)
	{
		val[l] = (e->s1)[k];
		l++;
	}
	return (val);
}
/**
 * _lenv - ...
 * @e: ...
 * Return: ...
 */
char **_lenv(l_u *e)
{
	char **val;
	int i = 0, j, l = 0;

	while (e != NULL)
		l++;
	val = malloc(l);
	while (e != NULL)
	{
		while ((e->s1)[i] != '\0')
			i++;
		val[j] = malloc(i + 1);
		_strcpy(val[j], (e->s1));
		e = e->next;
		i = 0;
		j++;
	}
	return (val);
}
