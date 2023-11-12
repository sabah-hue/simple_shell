#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>

extern char **environ;

ssize_t getline(char **lineptr, size_t *n, FILE *stream);
void start_shell(char *start_sympole, char *delimeter);
int num_words(char *str, char *delimeter);
char **tokenize_input(char *str, char *delimeter);
void run_non_interactive(void);
void execute_commands(char **split_data);
char *_getenv(const char *name);
void show_env();
int _strlen(char *str);
int _strcmp(char *str1, char *str2);
int _strncmp(const char *str1, const char *str2, size_t n_cmp);
size_t count_words(char *s, char *delimeter);
char **_strtok(char *s, char *delimeter);

#endif
