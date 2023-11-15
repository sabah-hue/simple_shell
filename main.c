#include "main.h"

/**
 * main - Entry point.
 *
 * Description: A function that run the shell
 *
 * Return: 0 on success
 **/
int main(void)
{
	char delimeter[] = " \t\n";
	char *start_sympole = "($) ";/*my shell start sympole*/

	/*dprintf(STDERR_FILENO, "%s", "Usage: simple_shell\n");*/
	/*exit(97);*/
	start_shell(start_sympole, delimeter);
	return (0);
}
