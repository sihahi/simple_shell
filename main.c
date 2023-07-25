#include "shell.h"

/**
 * fileCom - saves the command in the file in
 * the list of shell args.
 * @ar: the list of shell envirnment.
 * @av: the list of arguments in main.
 * Return: ...
 */
int fileCom(l_ar *ar, char **av)
{
	int file_in;

	file_in = open(av[1], O_RDONLY);
	if (file_in == -1)
	{
		if (errno == ENOENT)
		{
			_puts(av[0]);
			_puts(": 0: Can't open ");
			_puts(av[1]);
			_putchar('\n');
			_putchar(-1);
			exit(EXIT_VALUE);
		}
		if (errno == EACCES)
			exit((EXIT_VALUE - 1));
		return (1);
	}
	ar->file_in = file_in;
	return (0);
}
/**
 * prompt - prompts shell.
 * @ar: the struct list_ar.
 * @av: the list of arguments in main.
 * Return: 0 on success.
 */
int prompt(l_ar *ar, char **av)
{
	int r = 0, a;
	ssize_t n = 0;

	a = ((ar->file_in <= 2) && (isatty(STDIN_FILENO)));
	while (r != -2 && n != -1)
	{
		ar->arg = NULL;
		ar->argc = 0;
		ar->argv = NULL;
		ar->path = NULL;
		if (a)
			_puts("$ ");
		_putchar(-1);
		n = readLine(ar);
		if (n != -1)
		{
			r = checkCom(ar, av);
		}
		else if (a != 0)
			_putchar('\n');
		printf("here\n");
		freeArgShell(ar);
	}
	freeAllArgShell(ar);
	if (!a && ar->st)
		exit(ar->st);
	if (r == -2)
	{
		if (ar->nerr != -1)
		{
			exit(ar->nerr);
		}
		exit(ar->st);
	}
	return (r);
}
/**
 * checkCom - checks if command builtin or in path.
 * @ar: the struct list_ar.
 * @av: the list of arguments in main.
 * Return: ...
 */
int checkCom(l_ar *ar, char **av)
{
	int r = 0, i = 0;

	ar->filename = av[0];
	if (ar->arg)
	{
		ar->argv = _strtok(ar->arg, " \t");
		if (!ar->argv)
		{
			ar->argv = malloc(sizeof(char *) * 2);
			if (ar->argv == NULL)
				return (-1);
			if (ar->argv)
			{
				ar->argv[0] = _strdup(ar->arg);
				ar->argv[1] = NULL;
			}
		}
		for (i = 0; ar->argv && ar->argv[i]; i++)
			;
		ar->argc = i;
		changeVal(ar);
	}
	r = isBuiltin(ar);
	if (r == -1)
		isInPath(ar);
	return (r);
}
/**
 * isBuiltin - searches if command is builtin.
 * @ar: the stuct of args list_ar.
 * Return: 0 on success other -1.
 */
int isBuiltin(l_ar *ar)
{
	int r = -1;

	if (ar->argv[0] == NULL)
		return (-1);
	if (!_strcmp(ar->argv[0], "exit"))
	{
		ar->iline++;
		r = biExit(ar);
	}
	return (r);
}
/**
 * main - main entry function.
 * @argc: the number of arguments.
 * @argv: the list of arguments.
 * Return: 0 on success.
 */
int main(int argc, char **argv)
{
	int file_in, r;
	l_ar ar[] = {
		{
			NULL, 0, NULL, 0,
			NULL, 0, 0, 0, NULL,
			NULL, 0, NULL, 0, 0, NULL
		}};

	file_in = 2;
	asm ("mov %1, %0\n\tadd $3, %0" : "=r" (file_in) : "r" (file_in));
	if (argc == 2)
	{
		r = fileCom(ar, argv);
		if (r != 0)
			return (r);
	}
	initEnv(ar);
	prompt(ar, argv);
	return (0);
}
