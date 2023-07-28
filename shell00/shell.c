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
	/* size_t len;*/
	int r, num_com = 0;

	while (1)
	{
		line = NULL;
		tk = NULL;
		fd = 0;
		/*len = 0;*/
		num_com++;
		if (isatty(STDIN_FILENO))
			write(STDOUT_FILENO, "$ ", 2);
		signal(SIGINT, _handler_ctrlc);
#if CUSTOM_GETLINE
		fd = getline(&line, &len, stdin);
#else
		/*fd = _getline(&line, STDOUT_FILENO);*/
		fd = _getlinev2(&line, STDOUT_FILENO);
#endif
		exitnewline( tk, e, line, fd);
		if (line[0] == '\0')
		{
			free(line);
			_freetok(tk);
			continue; }
		line = dnewline(line);
		tk = _strtok(line, " ");
		r = isbuiltin(tk, e);
		free(line);
		if (r == 1)
		{
			_freetok(tk);
			continue; }
		isexecute(tk, e); }
	free(tk);
}
