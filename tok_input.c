#include "main.h"

/**
 * _strtok - tokenize input string into words.
 *
 * Description: A function that tokenize
 * input string into words depend on delimeter.
 * @line: input string from user.
 * @delim: separator betwwen words.
 *
 * Return: pointer to word of string.
 **/
char *_strtok(char *line, const char *delim)
{
	return (strtok(line, delim));
}

/**
 * tok_input -  divide input string.
 *
 * Description: A function that tokanize input string.
 * @s: input string.
 * @d: delimeter, separated between input variables.
 * @n: number of chars entered by user.
 *
 * Return: pointer to array of tokanize words.
 **/
char **tok_input(char *s, char *d, ssize_t n)
{
	char *copy_str = NULL, *token, **arr = NULL;
	int i, words = 0;

	copy_str = malloc(sizeof(char) * n);
	if (copy_str == NULL)
	{
		free(copy_str);
		return (NULL);
	}
	_strcpy(copy_str, s);
	token = _strtok(s, d);
	while (token)
	{
		words++;
		token = _strtok(NULL, d);
	}
	words++;
	arr = malloc(sizeof(char *) * words);
	if (arr == NULL)
	{
		perror("Error ");
		free(arr);
		return (NULL);
	}
	token = _strtok(copy_str, d);
	for (i = 0; token != NULL; i++)
	{
		arr[i] = malloc(sizeof(char) * _strlen(token));
		if (arr[i] == NULL)
		{
			perror("Error ");
			return (NULL);
		}
		_strcpy(arr[i], token);
		token = _strtok(NULL, d);
	}
	arr[i] = NULL;
	free(copy_str);
	return (arr);
}
