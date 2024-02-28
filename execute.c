#include "shell.h"

/**
 * execute - starts executing everything
 * @line: try to check current token
 * @arr: parse token
 *
 * Return: void function
 */

void execute(char *line, char **arr)
{

	pid_t  id;

	id = fork();

	if (id == 0)
	{
		execve(line, arr, NULL);
	}
	else
	{

		wait(NULL);
	}

}
