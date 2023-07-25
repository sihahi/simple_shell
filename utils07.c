#include "shell.h"
/**
 * getlineCus - custtom getline.
 * @ar: the struct of args of shell
 * @s: the already allocated buffer
 * in read line (buffer).
 * @len: length.
 * Return: ...
 */
int getlineCus(__attribute__((unused))l_ar *ar, __attribute__((unused))char **s, __attribute__((unused)) size_t *len)
{
	ssize_t t = 0;

	return (t);
}
/**
 * _strchr - return lenght after
 * locates a char in the input string.
 *@s: the input string.
 *@c: the char to be located.
 *Return: return lenght.
 */
char *_strchr(char *s, char c)
{
	do {
		if (*s == c)
			return (s);
	} while (*s++ != '\0');

	return (NULL);
}
