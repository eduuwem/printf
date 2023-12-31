#include "main.h"

/**** Authors: Eduuwem Udoh and Samuel Doghor *****/

/****
 * PRINT POINTER *
 ****/
/**
 * print_pointer - This function prints the value of a pointer variable.
 *
 * @types:     List of arguments
 * @buffer:    Buffer array for printing
 * @flags:     Calculates active flags
 * @width:     Width specification
 * @precision: Precision specification
 * @size:      Size specifier
 *
 * Return:     Number of characters printed.
 */

int print_pointer(va_list types, char buffer[], int flags, int width,
		int precision, int size) {

	char extra_c = 0, padd = ' ';

	int index = BUFF_SIZE - 2, length = 2, padd_start = 1;
	/* length=2, for '0x' */

	unsigned long num_addrs;

	char map_to[] = "0123456789abcdef";

	void *addrs = va_arg(types, void *);

	UNUSED(width);

	UNUSED(size);

	if (addrs == NULL)

		return (write(1, "(nil)", 5));

	buffer[BUFF_SIZE - 1] = '\0';

	UNUSED(precision);

	num_addrs = (unsigned long)addrs;

	while (num_addrs > 0)
	{
		buffer[index--] = map_to[num_addrs % 16];

		num_addrs /= 16;

		length++;
	}

	if ((flags & F_ZERO) && !(flags & F_MINUS))

		padd = '0';

	if (flags & F_PLUS)

		extra_c = '+', length++;

	else if (flags & F_SPACE)

		extra_c = ' ', length++;

	index++;

	/*return (write(1, &buffer[x], BUFF_SIZE - x - 1));*/

	return (write_pointer(buffer, index, length, width, flags, padd, extra_c,
				padd_start));
}

/****
 * PRINT NON PRINTABLE *
 ****/
/**
 * print_non_printable - This function prints ASCII codes in hexadecimal format
 * for non-printable characters.
 *
 * @types:     List of arguments
 * @buffer:    Buffer array for printing
 * @flags:     Calculates active flags
 * @width:     Width specification
 * @precision: Precision specification
 * @size:      Size specifier
 *
 * Return:     Number of characters printed.
 */

int print_non_printable(va_list types, char buffer[], int flags, int width,
		int precision, int size) {

	int x = 0, offset = 0;

	char *str = va_arg(types, char *);

	UNUSED(flags);

	UNUSED(width);

	UNUSED(precision);

	UNUSED(size);

	if (str == NULL)

		return (write(1, "(null)", 6));

	while (str[x] != '\0')
	{
		if (is_printable(str[x]))

			buffer[x + offset] = str[x];
		else
			offset += append_hexa_code(str[x], buffer, x + offset);
		x++;
	}

	buffer[x + offset] = '\0';

	return (write(1, buffer, x + offset));
}

/****
 * PRINT REVERSE *
 ****/
/**
 * print_reverse - This function prints a string in reverse.
 *
 * @types:     List of arguments
 * @buffer:    Buffer array for printing
 * @flags:     Calculates active flags
 * @width:     Width specification
 * @precision: Precision specification
 * @size:      Size specifier
 *
 * Return:     Number of characters printed.
 */

int print_reverse(va_list types, char buffer[], int flags, int width,
		int precision, int size) {

	char *str;

	int x, count = 0;

	UNUSED(buffer);

	UNUSED(flags);

	UNUSED(width);

	UNUSED(size);

	str = va_arg(types, char *);

	if (str == NULL)
	{
		UNUSED(precision);

		str = ")Null(";
	}
	for (x = 0; str[x]; x++)

	for (x = x - 1; x >= 0; x--)
	{
		char z = str[x];

		write(1, &z, 1);

		count++;
	}

	return (count);
}

/****
 * PRINT A STRING IN ROT13 *
 ****/
/**
 * print_rot13string - This function prints a string using the rot13 encoding.
 *
 * @types:     List of arguments
 * @buffer:    Buffer array for printing
 * @flags:     Calculates active flags
 * @width:     Width specification
 * @precision: Precision specification
 * @size:      Size specifier
 *
 * Return:     Number of characters printed.
 */

int print_rot13string(va_list types, char buffer[], int flags, int width,
		int precision, int size) {

	char b;

	char *str;

	unsigned int x, k;

	int count = 0;

	char in[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";

	char out[] = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";

	str = va_arg(types, char *);

	UNUSED(buffer);

	UNUSED(flags);

	UNUSED(width);

	UNUSED(precision);

	UNUSED(size);

	if (str == NULL)

		str = "(AHYY)";

	for (x = 0; str[x]; x++)
	{
		for (k = 0; in[k]; k++)
		{
			if (in[k] == str[x])
			{
				b = out[k];

				write(1, &b, 1);

				count++;

				break;
			}
		}

		if (!in[k])
		{
			b = str[x];

			write(1, &b, 1);

			count++;
		}
	}

	return (count);
}

