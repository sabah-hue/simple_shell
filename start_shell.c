#include "main.h"

/**
 * start_shell - basic implementation for simple shell.
 *
 * Description: A function that display shell
 * @start_sympole: my shell start sympole
 *
 * Return: nothing
 **/
void start_shell(char *start_sympole)
{
	char *user_typed;
	/*pointer to buffer holding what user typed*/
	size_t size = 0;/*size in bytes*/
	ssize_t n;/*numbers of char readed,return value from getline*/

	if (start_sympole == NULL)
		break;
	while (1)
	{
		printf("%s", start_sympole);
		n = getline(&user_typed, &size, stdin);
		if (n == EOF)
			/*handle the "end of file"*/
			break;
		printf("%s\n", user_typed);
	}
	free(user_typed);
}
