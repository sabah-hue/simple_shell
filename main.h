#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>

ssize_t getline(char **lineptr, size_t *n, FILE *stream);
void start_shell(char *start_sympole);
int _strlen(char *str);
int num_words(char *str, char *delimeter);
char **tokenize_input(char *str, char *delimeter);

#endif
