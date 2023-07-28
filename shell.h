#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <limits.h>
#include <fcntl.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>

/* read/write */

#define READ_BUF_SIZE 1024
#define WRITE_UF_SIZE 1024
#define UF_FLUSH –1

/* command _chaine */

#define CMD_NORM     0
#define CMD_OR       1
#define CMD_AND      2
#define CMD_CHAIN    3

/* convert number */

#define CONVERT_LOWERCASE    1
#define CONVERT_UNSIGNED     2

/* système getline */

#define USE_GETLINE  0
#define USE_STRRTOK  0
#define HIST_FILE   “.simple_shell_history”
#define HIST_MAX    4096

extern char **environ;

/**
 * struct liststr - syngly linked list
 * @num: hgyd
 * @str: jhydtr
 * @next: jjggd
 */
typedef struct liststr
{
	int num;
	char *str;
	struct liststr *next;
} list_t;

/**
 * struct paainfo - hyterfvndnb
 * @arg : string from getline
 * @argv: an array
 * @path: string path
 * @argc: argument count
 * @line_count: error count
 * @err_num: error code
 * @linecount_flag: hyeyffcgghd
 * @fname: programm filename
 * @env: linked list
 * @environ: custom copy of environ
 * @history: the history node
 * @alias: alias node
 * @env_changed: judydfgd
 * @status: hhdydtdg
 * @cmd_buf: jjhdtdyyu
 * @cmd_buf_type: hsgdtdgd
 * @readfd: hdyydrd
 * @histcount: hsgffdsgsh
 */
typedef struct passinfo
{
	char *arg;
	char **argv;
	char *path;
	int argc;
	unsigned int line_count;
	int err_num;
	int linecount_flag;
	char *fname;
	list_t *env;
	list_t *history;
	list_t *alias;
	char **environ;
	int env_changed;
	int status;

	char **cmd_buf;
	int cmd_buf_type;
	int readfd;
	int histcount;
} info_t;

#define INFO_INIT \
{NULL, NULL, NULL, 0, 0, 0, 0, NULL, NULL, NULL, NULL, NULL, 0, 0, NULL, \
	0, 0, 0}

/**
 * struct builtin _contains a builtin string
 * @type: builtin command flag
 * @func: function
 */
typedef struct builtin
{
	char *type;
	int (*func)(info_t *);
} builtin_table;


/* string_functions.c */
int _strlen(char *);
int _strcmp(char *, char *);
char *starts_with(const char *, const char *);
char *_strcat(char *, char *);

/* string_functions2.c */
char *_strcpy(char *, char *);
char *_strdup(const char *);
void _puts(char *);
int _putchar(char);

/* string_functions3.c */
char *_strncpy(char *, char *, int);
char *_strncat(char *, char *, int);
char *_strchr(char*, char);

/* string_functions4.c */
char **strtow(char *);

/* memory_functions.c */
char *_memset(char *s, char b, unsigned int n);
void ffree(char **pp);
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);

/* memory_functions2.c */
int bfree(void **ptr);

/* more_functions.c */
int _atoi(char *s);
int is_delim(char c, char *delim);
int interactive(info_t *info);
int _isalpha(int c);

/* info.c */
void free_info(info_t *info, int all);
void set_info(info_t *info, char **av);
void clear_info(info_t *info);

/* main.c */
int main(int ac, int **av);

#endif
