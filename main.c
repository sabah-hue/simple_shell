#include "main.h"

/**
 * main - Entry point.
 *
 * Description: A function that run the shell
 * @ac: counter,input parameter
 * @av: vector, input parameter
 *
 * Return: 0 on success
 **/
int main(int ac, char **av)
{
	char *start_sympole = "my_simple_shell# ";
	/*my shell will start with my_simple_shell# */
	char *user_typed;
	/*pointer to buffer holding what user typed*/
	size_t size = 0;/*size in bytes*/
	(void)ac;
	(void)av;

	while (1)
	{
		printf("%s", start_sympole);
		getline(&user_typed, &size, stdin);
		printf("%s\n", user_typed);
		free(user_typed);
	}
	return (0);
}
