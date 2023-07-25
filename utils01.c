#include "shell.h"
/**
 * _strlen - returns the length of a string
 * @s: input string
 * Return: length
 */

int _strlen(char *s)
{
	int l = 0;

	while (*s != '\0')
	{
		l++;
		s++;
	}

	return (l);
}
/**
 * _putchar - puts a char in output.
 * @c: The char to write.
 * Return: 1 on success.
 */
int _putchar(char c)
{
	static char buffer[BUFFER_SIZE];
	static int buffer_i;

	if (buffer_i >= BUFFER_SIZE || c ==  -1)
	{
		write(2, buffer, buffer_i);
		buffer_i = 0;
	}
	if (c != -1)
		buffer[buffer_i++] = c;
	return (1);
}
/**
 *_putse - puts a string in output.
 * @s: the string.
 */
void _puts(char *s)
{
	if (*s == '\0')
		return;
	_putchar(*s);
	s++;
	_puts(s);
}
/**
 * add_node_end - adds a node at the end of list.
 * @head: the linked list type l_s.
 * @s: the value of to save in the node.
 * Return: size of list
 */
l_s *add_node_end(l_s **head, char *s)
{
	l_s *n1, *n2;

	if (head == NULL)
		return (NULL);
	n1 = (l_s *)_calloc(1, sizeof(l_s));
	n2 = *head;
	if (s != NULL)
	{
		/**
		 * valgrind memory leak here
		 * when i free the ar->env once
		 * i can't initiliaze it again
		 */
		n1->s = _strdup(s);
		/* problem flaged above*/
		if (!n1->s)
		{
			free(n1);
			return (NULL);
		}
	}
	if (n2 != NULL)
	{
		while (n2->next)
			n2 = n2->next;
		n2->next = n1;
	}
	else
		*head = n1;
	return (n1);
}

/**
 * _calloc -  allocates memory for an array
 * and sets it to zero, using malloc.
 * @nmemb: the number of elements.
 * @size: size of byte.
 * Return: pointer to the allocated memory.
 */
void *_calloc(unsigned int nmemb, unsigned int size)
{
	char *p;
	unsigned int i, a;

	if (nmemb == 0 || size == 0)
		return (NULL);
	a = nmemb * size;
	p = malloc(a);
	if (p == NULL)
		return (NULL);
	for (i = 0; i < a; i++)
		p[i] = 0;
	return (p);
}
