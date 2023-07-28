#include "shell.h"

/**
 * _erratoi - jbbdjggttd
 * @s: the string to be converted
 * Return: 0, -1 on error
 */

int _erratoi(char *s)
{
	int i = 0;
	unsigned long int res = 0;

	if (*s == '+')
		s++;
	for (i = 0; s[i] != '\0'; i++)
	{
		if (s[i] >= '0' && s[i] <= '9')
		{
			res *= 10;
			res += (s[i] - '0');
			if (res > INT_MAX)
				return (-1);
		}
		else
			return (-1);
	}
	return (res);
}

/**
 * print_error - hbdhyfddf
 * @info: the jjdjvggd
 * @estr: nvhdh
 * Return: 0, or -1 on error
 */

void print_error(info_t *info, char *estr)
{
	_eputs(info->fname);
	_eputs(": ");
	print_d(info->line_count, STDERR_FILENO);
	_eputs(": ");
	_eputs(info->argc[0]);
	_eputs(": ");
	_eputs(estr);
}
