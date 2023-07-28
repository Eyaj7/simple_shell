#include "shell.h"

/**
* _exit - function that exit the program
* @line: ommand and arguments's array
* Return: no return
*/
int _exit(char *line[])
{
	int i = 0;
1
	if (line[1] == NULL)
	{
		exit(EXIT_SUCCESS); }
	else if (atoi(line[1]) > 0)
	{
		i = atoi(line[1]); }
	free(line);
	exit(i);
}

/**
* changedire - a function to change a directory
* @line: an array of commands and arguments
*
* Return: returns 0 in success and -1 if it fails
*/

int changedire(char **line)
{
	if (line[1] == NULL)
	{
		chdir(getenv("HOME"));
	}
	else if (chdir(line[1]) == -1)
	{
		write(1, line[0], strleng(line[0]));
		write(1, ": ", 3);
		write(1, ": cd", strleng(": cd"));
		write(1, ": can't cd to ", strleng(": can't cd to "));
		write(1, line[1], strleng(line[1]));
		write(1, "\n", 2);
		return (-1);
	}
	free(line);
	return (1);
}

/**
* _prompt - function that display a prompet
* @i: an int value to indicate which icon to display
* Return: void
*/

void _prompt(int i)
{
	if (i == 0)
	{
		write(1, "USH$ ", strleng("USH$ "));
	}
	else if (i == 1)
	{
		write(1, "ush> ", strleng("ush> "));
	}
}
