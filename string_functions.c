#include "main.h"

/**
 * _strlen - get length of given string.
 *
 * Description: Function that return the length of input string..
 * @str: pointer to an input string.
 *
 * Return: length of the string
 */
int _strlen(char *str)
{
	int i;
	if (str == NULL)
		return (0);
	for (i = 0; str[i] != '\0'; i++)
	{
	}
	return (i);
}
