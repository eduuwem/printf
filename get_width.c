#include "main.h"

/**
 * get_width -  this calculates and stores the minimum number
 * of character allocate for printing
 * @format: Formatted strings to print the arguments.
 * @x: List of arguments to be printed.
 * @a_list: list of arguments..
 *
 * Return: width.
 */
int get_width(const char *format, int *x, va_list a_list)
{
		int current_index;
		int width = 0;

		for (current_index = *x + 1; format[current_index] != '\0';
			current_index++)
		{

			if (is_digit(format[current_index]))
			{
				width *= 10;
				width += format[current_index] - '0';
			}
			else if (format[current_index] == '*')
			{
				current_index++;
				width = va_arg(a_list, int);
				break;
			}
			else
				break;
		}

		*x = current_index - 1;

		return (width);
}


