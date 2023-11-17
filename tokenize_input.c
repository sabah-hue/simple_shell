#include "main.h"

/**
 * tokenize_input - divided the input string into words
 *
 * Description: Function that recive a string and divided into words.
 *
 * @str: input string.
 * @delimeter: separator between words of string.
 *
 * Return: a pointer to an 2D array holds the words of string, NULL in faill.
 **/
char **tokenize_input(char *str, char *delimeter)
{
	char **input_data = NULL, *str_cpy = NULL, *first_word = NULL;
	int i = 0, words = 0;

	if (!delimeter)
		delimeter = " ";
	if (str == NULL)
		return (NULL);
	str_cpy = strdup(str);/* copied input string*/
	first_word = _strtok(str_cpy, delimeter);
	while (first_word)
	{
		words++;
		first_word = _strtok(NULL, delimeter);
	}
	free(str_cpy);
	/*M-alloc for row-2d-arr*/
	if (words == 0)
		return (NULL);
	input_data = malloc(sizeof(char *) * (words + 1));
	if (input_data == NULL)
		return (NULL);
	first_word = _strtok(str, delimeter);
	while (first_word)
	{
		input_data[i] = first_word;
		first_word = _strtok(NULL, delimeter);
		i++;
	}
	input_data[i] = NULL;
	return (input_data);
}
