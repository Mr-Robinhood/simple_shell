#include "shell.h"

/**
 * main - the main shell code
 *
 * applies the functions in utils and helpers
 * implements EOF
 * Prints error on Failure
 * Return: nothing.
 */

int main(void)
{
	char *line = NULL;
	size_t n = 0;
	int i;
	int j;
	ssize_t l = 0;
	char *arr[MAX_ARGS] = {NULL};
	char *token;

	while (1)
	{
		if (isatty(STDIN_FILENO))
		{
			write(1, "$ ", 2);
		}
		l = getline(&line, &n, stdin);
		if (l == -1)
		{
			printf("./hsh: 1 : %s : not found\n", line);
			break;
		}
		i = 0;
		token = strtok(line, " \t\n");
		while (token != NULL && i < MAX_ARGS - 1)
		{
			arr[i] = (char *)malloc((strlen(token) + 1) * sizeof(char));
			if (arr[i] == NULL)
			{
				perror("malloc");
				exit(EXIT_FAILURE);
			}
			strcpy(arr[i], token);
			token = strtok(NULL, " \n\t");
			i++;
		}
		arr[i] = NULL;
		execute(line, arr);
		for (j = 0; j < i; j++)
		{
			free(arr[j]);
		}
	}
	free(line);
	return (0);
}
