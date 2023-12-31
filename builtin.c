#include "shell.h"

/**
* lister - function for /bin/ls to list files
* @line: command and arguments' array
* Return: returns 1 in success and -1 if it fails
*/

int lister(char *line[])
{
	int status;
	pid_t i, pid;

	pid = fork();
	if (pid == -1)
	{
		perror("Forking");
	}
	if (pid == 0)
	{
		execve("/bin/ls", line, NULL);
	}
	else
	{
		i = wait(&status);
		if (i == -1)
		{
			perror("Waiting");
		}
	}
	free(line);
	return (1);
}

/**
* cater - a function which excutes the /bin/cat program to show text files
* @line: an array of command and arguments
* Return: returns 1 in success and -1 if it fails
*/

int cater(char *line[])
{
	int status;
	pid_t i, pid;

	pid = fork();
	if (pid == -1)
	{
		perror("Forking");
	}
	if (pid == 0)
	{
		execve("/bin/cat", line, NULL);
	}
	else
	{
		i = wait(&status);
		if (i == -1)
		{
			perror("Waiting");
		}
	}
	free(line);
	return (1);
}

/**
* builtincom -function to excute when unlisted command shows
* @line: pointer to pointer of characters
* Return: returns an integer
*/

int builtincom(char **line)
{
	int status;
	pid_t i, pid;

	pid = fork();
	if (pid == -1)
	{
		perror("Forking");
	}
	if (pid == 0)
	{
		execve(line[0], line, NULL);
		if (errno != 0)
		{
			return (errno);
		}
	}
	else
	{
		i = wait(&status);
		if (i == -1)
		{
			perror("Waiting");
		}
	}
	free(line);
	return (0);
}

/**
* pwder - a function which prints the current path
* @line: an array of command and arguments
*
* Return: returns 1 in success and -1 if it fails
*/

int pwder(char *line[])
{
	int status;
	pid_t i, pid;

	pid = fork();
	if (pid == -1)
		perror("Forking");
	if (pid == 0)
	{
		execve("/bin/pwd", line, NULL);
	}
	else
	{
		i = wait(&status);
		if (i == -1)
			perror("Waiting");
	}
	free(line);
	return (1);
}

/**
* echorr - a function which echo back any text
* @line: an array of command and arguments
* Return: returns 1 in success and -1 if it fails
*/

int echorr(char *line[])
{
	int status;
	pid_t waiter, child;

	child = fork();
	if (child == -1)
	{
		perror("Forking");
	}
	if (child == 0)
	{
		execve("/bin/echo", line, NULL);
	}
	else
	{
		waiter = wait(&status);
		if (waiter == -1)
		{
			perror("Waiting");
		}
	}
	free(line);
	return (1);
}

