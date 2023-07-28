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
	char *c = NULL, *a = NULL;

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
	return (r);
}
