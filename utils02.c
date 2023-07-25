#include "shell.h"
/**
 * _strdup - returns a pointer to a newly allocated
 * space in memory, which contains a copy.
 * of the string given as a parameter.
 * @s: input string.
 * Return: pointer to duplicated string.
 */
char *_strdup(char *s)
{
	int j = 0;
	char *a;

	if (s == NULL)
		return (NULL);
	while (*s++)
		j++;
	/**
	 *  valgrind error here a should be freed later
	 */
	a = malloc((j + 1));
	/** memory leak error when trying to create memory
	 * of an already freed env
	 */
	if (!a)
		return (NULL);
	for (j++; j--;)
		a[j] = *--s;
	return (a);
}
/**
 * _printd - prints a decimal.
 * @fd: the input filed escriptor.
 * @a: the input value.
 * Return: ...
 */
int _printd(int fd, int a)
{
	int i, r = 0;
	unsigned int n, m;
	int (*_putchars)(char) = _putchar;

	if (fd == STDERR_FILENO)
		_putchars = _putchar;
	if (a < 0)
	{
		n = -a;
		_putchars('-');
		r++;
	}
	else
		n = a;
	m = n;
	for (i = 1000000000; i > 1; i /= 10)
	{
		if (n / i)
		{
			_putchars('0' + m / i);
			r++;
		}
		m %= i;
	}
	_putchars('0' + m);
	r++;
	return (r);
}
/**
 * _atoie - converts a string of to int.
 * @s: the input string.
 * Return: the value.
 */
int _atoi(char *s)
{
	int i = 0;
	unsigned long int r = 0;

	if (*s == '+')
		s++;
	for (i = 0;  s[i] != '\0'; i++)
	{
		if (s[i] >= '0' && s[i] <= '9')
		{
			r *= 10;
			r += (s[i] - '0');
			if (r > INT_MAX)
				return (-1);
		}
		else
			return (-1);
	}
	return (r);
}
/**
 * _strcmp - compares two string.
 * @s1: first string.
 * @s2: second string.
 * Return: 0: equal, negative: s1 smaller than s2
 * positive: bigger
 */
int _strcmp(char *s1, char *s2)
{
	int i, a = 0, b = 0, l1, l2;

	l1 = _strlen(s1);
	l2 = _strlen(s2);
	if (l1 < l2)
		l1 = l2;
	for (i = 0; i < l1; i++)
		if (s1[i] != s2[i])
		{
			a = s1[i];
			b = s2[i];
			break;
		}
	return (a - b);
}
/**
 * _strtows - splits a string into words
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
	if (e == 0)
		return (NULL);
	r = malloc(sizeof(char *) * (e + 1));
	if (r == NULL)
		return (NULL);
	for (a = 0, b = 0; b < e; b++)
	{
		c = 0;
		while (inDlm(s[a], sd))
			a++;
		while (!inDlm(s[a + c], sd) && s[a + c])
			c++;
		r[b] = malloc(sizeof(char) * (c + 1));
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
