#include "main.h"

/**
 * get_precision - specifies and Calculates the precision for printing
 * @format: Formatted strings to print the arguments
 * @x: List of arguments to be printed.
 * @a_list: list of arguments.
 *
 * Return: Precision.
 */
int get_precision(const char *format, int *x, va_list a_list)
{
/* initializes two integer variables*/
/* current_index keeps track of the current index*/
/* precision stores the calculated precision value to prints*/

	int current_index = *x + 1;
	int precision = -1;

	if (format[current_index] != '.')
		return (precision);

	precision = 0;

	for (current_index += 1; format[current_index] != '\0';
						current_index++)

	{
		if (is_digit(format[current_index]))
		{
			precision *= 10;
			precision += format[current_index] - '0';
		}
	/**
	 * the asterisk is format specifier that shows the precision
	 * value from the argument list
	 */
		else if (format[current_index] == '*')
		{
			current_index++;
			precision = va_arg(a_list, int);
	/* va_args retrieve an int value from argument list*/
			break;
		}
else
			break;
	}

	*x = current_index - 1;

	return (precision);
}

