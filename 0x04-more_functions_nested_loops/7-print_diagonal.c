#include "main.h"

/**
 * print_diagonal - Draws a diagonal line of backslashes ('\').
 * @n: Number of times the character '\' should be printed.
 */
void print_diagonal(int n)
{
	int spaces = 0;

	if (n <= 0)
	{
		_putchar('\n');
		return;
	}

	while (spaces < n)
	{
		int i;

		for (i = 0; i < spaces; i++)
		{
			_putchar(' ');
		}
		_putchar('\\');
		_putchar('\n');
		spaces++;
	}
}
