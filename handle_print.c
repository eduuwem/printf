#include "main.h"
/**
 * handle_print - Prints the correspondents values of argument
 * with differrent format specifier
 * @fmt: Format string that has format specifier.
 * @a_list: va_list of arguments to be printed.
 * @index: index indicating current position.
 * @buffer: array used to store the printed output.
 * @flags: represent active formatting flags
 * @width: width of the field specified
 * @precision: Precision specifier
 * @size: Size specifier
 * Return: 1 or 2;
 */
int handle_print(const char *fmt, int *index, va_list a_list, char buffer[],
			int flags, int width, int precision, int size)
{
		int x, unknow_len = 0, printed_chars = -1;

		fmt_t fmt_types[] = {
			{'c', print_char}, {'s', print_string}, {'%', print_percent},
			{'i', print_int}, {'d', print_int}, {'b', print_binary},
			{'u', print_unsigned}, {'o', print_octal}, {'x', print_hexadecimal},
			{'X', print_hexa_upper}, {'p', print_pointer}, {'S', print_non_printable},
			{'r', print_reverse}, {'R', print_rot13string}, {'\0', NULL}
		};
		for (x = 0; fmt_types[x].fmt != '\0'; x++)
			if (fmt[*index] == fmt_types[x].fmt)
				return (fmt_types[x].fn(a_list, buffer, flags, width, precision, size));

		if (fmt_types[x].fmt == '\0')
		{
			if (fmt[*index] == '\0')
				return (-1);
		unknow_len += write(1, "%%", 1);
		if (fmt[*index - 1] == ' ')
			unknow_len += write(1, " ", 1);
		else if (width)
		{
			--(*index);
			while (fmt[*index] != ' ' && fmt[*index] != '%')
				--(*index);
			if (fmt[*index] == ' ')
				--(*index);
			return (1);
		}
		unknow_len += write(1, &fmt[*index], 1);
		return (unknow_len);
	}
	return (printed_chars);
}


