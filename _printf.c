#include "main.h"

void print_buffer(char buffer[], int *buffer_index);

/**
  * _printf - function that produces an output
  * @format: This is a character string
  * Return: Numbers of characters printed without null byte
  */
int _printf(const char *format, ...)
{
	int x, printed = 0, printed_chars = 0;
	int flags, width, precision, size, buffer_index = 0;
	va_list a_list;
	char buffer[BUFF_SIZE];
	int k, length = 0;
	int str_len = 0;

	if (format == NULL)
		return (-1);

	va_start(a_list, format);

	for (x = 0; format && format[x] != '\0'; x++)
	{
		if (format[x] != '%')
		{
			buffer[buffer_index++] = format[x];
			if (buffer_index == BUFF_SIZE)
			print_buffer(buffer, &buffer_index);
			/* write(1, &format[x], 1);*/
			printed_chars++;
		}
		else
		{
			print_buffer(buffer, &buffer_index);
			flags = get_flags(format, &x);
			width = get_width(format, &x, a_list);
			precision = get_precision(format, &x, a_list);
			size = get_size(format, &x);
			++x;

			if (format[x] == 'r')
			{
				char *str = va_arg(a_list, char *);

				if (str == NULL)
					str = "(null)";

				while (str[length] != '\0')

				{
					length++;
				}


				for (k = length - 1; k >= 0; k--)
				{
					buffer[buffer_index++] = str[k];

					if (buffer_index == BUFF_SIZE)

						print_buffer(buffer, &buffer_index);
				}

				printed_chars += length;
			}

			if (format[x] == 's')
			{
				char *str = va_arg(a_list, char *);

				if (str == NULL)
					str = "(null)";

				while (str[str_len] != '\0' && str_len < precision)
				{
					buffer[buffer_index++] = str[str_len++];

					if (buffer_index == BUFF_SIZE)
						print_buffer(buffer, &buffer_index);

				}

				printed_chars += str_len;
			}

			else
			{

			printed = handle_print(format, &x, a_list, buffer,
					flags, width, precision, size);

			if (printed == -1)

				return (-1);

			printed_chars += printed;
			}
		}
	}
	print_buffer(buffer, &buffer_index);
	va_end(a_list);
	return (printed_chars);
}


/**
 * print_buffer - Prints the functions of the buffer contents
 * @buffer: it takes an arrays of character
 * @buffer_index: Inputs as index that adds next
 *                character and also the length
 */
void print_buffer(char buffer[], int *buffer_index)
{
		if (*buffer_index > 0)
			write(1, &buffer[0], *buffer_index);

		*buffer_index = 0;
}


