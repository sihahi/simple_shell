#include "shell.h"

/**
 * _strncpy -  function that copies a string
 * @dest: destination pointer input
 * @src: source pointer input
 * @n: byte number
 * Return: @dest
 */

char *_strncpy(char *dest, char *src, int n)
{
	int i;

	for (i = 0; i < n && src[i] != '\0'; i++)
		dest[i] = src[i];
	while (i < n)
	{
		dest[i] = '\0';
		i++;
	}
	return (dest);
}

/**
 * _strncat - function that concatenates two strings
 * @dest: destination pointer input
 * @src: source pointer input
 * @n: byte number
 * Return: pointer to the resulting string dest
 */

char *_strncat(char *dest, char *src, int n)
{
	int c, c1;

	c = 0;
	while (dest[c])
		c++;
	for (c1 = 0; c1 < n && src[c1] != '\0'; c1++)
		dest[c + c1] = src[c1];
	dest[c + c1] = '\0';
	return (dest);
}

/**
 * *_strchr _ locates a charachter in string
 * @s: the string to be parsed
 * @c: tha character to look for
 * Return: (s) a pointer to the memory area s
 */
char *_strchr(char *s, char c)
{
	do {
		if (*s == c)
			return (s);
	} while (*s++ != '\0');
	return (NULL);
}
