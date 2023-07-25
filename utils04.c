#include "shell.h"
/**
 * getNodeOf - finds node which its s val
 * starts with the given string s.
 * @l: the pointer to head of l_s.
 * @s: tthe string to match.
 * @c: the next character to match.
 * Return: ...
 */
l_s *getNodeOf(l_s *l, char *s, char c)
{
	char *a = NULL;

	while (l != NULL)
	{
		while (*s)
		{
			if (*s++ != *l->s++)
				continue;
		}
		a = l->s;
		if (a && ((c == -1) || (*a == c)))
			return (l);
		l = l->next;
	}
	return (NULL);
}
/**
 * getAddressStr - gets the adress by locating
 * a char in the input string.
 *@s: the input string.
 *@c: the char to be located.
 *Return: pointer to the location(adress).
 */
char *getAddressStr(char *s, char c)
{
	do {
		if (*s == c)
			return (s);
	} while (*s++ != '\0');

	return (NULL);
}
/**
 * getInPath - finds the command in
 * path and gets full path.
 * @ar: the structs of args of shell.
 * @ps: the value of path.
 * @s: the value of command.
 * Return: ...
 */
char *getInPath(l_ar *ar, char *ps, char *s)
{
	int i = 0, a = 0;
	char *path, *p;
	struct stat st;

	p =  getEnvv(ar, ps);
	if (!p)
		return (NULL);
	if ((_strlen(s) > 2) && _strbg(s, "./"))
		if (!(!s || stat(s, &st)))
			if (st.st_mode & S_IFREG)
				return (s);
	while (1)
	{
		if (!p[i] || p[i] == ':')
		{
			path = pathDup(p, a, i);
			if (!*path)
				_strcat(path, s);
			else
			{
				_strcat(path, "/");
				_strcat(path, s);
			}
			if (!(!path || stat(path, &st)))
				if (st.st_mode & S_IFREG)
					return (path);
			if (!p[i])
				break;
			a = i;
		}
		i++;
	}
	return (NULL);
}
/**
 * _strbg - checks if string b starts with a.
 * @a: the string to search.
 * @b: the string to find.
 * Return: pointer to next char or NULL.
 */
char *_strbg(const char *a, const char *b)
{
	while (*b)
		if (*b++ != *a++)
			return (NULL);
	return ((char *)a);
}
/**
 * pathDup - duplicates characters of path.
 * @s: the value of path.
 * @a: the starting point.
 * @b: the ending point.
 * Return: ...
 */
char *pathDup(char *s, int a, int b)
{
	int i = 0, j = 0;
	static char buffer[BUFFER_SIZE];

	for (j = 0, i = a; i < b; i++)
		if (s[i] != ':')
			buffer[j++] = s[i];
	buffer[j] = 0;
	return (buffer);
}
