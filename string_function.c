#include "main.h"

/**
 * _strlen - get the length of a string
 *
 * Description: Function get the length of input string.
 * @str: pointer to the string
 *
 * Return: the length of string
 **/
int _strlen(char *str)
{
	int i;

	for (i = 0; str[i] != '\0'; i++)
	{
	}
	return (i);
}

/**
 *_strcpy - copy string from src to dest.
 *
 * Description: A function that displays the information
 * contained in the ELF header at the start of an ELF file.
 * @dest: string which hold a copy from src string
 * @src: input string
 *
 * Return: 1 on success, -1 on failure
 **/
char *_strcpy(char *dest, char *src)
{
	int i;

	for (i = 0; src[i] != '\0'; i++)
	{
		dest[i] = src[i];
	}
	dest[i] = '\0';
	return (dest);
}

/**
 * _strcmp - compare strings
 *
 * Description: a function that  cpmpare strings
 * @str1: first string
 * @str2: second string
 *
 * Return: result of compare value, 0 in matching case.
 **/
int _strcmp(char *str1, char *str2)
{
	int cmp_value;

	while (*str1 && *str2 && *str1 == *str2)
	{
		str1++;
		str2++;
	}
	if (*str1 != *str2)
	{
		cmp_value = *str1 - *str2;
		return (cmp_value);
	}
	return (0);
}

/**
 * _strncmp - compare strings with certain number of bits.
 *
 * Description: a function that  cpmpare strings
 * @str1: first string
 * @str2: second string
 * @n_cmp: number of bytes need to compare.
 *
 * Return: result of compare value, 0 in matching case.
 **/
int _strncmp(const char *str1, const char *str2, size_t n_cmp)
{
	size_t i = 0;

	while (str1[i] && str2[i] && i < n_cmp)
	{
		if (str1[i] > str2[i])
			return (str1[i] - str2[i]);
		else if (str1[i] < str2[i])
			return (str1[i] - str2[i]);
		i++;
	}
	if (i == n_cmp)
		return (0);
	else
		return (-15);
}

/**
 * split_len - count number of chars
 *
 * Description: A function that count number of char in one word.
 * @s: input string
 * @d: delimeter, separator between words.
 *
 * Return: number of char in word
 **/
int split_len(char *s, char *d)
{
	int i = 0;
	int j = 0;

	while (*(s + i) && *(s + i) != *d)
	{
		i++;
		j++;
	}
	return (j);
}
