#include "shell.h"

/**
 * _handler_ctrlc - ...
 * @n: ...
 */
void _handler_ctrlc(int n)
{
	if (n == SIGINT)
	{
		write(STDOUT_FILENO, "\n$ ", 3);
	}
}
/**
 * pnewline - ...
 * @s: ...
 */
void pnewline(char *s)
{
	free(s);
	if (isatty(STDIN_FILENO))
	{
		write(STDOUT_FILENO, "\n", 1);
	}
}
/**
 * exitnewline - ...
 * @tk: ...
 * @e: ...
 * @s: ...
 * @fd: ...
 */
void exitnewline(char **tk, l_u *e, char *s, ssize_t fd)
{
	if (fd == -1 || fd == 0)
	{
		pnewline(s);
		if (tk)
			_freetok(tk);
		freel(e);
		exit(fd);
	}
}
/**
 * dnewline - ...
 * @s: ...
 * Return: ...
 */
char *dnewline(char *s)
{
	int i = 0;

	while (s[i])
	{
		if (s[i] == '\n')
		{
			s[i] = '\0';
		}
		i++;
	}
	return (s);
}
/**
 * checkcounter - ...
 * @c: ...
 * Return: ...
 */
ssize_t checkcounter(ssize_t c)
{
	if (c == 0)
	{
		fflush(STDIN_FILENO);
	}
	else
	{
		return (-1);
	}
	return (0);
}
