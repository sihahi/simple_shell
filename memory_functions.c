#include "shell.h"

/**
 * _memset - function that fills memory with a constant byte
 * @s: the adresse of memory to print
 * @b: character
 * @n: the size of the memory to print
 * Return: pointer s
 */

char *_memset(char *s, char b, unsigned int n)
{
	unsigned int size;

	for (size = 0; n > 0; size++, n--)
	{
		s[size] = b;
	}

	return (s);
}

/**
 * ffree - free a string of strings
 * @pp: string of strings
 */

void ffree(char **pp)
{
	char **a = pp;

	if (!pp)
		return;
	while (*pp)
		free(*pp++);
	free(a);
}

/**
 * *_realloc - .......
 * @ptr: hghfguj
 * @old_size: ljgg
 * @new_size: khgyfd
 * Return: pointer
 */

void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	char *p;

	if (!ptr)
		return (malloc(new_size));
	if (!new_size)
		return (free(ptr), NULL);
	if (new_size == old_size)
		return (ptr);

	p = malloc(new_size);
	if (!p)
		return (NULL);
	old_size = old_size < new_size ? old_size : new_size;
	while (old_size--)
			p[old_size] = ((char *)ptr)[old_size];
			free(ptr);
			return (p);
}

