#include "main.h"

/**
 * get_size - modify how the argument is interpreted and printed
 * @format: Formatted string  to print the arguments
 * @x: List of arguments to be printed.
 *
 * Return: Precision.
 */
int get_size(const char *format, int *x)
	/**
	 * the function takes two parameters: format is a pointer to a
	 * constant array(formatted string), and x is a pointer to an
	 * integer(tracking the current_index in the format string
	 */
{
	int current_index = *x + 1;
	int size = 0;
/**
 * if the current_index in the format string is l, the size is 
 * is assign to the value of macro S_LONG
 */
	if (format[current_index] == 'l')
		size = S_LONG;
/**
  * if the current_index is h, the size is assign to the value of 
  * macro S_SHORT
 */
	else if (format[current_index] == 'h')
		size = S_SHORT;

	if (size == 0)
	*x = current_index - 1;
		else
		*x = current_index;

	return (size);
}


