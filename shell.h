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
extern char **environ;
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
char *nocomment(char *s);

/* void n_i_mode(char **argv, l_u *e);*/
/*-----------utils01.c-----------*/
void _handler_ctrlc(int n);
void pnewline(char *s);
char *dnewline(char *s);
ssize_t checkcounter(ssize_t c);
void exitnewline(char **tk, l_u *e, char *s, ssize_t fd);

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

/*-----------utils05.c-----------*/
l_u *add_nod(l_u **head, char *s1, char *s2);
ssize_t _getlinev2(char **s, int sf);
char *_strdup(char *s);
char *comb(char *b, char *s);

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
int _setenv(char *s, char *c, l_u **e);
int _getidxenv(char *s, l_u *e);

/*-----------builtin01.c-----------*/
int _bi_exit(char **tk, l_u *e);
int _bi_env(l_u *e);
int _bi_cd(char **tk, l_u *e);
int cdex(char *a, char *b, char *s, l_u *e);
char *cddir(char *b, char *s);

#endif
