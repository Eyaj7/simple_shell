#include "shell.h"

/**
 * envir - a function which excutes the /bin/ls program to list files
 * @line: an array of command and arguments
 * Return: returns 1 in success and -1 if it fails
 */

int envir(char *line[] __attribute__((unused)))
{
	int i = 0;

	while (environ[i] != NULL)
	{
		write(1, environ[i], strleng(environ[i]));
		write(1, "\n", 2);
		i++;
	}
	free(line);
	return (1);
}

/**
 * maker - a function which excutes the /bin/ls program to list files
 * @line: an array of command and arguments
 *
 * Return: returns 1 in success and -1 if it fails
 */

int maker(char *line[])
{
	int status;
	pid_t waiter, child;

	child = fork();
	if (child == -1)
		perror("Forking");

	if (child == 0)
	{
		execve("/bin/mkdir", line, NULL);
	}
	else
	{
		waiter = wait(&status);
		if (waiter == -1)
			perror("Waiting");
	}
	free(line);
	return (1);
}

/**
 * stringer - a helper function
 * @line: a string
 * @i: the index
 * @str: a string
 * @c: a character
 * Return: returns a string pointer
 */

char *stringer(char *line, int i, char *str, char c)
{
	int z = 0;
	char *tmp;

	str = malloc(64);
	if (str == NULL)
	{
		perror("Couldn't Allocate");
		return (NULL);
	}
	while (line[i] != c && line[i] != '\0')
	{
		str[z] = line[i++];
		z++;
		if (z > 60)
		{
			tmp = realloc(str, (z + 8));
			if (!tmp)
			{
				perror("Error");
				return (NULL);
			}
			else
				str = tmp;
		}
	}

	str[z] = '\0';

	return (str);
}
