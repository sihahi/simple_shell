#include "shell.h"
/**
 * isInPath - finds in path the command.
 * @ar: the struct of arg of the shell.
 */
void isInPath(l_ar *ar)
{
	int i, j;
	char *path = NULL, *s = " \t\n";
	struct stat st;

	ar->path = ar->argv[0];
	if (ar->iflag)
	{
		ar->iline++;
		ar->iflag = 0; }
	for (i = 0, j = 0; ar->arg[i]; i++)
	{
		while (*s)
		{
			if (*s++ == ar->arg[i])
				continue;
			j++; }
	}
	if (!j)
		return;
	path = getInPath(ar, "PATH=", ar->argv[0]);
	if (path)
	{
		ar->path = path;
		_fork(ar); }
	else
	{
		if ((ar->file_in <= 2 && isatty(STDIN_FILENO))
		|| getEnvv(ar, "PATH=") || ar->argv[0][0] == '/')
		{
			if (!ar->argv[0] || stat(ar->argv[0], &st))
				;
			else
				if (st.st_mode & S_IFREG)
					_fork(ar); }
		else if (*(ar->arg) != '\n')
		{
			ar->st = EXIT_VALUE;
			_puts(ar->filename);
			_puts(": ");
			_printd(STDERR_FILENO, ar->iline);
			_puts(": ");
			_puts(ar->argv[0]);
			_puts(": not found\n"); }}
}
/**
 * _fork - forks to run command
 * @ar: the struct of arg of the shell.
 */
void _fork(l_ar *ar)
{
	pid_t child;

	child = fork();
	if (child == -1)
	{
		perror("Error:");
		return;
	}
	if (child != 0)
	{
		wait(&(ar->st));
		if (WIFEXITED(ar->st))
		{
			ar->st = WEXITSTATUS(ar->st);
			if (ar->st == (EXIT_VALUE - 1))
			{
				_puts(": ");
				_printd(ar->iline, STDERR_FILENO);
				_puts(": ");
				_puts(ar->argv[0]);
				_puts(": Permission denied\n");
			}
		}
	}
	else
	{
		if (ar->dif_env || !ar->envr)
		{
			ar->dif_env = 0;
			ar->envr = getArray(ar->env);
		}
		if (execve(ar->path, ar->argv, ar->envr) == -1)
		{
			freeAllArgShell(ar);
			if (errno == EACCES)
				exit((EXIT_VALUE - 1));
			exit(1);
		}
	}
}
/**
 * readLine - gets the line without \n.
 * @ar: the struct of arg of the shell.
 * Return: ...
 */
ssize_t readLine(l_ar *ar)
{
	static size_t i, j, len;
	size_t lenl;
	ssize_t r = 0;
	char **ptr = &(ar->arg);
	static char *buffer;

	j = i;
	if (!len)
	{
		free(buffer);
		buffer = NULL;
		signal(SIGINT, handleSignal);
		r = _getline(ar, &buffer, &lenl);
		if (r > 0)
		{
			if ((buffer)[r - 1] == '\n')
			{
				(buffer)[r - 1] = '\0';
				r--;
			}
			deleteCom(buffer);
			ar->iflag = 1;
		}
	}
	_putchar(-1);
	if (r == -1)
		return (-1);
	if (len)
		return (treat(ar, buffer, ptr, i, j, len));
	*ptr = buffer;
	return (r);
}
/**
 * _getline - redirects to the convient getline.
 * @ar: the struct of args of shell.
 * @s: ...
 * @len: length.
 * Return: ...
 */
int _getline(__attribute__((unused))l_ar *ar, char **s, size_t *len)
{
	ssize_t r = 0;

#if CUSTOM_GETLINE
	r = getlineCus(ar, s, len);
#else
	r = getline(s, len, stdin);
#endif
	return (r);
}

