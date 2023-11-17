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
	int i = 0, index;
	char **e = environ;
	char *x = NULL;

	if (name == NULL)
		return (NULL);
	while (e[i])
	{
		index = 0; /* start count */
		if (name[index] == e[i][index])
		{
			while (name[index] != '\0')
			{
				if (name[index] != e[i][index])
					break;
				index++;
			}
			if (name[index] == '\0')
			{
				x = e[i] + index + 1;
				/* x refere to value of the name */
				return (x);
			}
		}
		i++;
	}
	for (i = 0; e[i]; i++)
	{
		free(e[i]);
	}
	free(e);
	return (NULL);
}

/**
 * show_env - print environment variables.
 *
 * Description: A function that print environment variables.
 *
 * Return: nothing.
 **/
void show_env(void)
{
	char **e = environ;

	while (*e != NULL)
	{
		printf("%s\n", *e);
		e++;
	}
}


