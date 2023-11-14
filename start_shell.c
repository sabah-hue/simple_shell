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

	while (isatty(STDIN_FILENO))
	{
		write(STDOUT_FILENO, start_sympole, _strlen(start_sympole));
		chars_r_num = getline(&user_data, &buffer_size, stdin);
		if ((!_strncmp(user_data, "exit", 4) && chars_r_num == 5)
				|| chars_r_num == -1)
		{
			free(user_data);
			write(STDOUT_FILENO, "\n", 1);
			exit(EXIT_SUCCESS);
		}
		/*user_data[chars_r_num - 1] = '\0';*/
		split_data = tok_input(user_data, delimeter, chars_r_num);
		/**
		*split_data = tokenize_input(user_data, delimeter);
		* use this code to tokenize line without using strtok
		* but it fail in testing
		**/
		execute_commands(split_data);
	}
	free(user_data);
	for (i = 0; split_data[i] != NULL; i++)
	{
		free(split_data[i]);
	}
	free(split_data);
}
