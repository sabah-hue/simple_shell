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
int main()
{
	char delimeter[] = " \t\n";
	char *start_sympole = "($) ";/*my shell start sympole*/

	start_shell(start_sympole, delimeter);
	return (0);
}
