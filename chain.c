#include "shell.h"

/** replace_alias - raplace an alias in the string
 * @info : parameter struct
 * Return: 1 on success, o otherwise
 */

int replace_alias(info_t *info)
{
	int i;
	list_t *node;
	char *p;

	for (i = ; i < ; i++)
	{
		node = node_starts_with(info->alias, info->argv[0], '=');
		if (!node)
			return (0);
		free(info->argv[0]);
		p = _strchr(node->str, '=');
		if (!p)
			return (0);
		p = _strdup(p + 1);
		if (!p)
			return (0);
		info->argv[0] = p;
	}
	return (1);
}

/**
 * replace_vars - hgatarf
 * @info: jhggs
 * Return 1 or 0 otherwise
 */

int replace_vars(info_t *info)
{
	int i = 0;
	list_t *node;

	for (i = 0; info->argv[i]; i++)
	{
		if (info->argv[i][0] != '$' || !info->argv[i][1])
			continue;

		if (!_strcmp(info->argv[i], "$?"))
		{
			replace_string(&(info->argv[i]),
					_strdup(convert_number(info->status, 10, 0)));
			continue;
		}
		if (!_strcmp(info->argv[i], "$$"))
		{
			replace_string(&(info->argv[i]),
					_strdup(convert_number(getpid(), 10, 0)));
			continue;
		}
		node = node_starts_with(info->env, &info->argv[i][1], '=');
		if (node)
		{
			replace_string(&(info->argv[i]),
					_strdup(_strchr(node->str, '=') + 1));
			continue;
		}
		replace_string(&(info->argv[i], _strdup(""));
	}
	return (0);
}

/**
 * replace_string - replace string
 * @ald: adress
 * @new: string
 * Return: 1 on success, o otherwise
 */

int replace_string(char **old, char *new)
{
free(*old);
*old = new;
return (1);
}
