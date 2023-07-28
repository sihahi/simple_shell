<<<<<<< HEAD
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

/* command chaine */

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
#define HIST_FILE      “.simple_shell_history”
#define HIST_MAX    4096

/* string_functions.c */
int _strlen (char *);
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

/*string_functions4.c */
char **strtow(char *);

#endif
=======
#ifndef _SHELL_H_
#define _SHELL_H_

#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <unistd.h>
#include <errno.h>
#define BUF_SIZE 1024
#define CUSTOM_GETLINE 1

/**
 * struct list_u - linked list.
 * @s1: the first variable.
 * @s2: the second variabe.
 * @next: the next node.
 */
typedef struct list_u
{
	char *s1;
	char *s2;
	struct list_u *next;

} l_u;
/* global variables*/
/* extern l_u *a; */



/*-----------shell.c-----------*/
void i_mode(l_u *e);
/* void n_i_mode(char **argv, l_u *e);*/
/*-----------utils01.c-----------*/
void _handler_ctrlc(int n);
void pnewline(char *s);
char *dnewline(char *s);
ssize_t checkcounter(ssize_t c);

/*-----------utils02.c-----------*/
int _strlen(char *s);
char *_strcpy(char *dest, char *src);
ssize_t _getline(char **s, int sf);
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);

/*-----------utils03.c-----------*/
int _putchar(char c);
void _puts(char *s);
char *_strcat(char *dest, char *src);
int _strcmp(char *s1, char *s2);
void freel(l_u *head);

/*-----------utils04.c-----------*/
char *isinpath(char *s, l_u *e);
char *inpath(char *s1, char *s2);
l_u *add_node(l_u **head, char *s1, char *s2);
int _atoi(char *s);
void *_calloc(unsigned int nmemb, unsigned int size);

/*-----------token.c-----------*/
char **_strtok(char *s, char *sd);
void _freetok(char **tk);
int getLenTok(char *s, char *sd);
int inDlm(char c, char *ds);

/*-----------command.c-----------*/
int isbuiltin(char **token, l_u *e);
void isexecute(char **tk, l_u *e);

/*-----------environment.c-----------*/
l_u *_getenv(char **env);
char *_getenvval(char *s, l_u *e);
char **_lenv(l_u *e);

/*-----------builtin01.c-----------*/
int _bi_exit(char **tk);
int _bi_env(l_u *e);

#endif


>>>>>>> d81d9d7c31e2e3ae615e4566a4824c7a79a33f37
