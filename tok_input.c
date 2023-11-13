#include "main.h"

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
	char *copy_str = NULL;
	char *token;
	char **arr = NULL;
	int i, words = 0;

	copy_str = malloc(sizeof(char) * n);
	if (copy_str == NULL)
	{
		perror("Error ");
		return (NULL);
	}
	_strcpy(copy_str, s);
	token = strtok(s, d);
	while (token)
	{
		words++;
		token = strtok(NULL, d);
	}
	words++;
	arr = malloc(sizeof(char *) * words);
	token = strtok(copy_str, d);
	for (i = 0; token != NULL; i++)
	{
		arr[i] = malloc(sizeof(char) * _strlen(token));
		_strcpy(arr[i], token);
		token = strtok(NULL, d);
	}
	arr[i] = NULL;
	free(copy_str);

	return (arr);
}
