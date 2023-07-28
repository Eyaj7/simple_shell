#include "shell.h"

/**
 * copyarray - a function
 * @line: a string 
 * Return: returns the copied array
 */

char **copyarray(char **line)
{
	char **array;
	int j = 1;

	array = malloc(64);
	if (!array)
		return (NULL);

	while (line[j] != NULL)
	{
	array[(j - 1)] = malloc(32);
	if (!array[(j - 1)])
		return (NULL);

	strcopy(line[j], array[(j - 1)]);
	j++;
	}

return (array);
}

/**
 * sigintHandler - a function to handle the ctrl-c signal
 * @sig_num: an integer signal indicator
 *
 * Return: void function
 */

void sigintHandler(int sig_num __attribute__((unused)))
{
	signal(SIGINT, sigintHandler);
	write(1, "\n", 2);
	printprompt(0);
	fflush(stdout);
}

/**
 * main - a the main function
 * @argc: the number of arguments given
 * @argv: an array of given argument strings
 * Return: returns 0
 */

int main(int argc __attribute__((unused)), char **argv)
{
	char *line;

	line = malloc(256);
	if (!line)
	{
		perror("Allocation");
		exit(1);
	}

	if (!isatty(STDIN_FILENO))
	{
		if (getstr(line) == (-1))
		{
			write(1, "\n", 2);
			exit(1);
		}
		if (shellprocessor(strbrk(line, ' '), argv) == -1)
		{
			perror("Error");
		}

		exit(0);
	}

	do {
		printprompt(0);
		if (getstr(line) == (-1))
		{
			write(1, "\n", 2);
			exit(0);
		}

		if ((shellprocessor(strbrk(line, ' '), argv)) == -1)
		{
			perror("Error");
		}
	} while (1);

	return (0);
}
