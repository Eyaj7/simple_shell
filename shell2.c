#include "shell.h"

/**
* getstr - a function
* @str: a string pointer
* Return: return 1 in success and -1 in failure
*/

int getstr(char *str)
{
	char **line;
	size_t siz = 0;
	signal(SIGINT, sigintHandler);
	line = malloc(24);
	if (!line)
	{
		return (-1);
	}

	if ((getline(line, &siz, stdin)) == -1)
	{
		return (-1);
	}

	line[0][siz] = '\0';

	strcopy(line[0], str);

	if (line[0][siz - 2] == '\\')
	{
		do {
			str[strleng(str) - 1] = ' ';
			siz = 0;
			printprompt(1);

			if ((getline(line, &siz, stdin)) == -1)
			{
				return (-1);
			}
			line[0][siz] = '\0';

			strmix(line[0], str);
		} while (line[0][siz - 2] == '\\');
	}

	free(line);
	return (1);
}

/**
* strcopy - a function to copy to strings
* @src: the string to be copied
* @dest: the destination of the copied string
* Return: returns nothing (void)
*/

void strcopy(char *src, char *dest)
{
	int y = 0;
	int z = 0;

	if (!dest)
	{
		z = 0;
	}

	while (src[y] != '\0' && src[y] != '\n')
	{
		dest[z++] = src[y++];
	}

	dest[z] = '\0';
}

/**
* strmix - a function
* @src: the string
* @dest: the destination
* Return: returns nothing (void)
*/

void strmix(char *src, char *dest)
{
	int y = 0;
	int z;

	if (!dest)
	{
		z = 0;
	}
	else
	{
		z = strleng(dest);
	}

	while (src[y] != '\0' && src[y] != '\n')
	{
		dest[z++] = src[y++];
	}

	dest[z] = '\0';
}

/**
* strbrk - a function that breaks a long string in to arrauy of strings
* @line: the string to be breakdown
* @c: a chacter specifier where to break the string
*
* Return: returns the array of the words.
*/

char **strbrk(char *line, char c)
{
	int y = 0, z = 0;
	char **array, **tmp;

	if (!line || line[0] == '\0')
	{
		return (NULL);
	}
	array = malloc(sizeof(*array) * 128);
	if (array == NULL)
	{
		perror("Couldn't Allocate");
		return (NULL); }
	while (line[y] != '\0')
	{
		if (z > 124)
		{
			tmp = realloc(array, sizeof(*array) * (y + 4));
			if (tmp == NULL)
			{
				perror("Couldn't Reallocate");
				return (NULL); }
			else
			{
				array = tmp; }
		}
		if (line[y] == c)
		{
			y++;
			continue; }
		array[z] = stringer(line, y, array[z], c);
		if (array[z] == NULL)
		{
			return (NULL); }
		y += strleng(array[z++]);
	}
	array[z] = NULL;
	return (array);
}

/**
* strleng - measures
* @s: a string
* Return: returns length
*/

int strleng(char *s)
{
	int len = 0;

	while (s[len] != '\0')
	{
	len++;
	}

	return (len);
}
