#include "shell.h"

/**
 * _strtok - splits a string into words
 * while ignoring the reapeting delimiters.
 * @s: the string.
 * @sd: the string delimeter.
 * Return: a pointer , or NULL if it fails.
 */

char **_strtok(char *s, char *sd)
{
	char **r;
	int a, b, c, d, e;

	if (s == NULL || s[0] == 0)
		return (NULL);
	if (sd == 0)
		sd = " ";
	e = getLenTok(s, sd);
	if (e == -1)
		return (NULL);
	r = _calloc((e + 2), sizeof(char *));
	if (r == NULL)
		return (NULL);
	for (a = 0, b = 0; b < e + 1; b++)
	{
		c = 0;
		while (!inDlm(s[a], sd))
			a++;
		while (inDlm(s[a + c], sd) && s[a + c])
			c++;
		r[b] = _calloc((c + 2), sizeof(char));
		if (r[b] == NULL)
		{
			for (c = 0; c < b; c++)
				free(r[c]);
			free(r);
			return (NULL);
		}
		for (d = 0; d < c; d++)
			r[b][d] = s[a++];
		r[b][d] = 0;
	}
	r[b] = NULL;
	return (r);
}

/**
 * _freetok - ...
 * @tk: ...
 */
void _freetok(char **tk)
{
	char **r = tk;

	if (!tk)
		return;
	while (*tk)
		free(*tk++);
	free(r);
}
/**
 * getLenTok - ...
 * @s: the string.
 * @sd: the string delimeter.
 * Return: length.
 */
int getLenTok(char *s, char *sd)
{
	int a, b, c, l = -1;

	for (a = 0; s[a] != '\0'; a++)
	{
		b = inDlm(s[a], sd);
		c = inDlm(s[a + 1], sd);
		if ((b == 1) && (!s[a + 1] || (c == 0)))
			l++;
	}
	return (l);
}
/**
 * inDlm - checks if delimiter.
 * @c: the input char.
 * @ds: the delimeter string.
 * Return: 0 on success.
 */
int inDlm(char c, char *ds)
{
	while (*ds)
		if (*ds++ == c)
			return (0);
	return (1);
}
