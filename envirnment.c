#include "shell.h"
/**
 * initEnv - adds the value of the envirnment
 * to the shell list (ar).
 * @ar: the struct of args of shell.
 * Return: 0 on sucess.
 */
int initEnv(l_ar *ar)
{
	size_t i;
	l_s *env_l = NULL;

	for (i = 0; environ[i]; i++)
	{
		/**
		 * add_node_end used to keep the same position of the value.
		 * this part creates a valgrind error.
		 * tried to free the env_l created more problems.
		 * the ar->env is freed in the freeAllArgShell.
		 * but there is ann issue it doesn't free correctly.
		 */
		add_node_end(&env_l, environ[i]);
	}
	ar->env = env_l;
	return (0);
}
/**
 * getEnvv - gets the env value.
 * @ar: the struct of args of shell.
 * @s: the siable in env.
 * Return: ...
 */
char *getEnvv(l_ar *ar, const char *s)
{
	char *p;
	l_s *l;

	l = ar->env;
	while (l)
	{
		while (*s)
		{
			if (*s++ != *l->s++)
				return (NULL);
		}
		p = l->s;
		if (p && *p)
			return (p);
		l = l->next;
	}
	return (NULL);
}
