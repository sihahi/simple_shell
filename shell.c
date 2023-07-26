#include "shell.h"
/* void n_i_mode(char **argv, l_u *e){} */
/**
 * i_mode - ...
 * @e: ...
 */
void i_mode(l_u *e)
{
	char *line, **tk;
	ssize_t fd;
	size_t len;
	int r, num_com = 0;

	while (1)
	{
		line = NULL;
		tk = NULL;
		fd = 0;
		len = 0;
		num_com++;
		if (isatty(STDIN_FILENO))
			write(STDOUT_FILENO, "$ ", 2);
		signal(SIGINT, _handler_ctrlc);
#if CUSTOM_GETLINE
		fd = getline(&line, &len, stdin);
#else
		fd = _getline(&line, STDOUT_FILENO);
#endif
		if (fd == -1 || fd == 0)
		{
			pnewline(line);
			exit(fd);
		}
		if (line[0] == '\0')
		{
			continue;
		}
		line = dnewline(line);
		tk = _strtok(line, " ");
		r = isbuiltin(tk, e);
		if (r != 1)
			isexecute(tk, e);
	}
	free(line);
	_freetok(tk);
	free(tk);
}
