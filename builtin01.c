#include "shell.h"
/**
 * biExit - exits the shell with a status.
 * @ar: the struct of args of shell.
 *  Return: exit status.
 */
int biExit(l_ar *ar)
{
	int r;

	if (ar->argv[1])
	{
		r = _atoi(ar->argv[1]);
		if (r != -1)
		{
			/** the number of the exist value is saved*/
			ar->nerr = r;
			return (-2);
		}
		ar->st = 2;
		_puts(ar->filename);
		_puts(": ");
		_printd(STDERR_FILENO, ar->iline);
		_puts(": ");
		_puts(ar->argv[0]);
		_puts(": Illegal number: ");
		_puts(ar->argv[1]);
		_putchar('\n');
		return (1);
	}
	/** if no exit value is given*/
	ar->nerr = -1;
	return (-2);
}
