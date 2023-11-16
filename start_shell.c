#include "main.h"

/**
 * start_shell - displays my own shell
 *
 * Description: A function that display shell with interactive mode.
 * @start_sympole: input parameter, sympole of my shell
 * @delimeter: separator betwwen input data
 *
 * Return: nothing
 **/
void start_shell(char *start_sympole, char *delimeter)
{
	char *user_data = NULL;
	size_t buffer_size = 0;
	ssize_t chars_r_num;
	char **split_data = NULL;
	int i;

	while (1)
	{
		if (isatty(STDIN_FILENO))
			printf("%s", start_sympole);
		chars_r_num = getline(&user_data, &buffer_size, stdin);
		if (!_strncmp(user_data, "exit", 4) && chars_r_num == 5)
		{
			free(user_data);
			free(split_data);
			exit(0);
		}
		if (chars_r_num == -1)
		{
			printf("\n");
			free(user_data);
			free(split_data);
			exit(0);
		}
		split_data = tok_input(user_data, delimeter, chars_r_num);
		if (split_data == NULL)
		{
			free(user_data);
			for (i = 0; split_data[i] != NULL; i++)
				free(split_data[i]);
			free(split_data);
		}
		execute_commands(split_data);
	}
	free(user_data);
	for (i = 0; split_data[i] != NULL; i++)
	{
		free(split_data[i]);
	}
	free(split_data);
}
