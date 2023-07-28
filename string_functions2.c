#include "shell.h"


/**
 * *_strcpy - function that copies the string pointed
 * @dest: char type string
 * @src: char type string
 * Return: pointer to dest
 */

char *_strcpy(char *dest, char *src)
{
	int i = -1;

	do {
		i++;
		dest[i] = src[i];
	} while (src[i] != '\0');

	return (dest);
}

/**
 * *_strdup - function that returns a pointer to a
 * newly allocated space in memory,
 * which contains a copy of the string given as a parameter
 * @str: string
 * Return: pointer to the duplicated string
 * or NULL  if insufficient memory was available
 */

char *_strdup(const char *str)
{
	int i = 0, size = 0;
	char *m;

	if (str == NULL)
		return (NULL);

	for (; str[size] != '\0'; size++)
	;

	m = malloc(size * sizeof(*str) + 1);

	if (m == 0)
		return (NULL);

	else
	{
		for (; i < size; i++)
			m[i] = str[i];
	}
	return (m);
}

/**
 * _puts - function that prints a string, followed by a new line, to stdout
 *
 * @str: string parameter to print
 *
 * Return: nothing
 */

void _puts(char *str)
{
	while (*str != '\0')
	{
		_putchar(*str + 0);
		str++;
	}
	_putchar('\n');
}

/**
 * _putchar - write the character c to stdout
 * @c: tha character to print
 *
 * Return: 1 (success)
 */

int _putchar(char c)
{
	return (write(1, &c, 1));
}
