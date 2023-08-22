#include "main.h"

/****
 * PRINT UNSIGNED NUMBER **
 ****/
/**
 * print_unsigned - This function is used to print an unsigned number.
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

int print_unsigned(va_list types, char buffer[], int flags, int width,
                   int precision, int size) {
  int x = BUFF_SIZE - 2;
  unsigned long int num = va_arg(types, unsigned long int);

  num = convert_size_unsgnd(num, size);

  if (num == 0)
    buffer[x--] = '0';

  buffer[BUFF_SIZE - 1] = '\0';

  while (num > 0) {
    buffer[x--] = (num % 10) + '0';
    num /= 10;
  }

  x++;

  return (write_unsgnd(0, x, buffer, flags, width, precision, size));
}

/****
 * PRINT UNSIGNED NUMBER IN OCTAL *
 ****/
/**
 * print_octal - This function prints an unsigned number in octal notation.
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

int print_octal(va_list types, char buffer[], int flags, int width,
                int precision, int size) {

  int x = BUFF_SIZE - 2;
  unsigned long int num = va_arg(types, unsigned long int);
  unsigned long int init_num = num;

  UNUSED(width);

  num = convert_size_unsgnd(num, size);

  if (num == 0)
    buffer[x--] = '0';

  buffer[BUFF_SIZE - 1] = '\0';

  while (num > 0) {
    buffer[x--] = (num % 8) + '0';
    num /= 8;
  }

  if (flags & F_HASH && init_num != 0)
    buffer[x--] = '0';

  x++;

  return (write_unsgnd(0, x, buffer, flags, width, precision, size));
}

/****
 * PRINT UNSIGNED NUMBER IN HEXADECIMAL *
 ****/
/**
 * print_hexadecimal - This function prints an unsigned number in hexadecimal
 * notation.
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

int print_hexadecimal(va_list types, char buffer[], int flags, int width,
                      int precision, int size) {
  return (print_hexa(types, "0123456789abcdef", buffer, flags, 'x', width,
                     precision, size));
}

/****
 * PRINT UNSIGNED NUMBER IN UPPER HEXADECIMAL *
 ****/
/**
 * print_hexa_upper - This function prints an unsigned number in upper
 * hexadecimal notation.
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

int print_hexa_upper(va_list types, char buffer[], int flags, int width,
                     int precision, int size) {
  return (print_hexa(types, "0123456789ABCDEF", buffer, flags, 'X', width,
                     precision, size));
}

/****
 * PRINT HEXX NUM IN LOWER OR UPPER *
 ****/
/**
 * print_hexa - This function prints a hexadecimal number in either lower or
 * upper case.
 *
 * @types:     List of arguments
 * @map_to:    Array of values to map the number to
 * @buffer:    Buffer array for printing
 * @flags:     Calculates active flags
 * @flag_ch:   Calculates active flags
 * @width:     Width specification
 * @precision: Precision specification
 * @size:      Size specification
 *
 * Return:     Number of characters printed.
 */

int print_hexa(va_list types, char map_to[], char buffer[], int flags,
               char flag_ch, int width, int precision, int size) {
  int x = BUFF_SIZE - 2;
  unsigned long int num = va_arg(types, unsigned long int);
  unsigned long int init_num = num;

  UNUSED(width);

  num = convert_size_unsgnd(num, size);

  if (num == 0)
    buffer[x--] = '0';

  buffer[BUFF_SIZE - 1] = '\0';

  while (num > 0) {
    buffer[x--] = map_to[num % 16];
    num /= 16;
  }

  if (flags & F_HASH && init_num != 0) {
    buffer[x--] = flag_ch;
    buffer[x--] = '0';
  }

  x++;

  return (write_unsgnd(0, x, buffer, flags, width, precision, size));
}

