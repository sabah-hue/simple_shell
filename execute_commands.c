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
 * _which - get full path
 *
 * Description: A function that get full path for input command;
 * @x: input command.
 *
 * Return: full path, NULL in failur.
 **/
char *_which(char *x)
{
	char *path, *path_dir, *path_edit, *copy_path;

	path = _getenv("PATH");
	if (path == NULL)
		return (NULL);
	copy_path = strdup(path);
	path_dir = _strtok(copy_path, ":");
	while (path_dir)
	{
		path_edit = malloc(strlen(path_dir) + 2 + strlen(x) + 1);
		sprintf(path_edit, "%s/%s", path_dir, x);
	/*	path_edit = str_concat(path_dir, "/");*/
	/*	path_full = str_concat(path_edit, x);*/
		if (access(path_edit, F_OK) == 0 && access(path_edit, X_OK) == 0)
		{
			free(copy_path);
			return (path_edit);
		}
		free(path_edit);
		path_dir = _strtok(NULL, ":");
	}
	free(copy_path);
	perror(_getenv("_"));
	return (NULL);
}

/**
 * str_concat - concate two strings.
 *
 * Description: a function returns concatenates two strings.
 * @s1: input string,input parameter
 * @s2: input string, input parameter
 *
 * Return: a pointer to a concated string, NULL in failure.
 **/
char *str_concat(char *s1, char *s2)
{
	char *a;
	int i, j, x, size;

	if (s1 != NULL)
	{
		for (i = 0; s1[i] != '\0'; i++)
		{
		}
	}
	if (s2 != NULL)
	{
		for (j = 0; s2[j] != '\0'; j++)
		{
		}
	}
	size = i + j;
	a = malloc(sizeof(char) * size + 1);
	if (a != NULL)
	{
		for (x = 0; x < i; x++)
		{
			a[i] = s1[i];
		}
		for (x = 0; x < j; x++, i++)
		{
			a[i] = s2[x];
		}
		a[i] = '\0';
	}
	return (a);
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
	struct stat st;
	char *full_path;

	if (split_data == NULL || split_data[0] == NULL)
		return;
	if (check_command(split_data))
	{
		return;
	}
	if (stat(split_data[0], &st))
	{
		full_path = _which(split_data[0]);
		if (full_path)
			split_data[0] = full_path;
		else
			return;
	}
	if (access(split_data[0], F_OK) == 0 && access(split_data[0], X_OK) == 0)
	{
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
		wait(&status);
	}
}
