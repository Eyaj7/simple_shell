#include "shell.h"

/**
 * strcomp - a function
 * @str: the first string
 * @equ: the secodn string
 * Return: returns an integer indicater of the boolean
 */

int strcomp(char *str, char *equ)
{
	int j = 0;
	int r = 0;

	if (str == NULL || equ == NULL)
	{
		return (0);
	}
	while (equ[j] != '\0' || str[j] != '\0')
	{

		if (str[j] == equ[j])
		{
			r = 1;
		}
		else
		{
			r = 0;
		}
		j++;
	}

	return (r);
}

/**
 * description -  a function to discription about the program
 * Return: void
 */

void description(void)
{
printstar();
printstar();
printstr("~- H.E.L.L.O _ W.A.R.M _ W.E.L.C.O.M.E -~");
printstr("");
printstr("This is a simple bash shell project.");
printstr("Designed by sertse and faj for ALX SE ");
printstr("https://github.com/sertsev");
printstar();
printstar();
}


/**
 * printstar - prints
 * Return: void
 */

void printstar(void)
{
	int j = 0;

	write(1, "\n\t\t\t", 5);
	while (j < 75)
	{
		write(1, "*", 2);
		j++;
	}
}

/**
 * printstr - a function
 * @s: a string location pointer
 * Return: void
 */

void printstr(char *s)
{
	int len = strleng(s), spc, n = 0;

	write(1, "\n\t\t\t***\t", strleng("\n\t\t\t***\t"));

	spc = (60 - len) / 2;

	while (n < spc)
	{
		write(1, " ", 2);
		n++;
	}

	write(1, s, strleng(s));

	while (n > 0)
	{
		write(1, " ", 2);
		n--;
	}

	write(1, "\t***", strleng("\t***"));
}
