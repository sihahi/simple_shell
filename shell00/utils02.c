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
 * _strcpy - copy the string
 * @dest: destination of the string
 * @src: souece of the string
 * Return: copied string
 */
char *_strcpy(char *dest, char *src)
{
	int l, i;

	l = _strlen(src);

	for (i = 0; i <= l; i++)
	{
		dest[i] = src[i];
	}
	return (dest);
}
/**
 * _getline - ...
 * @s: ...
 * @sf: ...
 * Return: ...
 */
ssize_t _getline(char **s, int sf)
{
	ssize_t r, fd = 1, len = BUF_SIZE, i = 0, j = 0, k = 0;
	static ssize_t counter;
	char *buffer;

	counter = checkcounter(counter);
	if (counter == -1)
		return (-1);
	/* buffer = malloc(sizeof(char) * (len + 1));*/
	buffer = (char *)_calloc((len + 1), sizeof(char));
	if (buffer == NULL)
		return (-1);
	while (j == 0 && k == 0)
	{
		fd = read(sf, buffer, len);
		if (fd == -1)
		{
			free(buffer);
			return (-1); }
		if (counter == 0 && fd == 0)
			return (0);
		if (counter == 0 && fd != 0)
			counter += fd;
		if (counter != 0 && fd == 0)
		{
			counter++;
			j = 1; }
		while (buffer[i] != '\0')
		{
			if (buffer[i] == '\n')
				k = 1;
			i++; }
	}
	if (counter > len)
		buffer = _realloc(buffer, len + 1, counter + 1);
	buffer[counter] = '\0';
	if (*s == NULL)
	{
		*s = (char *)_calloc((counter + 1), sizeof(char));
		if (*s == NULL)
			return (-1);
	}
	_strcpy(*s, buffer);
	free(buffer);
	r = counter;
	counter = 0;
	return (r);
}

/**
 * _realloc - reallocates a memory block using malloc and free.
 * @ptr: pointer to the memory previously allocated.
 * @old_size: size of space of ptr.
 * @new_size: new size of the new memory.
 * Return: pointer.
 */

void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	unsigned int i;
	void *p;

	if (new_size == 0 && ptr != NULL)
	{
		free(ptr);
		return (NULL);
	}
	if (ptr == NULL)
	{
		/* ptr = malloc(new_size);*/
		ptr = (char *)_calloc(new_size, sizeof(char));
		if (ptr == NULL)
			return (NULL);
		return (ptr);
	}
	if (new_size == old_size)
		return (ptr);
	if (new_size > old_size)
	{
		i = 0;
		/*p = malloc(new_size);*/
		p = (char *)_calloc(new_size, sizeof(char));
		if (p == NULL)
			return (NULL);
		while (i < old_size)
		{
			((char *)p)[i] = ((char *)ptr)[i];
			i++;
		}
		free(ptr);
		return (p); }
	/* p = malloc(new_size);*/
	p = (char *)_calloc(new_size, sizeof(char));
	if (p == NULL)
		return (NULL);
	while (i < new_size)
	{
		((char *)p)[i] = ((char *)ptr)[i];
		i++;
	}
	free(ptr);
	return (p);
}
