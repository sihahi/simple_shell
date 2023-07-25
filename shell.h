#ifndef _SHELL_H_
#define _SHELL_H_

#include <errno.h>
#include <fcntl.h>
#include <limits.h>
#include <signal.h>
#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <unistd.h>

#define BUFFER_SIZE 1024
#define CUSTOM_GETLINE 0
#define EXIT_VALUE 127

/**
 * using instead of env in main()
 * extern char **environ; is POSIX standard.
*/
extern char **environ;

/**
 * struct list_s - linked list used for env and.
 * @n: ...
 * @s: ...
 * @next: the next node.
*/
typedef struct list_s
{
int n;
char *s;
struct list_s *next;
} l_s;


/**
 * struct list_args - linked list of args of shell.
 * @arg: ...
 * @argc: the number of arguments.
 * @argv: the list of arguments.
 * @file_in: ...
 * @env: the list of environment values.
 * @iline: ...
 * @nerr: the code of exit (used in builtin exit).
 * @st: the return statue.
 * @filename: the filename entered in cmd.
 * @path: the path of the command.
 * @iflag: conut line?
 * @envr: duplicate of env.
 * @dif_env: ...
 * @tcmd: ...
 * @bcmd: ...
 */
typedef struct list_args
{
char *arg;
int argc;
char **argv;
int file_in;
l_s *env;
unsigned int iline;
int nerr;
int st;
char *filename;
char *path;
int iflag;
char **envr;
int dif_env;
int tcmd;
char **bcmd;
} l_ar;

/* main.c*/
int fileCom(l_ar *ar, char **av);
int prompt(l_ar *ar, char **av);
int isBuiltin(l_ar *ar);
int checkCom(l_ar *ar, char **av);

/* utils01.c*/
int _strlen(char *s);
int _putchar(char c);
void _puts(char *s);
l_s *add_node_end(l_s **head, char *s);
void *_calloc(unsigned int nmemb, unsigned int size);

/* utils02.c*/
char *_strdup(char *s);
int _printd(int fd, int a);
int _atoi(char *s);
int _strcmp(char *s1, char *s2);
char **_strtok(char *s, char *sd);

/* utils03.c*/
int getLenTok(char *s, char *sd);
int inDlm(char c, char *ds);
int changeVal(l_ar *ar);
int changeStr(char **s1, char *s2);
char *_itoa(long int n, int b, int f);

/* utils04.c*/
l_s *getNodeOf(l_s *l, char *s, char c);
char *getAddressStr(char *s, char c);
char *getInPath(l_ar *ar, char *ps, char *s);
char *_strbg(const char *a, const char *b);
char *pathDup(char *s, int a, int b);

/* utils05.c*/
char *_strcat(char *s1, char *s2);
char **getArray(l_s *head);
char *_strcpy(char *s1, char *s2);
void freeArgShell(l_ar *ar);
void freeAllArgShell(l_ar *ar);

/* utils06.c*/
void freeList(l_s **head);
void handleSignal(__attribute__((unused))int n);
void deleteCom(char *s);
ssize_t treat(l_ar *ar, char *buffer, char **ptr,
size_t i, size_t j, size_t len);
int delimiterExesit(l_ar *ar, char *s, size_t *n);

/* utils07.c*/
int getlineCus(l_ar *ar, char **s, size_t *len);
char *_strchr(char *s, char c);

/* environment.c */
int initEnv(l_ar *ar);
char *getEnvv(l_ar *ar, const char *s);

/* command.c */
void isInPath(l_ar *ar);
void _fork(l_ar *ar);
ssize_t readLine(l_ar *ar);
int _getline(l_ar *ar, char **s, size_t *len);

/* builtin01.c*/
int biExit(l_ar *ar);
#endif
