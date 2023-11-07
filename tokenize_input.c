#include "main.h"

/**
 * num_words - get the number of words in a given string.
 *
 * Description: Function that calculate the number of words in string.
 * @str: String, input parameter.
 * @delimeter: Separator character between words..
 *
 * Return: Number of words, -1 if the string is NULL.
 **/
int num_words(char *str, char *delimeter)
{
	int i, j, str_len = 0, words = 0, word_len;

	if (str == NULL)
		return (-1);

	for (i = 0; str[i] != '\0'; i++)
		str_len++;
	for (j = 0; j < str_len; j++)
	{
		if (str[j] != *delimeter)
		{
			words++;
			word_len = 0;
		while (str[j + word_len] && str[j + word_len] != *delimeter)
			word_len++;
		j = j + word_len;
		}
	}
	return (words);
}

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
	char **input_data = NULL;
	int i, j, count, n, word_len, z = 0, x_len = 0;

	if (str == NULL || num_words(str, delimeter) == 0)
		return (NULL);
	n = num_words(str, delimeter); /*memory allocation for number of words*/
	input_data = malloc(sizeof(char *) * (n + 2));
	if (input_data == NULL)
		return (NULL);
	for (i = 0; i < n; i++)
	{
		for (; str[j] == *delimeter || str[j]  == '\0';) /*stop at end of each word*/
			j++;
		z = j;
		for (; *(str + z) && *(str + z) != *delimeter;)
		{
			x_len++, z++;
		}
			word_len = x_len;
			x_len = 0; /*M-alloc for row-2d-arr*/
		input_data[i] = malloc(sizeof(char) * (word_len + 1));
		if (input_data[i] == NULL)
		{
			j = j - 1;
			while (j >= 0)
			{
				free(input_data[j]), j--;
			}
			free(input_data);
			return (NULL);
		}
		for (count = 0; count < word_len; count++)
		{
			input_data[i][count] = str[j], j++;
		}
		input_data[i][count] = '\0';
	}
	input_data[i] = NULL;
	input_data[i + 1] = NULL;
	return (input_data);
}
