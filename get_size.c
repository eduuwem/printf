#include "main.h"

/**
 * get_size - modify how the argument is interpreted and printed
 * @format: Formatted string  to print the arguments
 * @x: List of arguments to be printed.
 *
 * Return: Precision.
 */
int get_size(const char *format, int *x)
{
	int current_index = *x + 1;
	int size = 0;

	if (format[current_index] == 'l')
		size = S_LONG;

	else if (format[current_index] == 'h')
		size = S_SHORT;

	if (size == 0)
	*x = current_index - 1;
		else
		*x = current_index;

	return (size);
}


