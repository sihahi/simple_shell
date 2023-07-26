#include "shell.h"

/**
 * main - main entry function.
 * @argc: the number of arguments.
 * @argv: the list of arguments.
 * @env: the variable ennvironment.
 * Return: 0 on success.
 */
int main(int argc, char **argv, char **env)
{
	l_u *e;

	(void) argv;
	e = _getenv(env);
	/* a = get_aliases(); */
	if (argc == 1)
	{
		i_mode(e);
	}
	/*
	 * else if (argc > 1){
	 * n_i_mode(argv, e); }
	 */
	return (0);
}
