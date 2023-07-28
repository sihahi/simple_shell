#include "shell.h"

/**
 * _strlen -  function that returns the length of a string
 *
 * @s: string parametre input
 *
 * Return: the length of string
 */

int _strlen(char *s)
{
	int counter;

	for (counter = 0; *s != '\0'; s++)
		++counter;

	return (counter);
}

/**
 * _strcmp - function that compares two strings
 * @s1: string input 1
 * @s2: string input 2
 * Return: 1 if true, 0 if false
 */

int _strcmp(char *s1, char *s2)
{
	int equal = 0;

	while (*s1)
	{
		if (*s1 != *s2)
		{
			equal = ((int)*s1 - 48) - ((int)*s2 - 48);
			break;
		}
		s1++;
		s2++;
	}
	return (equal);
}

/**
 * _strcat - function that concatenates two strings
 *
 * @dest: Destination pointer input
 * @src: Source pointer input
 * Return:  pointer to the resulting string @dest
 */

char *_strcat(char *dest, char *src)
{
	int c, c1;

	c = 0;
	while (dest[c])
		c++;

	for (c1 = 0; src[c1]; c1++)
		dest[c++] = src[c1];

	return (dest);
}

/**
 * starts_with - check if needle starts with haystack
 * @haystack: string to search
 * @needle: the substring to find
 * Return: address of next char of haystack or NULL
 */

char *starts_with(const char *haystack, const char *needle)
{
	while (*needle)
		if (*needle++ != *haystack++)
			return (NULL);
	return ((char *)haystack);
}

