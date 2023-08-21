#include "main.h"

/**
 * get_flags - turns on flags if _printf finds a flag
 *             modifier in the format string
 * @format:The formatted strings  to print the arguments
 * @x: inputs a parameter.
 * Return: Flags
 */
int get_flags(const char *format, int *x)
{
	/* flags associated with binary values*/
	/* - + 0 # ' ' */
	/* 1 2 4 8  16 */
	int k, current_index;
	int flags = 0;

	/* these arrays stores the mapping between characters*/
	const char FLAGS_CH[] = {'-', '+', '0', '#', ' ', '\0'};
	const int FLAGS_ARR[] = {F_MINUS, F_PLUS, F_ZERO, F_HASH,
					F_SPACE, 0};

	for (current_index = *x + 1; format[current_index] != '\0';
						current_index++)
	{

		for (k = 0; FLAGS_CH[k] != '\0'; k++)
			if (format[current_index] == FLAGS_CH[k])
			{
				/**
				 *if the current character in the forma
				 * at string matches the flag character
				 * the correlate flag value is added to
				 * the flags variables using bitwise
				 *operators
				 */
				flags |= FLAGS_ARR[k];
				break;
			}

		if (FLAGS_CH[k] == 0)
			break;
	}

	*x = current_index - 1;

	return (flags);
}

