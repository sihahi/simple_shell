#include "shell.h"
/**
 * getLenTok - ...
 * @s: the string.
 * @sd: the string delimeter.
 * Return: length.
 */
int getLenTok(char *s, char *sd)
{
	int a, b, c, l = 0;

	for (a = 0; s[a] != '\0'; a++)
	{
		b = inDlm(s[a], sd);
		c = inDlm(s[a + 1], sd);
		if (!b && (!s[a + 1] || !c))
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
/**
 * changeVal - changes value of special variables.
 * @ar: ...
 * @s: the string input.
 * Return: 1 if replaced, 0 otherwise
 */
int changeVal(l_ar *ar)
{
	int i = 1;
	l_s *l;

	for (i = 0; ar->argv[i]; i++)
	{
		if (ar->argv[i][0] != '$' || !ar->argv[i][1])
			continue;
		if (!_strcmp(ar->argv[i], "$$"))
		{
			changeStr(&(ar->argv[i]), _strdup(_itoa(getpid(), 10, 0)));
			continue;
		}
		if (!_strcmp(ar->argv[i], "$?"))
		{
			changeStr(&(ar->argv[i]), _strdup(_itoa(ar->st, 10, 0)));
			continue;
		}
		l = getNodeOf(ar->env, &ar->argv[i][1], '=');
		if (l)
		{
			changeStr(&(ar->argv[i]), _strdup(getAddressStr(l->s, '=') + 1));
			continue;
		}
		changeStr(&ar->argv[i], _strdup(""));
	}
	return (0);
}
/**
 * changeStr - changes the value of a string with another.
 * @s1: the old string pointer.
 * @s2: the new string.
 * Return: 1 success, else 0.
 */
int changeStr(char **s1, char *s2)
{
	free(*s1);
	*s1 = s2;
	return (1);
}
/**
 * _itoa - convertes int to a given baese.
 * @n: the input number.
 * @b: the input base.
 * @f: the appropriate flags.
 * Return: ...
 */
char *_itoa(long int n, int b, int f)
{
	static char *t, buffer[50];
	char *p, sign = 0;
	unsigned long num = n;

	if (!(f & 2) && n < 0)
	{
		num = -n;
		sign = '-';

	}
	if (!(f & 1))
		t = "0123456789ABCDEF";
	else
		t = "0123456789abcdef";
	p = &buffer[(50 - 1)];
	*p = '\0';
	do	{
		*--p = t[num % b];
		num /= b;
	} while (num != 0);

	if (sign)
		*--p = sign;
	return (p);
}
