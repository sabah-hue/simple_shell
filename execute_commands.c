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
	if (!_strncmp(split_data[0], "env", 3))
	{
		show_env();
		return;
	}
	/*if (!_strncmp(split_data[0], "./", 2)  || !_strncmp(split_data[0], "/", 1))
		execve(split_data[0], split_data, NULL);*/
	pid = fork();
	if (pid == -1)
	{
		perror("Error ");
		return;
	}
	if (pid == 0)
	{
		if (execve(split_data[0], split_data, environ) == -1)
		{
			perror("./shell ");
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		wait(&status);
	}
}
