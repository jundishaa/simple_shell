#ifndef SHELL_H
#define SHELL_H

#include <sys/stat.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

/**
 * struct builtin_s - this code is about
 *Structure for builtin commands
 *
 * @cmd: this is The member of the
 *structure which is the  command's name
 *
 * @f: this one is the appropriate
 *function to act on command
 *Description: this is structure for command
 */
typedef struct builtin_s
{
	char *cmd;
	int (*f)(char **, int, char *);
} builtin_s;


/* macros */
#define BUFSIZE 1024
#define TRUE 1
#define FALSE 0

  /* global */
extern char **environ;

/* In new_shell_prompt.c */
void  new_prompt(void);

/* In run.c */
int run(char **command, char *source);

/* In customs.c */
int _strlen(const char *s);
char *_strstr(char *haystack, char *needle);
char *_strcpy(char *target, const char *source);
char *_strcat(char *target, const char *source);
int _strcmp(char *str1, char *str2);


/* In putchar.c */
int _putchar(int c);
int print(char *str);


/* In tokinizer.c */
char *no_newline(char *input);
char **tokinize(char *input);
char *command_path(char *command_name, char *dir);
int verify_cmd_path(char **command);

/* In environment.c */
char *_getenv(const char *jund);

/* In memory.c */
void free_memory_p(char *);
void free_memory_pp(char **);
int cmp(const char *str1, const char *str2);
int _atoi(char *s);
int _isalpha(char a);

/* In builtinscom.c */
int exit_func(char **, int, char *);
int env_func(char **, int, char *);
builtin_s find_builtin(char *cmd);
int (*look_builtins(char **))(char **, int, char *);

/* In newstr.c */
char *_strdup(char *str);


#endif

