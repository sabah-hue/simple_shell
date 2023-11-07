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
	char *input_data;
	char **split_data;
	char delimeter[] = " \n\t";
	char *start_sympole = "($) ";/*my shell start sympole*/

	(void)ac;
	(void)av;

	input_data = start_shell(start_sympole);
	split_data = tokenize_input(input_data, delimeter); 

	return (0);
}
