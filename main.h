#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <string.h>

extern char **environ;

ssize_t getline(char **lineptr, size_t *n, FILE *stream);
void start_shell(char *start_sympole, char *delimeter);
int num_words(char *str, char *delimeter);
char **tokenize_input(char *str, char *delimeter);
void execute_commands(char **split_data);
char *_getenv(const char *name);
void show_env(void);
int _strlen(char *str);
int _strcmp(char *str1, char *str2);
int _strncmp(const char *str1, const char *str2, size_t n_cmp);
char **tok_input(char *s, char *d, ssize_t n);
int split_len(char *s, char *d);
int split_len(char *s, char *d);
char *_strcpy(char *dest, char *src);
char *_strtok(char *line,const char *delim);
int check_command(char **split_data);
char *_which(char *x);
char *str_concat(char *s1, char *s2);

#endif
