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
	int check;
	char **split_data;

	while (1)
	{
		printf("%s", start_sympole);
		chars_r_num = getline(&user_data, &buffer_size, stdin);
		check = strncmp(user_data, "exit", 4);
		if (check == 0 || chars_r_num == -1)
		{
			break;
		}
		split_data = tokenize_input(user_data, delimeter);
		if (split_data[0] != NULL)
		{
			if (access(split_data[0], X_OK == 0) == 0)
			{
				execute_commands(split_data);

			}
			else
			{
				perror("./hsh ");
			}
		}
	}
	free(user_data);
}
