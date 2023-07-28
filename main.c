#include "shell.h"

/**
 * main - main entry function.
 * @argc: the number of arguments.
 * @argv: the list of arguments.
 * Return: 0 on success.
 */
int main(int argc, char **argv)
{
	l_u *e;

	(void) argv;
	e = _getenv(environ);
	if (argc == 1)
		i_mode(e);
	freel(e);
	return (0);
}
