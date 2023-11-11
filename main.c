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
	char delimeter[] = " \n\t";
	char *start_sympole = "($) ";/*my shell start sympole*/

	(void)ac;
	(void)av;

	if (isatty(STDIN_FILENO))
	{
		start_shell(start_sympole, delimeter);
	}
	else
		/* run_non_interactive(); */
		printf("non interact mode");
	return (0);
}
