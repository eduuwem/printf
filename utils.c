#include "main.h"

/**** Authors: Eduuwem Udoh and Samuel Doghor *****/

/**
 * is_printable - This function evaluates whether a character is printable.
 *
 * @c: Char to be evaluated.
 *
 * Return: 1 if 'c' is printable, 0 otherwise.
 */

int is_printable(char c)
{
	if (c >= 32 && c < 127)
		return (1);

	return (0);
}

/**
 * append_hexa_code - This function appends ASCII code in hexadecimal format to
 * a character array.
 *
 * @buffer:      Array of characters.
 * @x:           Index at which to start appending.
 * @ascii_code:  ASCII code.
 *
 * Return:       Always 3.
 */

int append_hexa_code(char ascii_code, char buffer[], int x)
{
	char map_to[] = "0123456789ABCDEF";
	/* The hexa format code is always 2 digits long */

	if (ascii_code < 0)
		ascii_code *= -1;

	buffer[x++] = '\\';
	buffer[x++] = 'x';

	buffer[x++] = map_to[ascii_code / 16];
	buffer[x] = map_to[ascii_code % 16];

	return (3);
}

/**
 * is_digit - This function verifies if a character is a digit.
 *
 * @c: Char to be evaluated.
 *
 * Return: 1 if 'c' is a digit, 0 otherwise.
 */

int is_digit(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

/**
 * convert_size_number - This function casts a number to the specified size.
 *
 * @num: Number to be casted.
 * @size: Number indicating the type to be casted.
 *
 * Return: Casted value of 'num'.
 */

long int convert_size_number(long int num, int size)
{
	if (size == S_LONG)
		return (num);

	else if (size == S_SHORT)
		return ((short)num);

	return ((int)num);
}

/**
 * convert_size_unsgnd - This function casts a number to the specified size.
 *
 * @num: Number to be casted.
 * @size: Number indicating the type to be casted.
 *
 * Return: Casted value of 'num'.
 */

long int convert_size_unsgnd(unsigned long int num, int size)
{
	if (size == S_LONG)
		return (num);
	else if (size == S_SHORT)
		return ((unsigned short)num);
	return ((unsigned int)num);
}

