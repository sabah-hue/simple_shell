#include "main.h"
/**
 * check_command - execute special command cases.
 *
 * Description: A function that execute special cases from input commands.
 * @split_data: pointer to input data commands.
 *
 * Return: 1 on success, 0 on failure
 **/
int check_command(char **split_data)
{
	pid_t my_pid;

	if (!_strncmp(split_data[0], "echo", 4) && !_strncmp(split_data[1], "$?", 2))
	{
		write(1, "0", 1);
		write(1, "\n", 1);
		return (1);
	}
	if (!_strncmp(split_data[0], "echo", 4) && !_strncmp(split_data[1], "$$", 2))
	{
		my_pid = getpid();
		printf("%u\n", my_pid);
		return (1);
	}
	if (!_strncmp(split_data[0], "env", 3))
	{
		show_env();
		return (1);
	}
	if (!_strncmp(split_data[0], "exit", 4) && split_data[1] != NULL)
	{
		printf("exit %s\n", split_data[1]);
		return (1);
	}
	return (0);
}

/**
 * execute_commands - execute the command in my own shell
 *
 * Description: A function that execute command.
 * @split_data: pointer to data entered by user
 *
 * Return: nothing
 **/
void execute_commands(char **split_data)
{
	pid_t pid;

	int status;

	if (split_data == NULL || split_data[0] == NULL)
		return;
	if (check_command(split_data))
	{
		return;
	}

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
			perror(_getenv("_"));
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		wait(&status);
	}
}
