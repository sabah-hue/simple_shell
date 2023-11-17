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
		printf("0\n");
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
		printf("%s\n", split_data[1]);
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
	char *path = NULL, *path_dir = NULL, *path_edit = NULL, *copy_path = NULL;

	path = _getenv("PATH");
	if (path == NULL || x == NULL)
		return (NULL);
	copy_path = strdup(path);
	if (copy_path == NULL)
		free(copy_path);
	path_dir = _strtok(copy_path, ":");
	while (path_dir && x)
	{
		path_edit = malloc(strlen(path_dir) + strlen(x) + 3);
		sprintf(path_edit, "%s/%s", path_dir, x);
		if (access(path_edit, F_OK) == 0 && access(path_edit, X_OK) == 0)
		{
			free(copy_path);
			return (path_edit);
		}
		free(path_edit);
		path_dir = _strtok(NULL, ":");
	}
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
	char *a = NULL;
	int i, len1, len2, size;

	if (s1 != NULL)
	{
		for (len1 = 0; s1[len1] != '\0'; len1++)
		{
		}
	}
	if (s2 != NULL)
	{
		for (len2 = 0; s2[len2] != '\0'; len2++)
		{
		}
	}
	size = len1 + len2;
	a = malloc(sizeof(char) * size + 1);
	if (a == NULL)
		return (NULL);
	if (a != NULL)
	{
		while (i < len1)
		{
			a[i] = s1[i];
			i++;
		}
		i = 0;
		while (i < len2)
		{
			a[len1] = s2[i];
			i++;
			len1++;
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

	int status, i;
	struct stat st;
	char *full_path = NULL;

	if (split_data == NULL || split_data[0] == NULL)
		return;
	if (check_command(split_data))
		return;
	if (stat(split_data[0], &st))
	{
		full_path = _which(split_data[0]);
		if (full_path)
		{
			split_data[0] = full_path, free(full_path);
		}
	}
	if (access(split_data[0], F_OK) == 0 && access(split_data[0], X_OK) == 0)
	{
	pid = fork();
	if (pid == 0)
	{
		if (execve(split_data[0], split_data, environ) == -1)
		{
			perror(split_data[0]);
			for (i = 0; split_data[i] != NULL; i++)
			{
				free(split_data[0]);
			}
			free(split_data);
			exit(127);
		}
	}
	else
		wait(&status);
	free(split_data);
	}
}
