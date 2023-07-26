#include "shell.h"

/**
 * _handler_ctrlc - ...
 * @n: ...
 */
void _handler_ctrlc(int n)
{
	if (n == SIGINT)
	{
		write(STDOUT_FILENO, "\n($) ", 5);
	}
}
/**
 * pnewline - ...
 * @command: ...
 */
void pnewline(char *command)
{
	free(command);
	if (isatty(STDIN_FILENO))
	{
		write(STDOUT_FILENO, "\n", 1);
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

