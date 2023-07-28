#include "simishell.h"
/**
 * _getchar - function that reads a character
 * from the standard input
 * Return: returns the read character
 */
char _getchar(void)
{
	char *buffer;
	char c;
	int i = 0;

	buffer = malloc(2);
	if (!buffer)
		return (-1);
	fflush(stdout);
	i = read(1, buffer, 1);
	if (i == -1)
	{
		perror("Reading Char");
		return (-1);
	}
	else if (i == 0)
	{
		write(1, "\n", 2);
		fflush(stdout);
		exit(1);
	}
	c = *buffer;
	return (c);
}

/**
 * _getline - function to read a line from the standard input
 * @adress: pointer to a pointer
 * @len: the size of the characters
 * Return: returns the size of the string
 */

int _getline(char **adress, size_t *len)
{
	size_t l = 25;
	char *tmp;

	adress[0] = malloc(25);
	if (!adress[0])
		return (-1);
	*len = 0;
	while (adress[0][*len - 1] != '\n')
	{
		adress[0][*len] = _getchar();
		*len += 1;
		if (*len > (l - 3))
		{
			tmp = realloc(adress[0], l + 10);
			if (tmp)
				adress[0] = tmp;
			else
				perror("Reallocation");
			l += 10;
		}
	}
	return (*len);
}

/**
 * _echo - function to echo back any text you send
 * @array: command and arguments's array
 * Return: returns 1 in success and -1 if it fails
 */
int _echo(char *array[])
{
	int i = 1;

	if (array[i] == NULL)
	{
		write(1, "\n", 2);
		return (1);
	}
	while (array[i] != NULL)
	{
		write(1, array[i], strleng(array[i]));
		i++;
		if (array[i] != NULL)
		{
			write(1, " ", 2);
		}
	}
	write(1, "\n", 2);
	return (1);

