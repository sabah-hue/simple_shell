#include "main.h"

/**
 * _getenv - gets an environment variable (without using getenv).
 *
 * Description: A function that get environment variable.
 * @name: environment variable name need to know his value.
 *
 * Return: a pointer to value, NULL in failur.
 **/
char *_getenv(const char *name)
{
	int i = 0;
	char **e = environ;

	while (e[i])
	{
		if (*e == name)
			return (*e);
	}
	return (NULL);
}


/**
 * show_env -  print environment variables.                                                        *
 * Description: A function that print environment variables.
 *
 * Return: nothing.                                                                           
 **/
void show_env()
{
	char **e = environ;

	while (*e != NULL)
	{
		printf("%s\n", *e);
	}
}
