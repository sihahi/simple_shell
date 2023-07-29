#include "shell.h"

/**
 * _bi_exit - ...
 * @tk: ...
 * @e: ...
 * Return: ...
 */
int _bi_exit(char **tk, l_u *e)
{
	int i = 0;

	if (tk[1] == NULL)
	{
		freel(e);
		_freetok(tk);
		exit(0);
	}
	else
		i = _atoi(tk[1]);
	if (i < 0)
	{
		_puts("exit: Illegal number: ");
		_puts(tk[1]);
		_putchar('\n');
		return (-1);
	}
	freel(e);
	_freetok(tk);
	exit(i);
}
/**
 * _bi_env - ...
 * @e: ...
 * Return: ...
 */
int _bi_env(l_u *e)
{
	while (e != NULL)
	{
		if (e->s1 != NULL)
		{
			_puts(e->s1);
			_putchar('\n');
		}
		else
		{
			_putchar('\n');
		}
		e = e->next;
	}
	return (0);
}
/**
 * _bi_cd - ...
 * @tk: ...
 * @e: ...
 * Return: ...
 */
int _bi_cd(char **tk, l_u *e)
{
	int r = 0;
	char *c = NULL, *a = NULL, *b = NULL;

	a = getcwd(a, 0);
	if (!tk[1])
	{
		c = _getenvval("HOME", e);
		_setenv("OLDPWD", a, &e);
		free(a);
		if (access(c, F_OK) == 0)
			chdir(c);
		free(c);
		a = NULL;
		a = getcwd(a, 0);
		_setenv("PWD", a, &e);
		free(a);
	}
	else
	{
		if (tk[1][0] == '-')
		{
			if (tk[1][1] == '\0')
				b = _getenvval("OLDPWD", e);
		}
		else if (tk[1][0] == '~')
		{
			b = _getenvval("HOME", e);
			b = comb(b, tk[1]);
		}
		else
			b = cddir(b, tk[1]);
		r = cdex(a, b, tk[1], e);
		free(b);
	}
	return (r);
}

/**
 * cdex - ...
 * @a: ...
 * @b: ...
 * @s: ...
 * @e: ...
 * Return: ...
 */
int cdex(char *a, char *b, char *s, l_u *e)
{
	int r = 0;

	if (access(b, F_OK))
	{
		r = 2;
		puts("cd: can't access drictrory: ");
		puts(s);
		puts("\n");
		free(a);
	}
	else
	{
		_setenv("OLDPWD", a, &e);
		free(a);
		a = NULL;
		chdir(b);
		a = getcwd(a, 0);
		_setenv("PWD", a, &e);
		free(a);
	}
	return (r);
}
/**
 * cddir - ...
 * @b: ...
 * @s: ...
 * Return: ...
 */
char *cddir(char *b, char *s)
{
	if (s[0] != '/')
	{
		b = getcwd(b, 0);
		b = _strcat(b, "/");
		b = _strcat(b, s);
	}
	else
		b = _strdup(s);
	return (b);
}
