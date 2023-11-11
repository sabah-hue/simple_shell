#include "main.h"

/**
 * execute_commands - execute the command in my own shell
 *
 * Description: A function that execute command.
 *
 * Return: nothing
 **/
void execute_commands(char **split_data)
{
	pid_t pid;
	int status;
	
	if (split_data == NULL || split_data[0] == NULL)
		return;
	pid = fork();
	if (pid == -1)
	{
		perror("Error: fork()");
	}
	if (pid == 0)
	{
		execve(split_data[0], split_data, environ);
		perror(split_data[0]);
		exit(EXIT_FAILURE);
	}
	wait(&status);
}
