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
