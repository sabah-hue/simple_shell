#include "main.h"

/**
 * count_words - get number of words in given string.
 *
 * Description: A function that count number og words in string.
 * @s: input string need to tokonized
 * @delimeter: separator between words in string
 *
 * Return: number of words.
 **/
size_t count_words(char *s, char *delimeter)
{
	size_t words = 0;

	if (strtok(s, delimeter))
		words = 1;
	while (strtok(NULL, delimeter))
		++words;
	return (words);
}

/**
 * toknize - convert input string to array of words 
 *
 * Description: A function that make array from string
 * @s: input string, input parameter
 * @delimeter: separator between words
 *
 * Return: 1 on success, -1 on failure
 **/
char **_strtok(char *s, char *delimeter)
{
	char **split_data = NULL;
	size_t buf_size = 0;
	int i, j = 0;
	char null_term = '\0';

	buf_size = count_words(s, delimeter);
	if (buf_size > 0)
	{
		split_data = malloc(sizeof(char *) * (buf_size + 1));
		for (i = 0; i < _strlen(s); ++i)
		{
			if (s[i] != '\0' && null_term == '\0')
			{	
				split_data[j] = s + i;
				++j;
	
			}
			null_term = s[i];
		}
		split_data[j] = NULL;
	}
	return (split_data);
}
