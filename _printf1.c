#include "main.h"
/***** UNSIGNED NUM TO BE PRINTED *****/
/**
 * _print_unsigned - function to print unsigned num
 * @a: arguements
 * @buffer: an array to hold print
 * @width: specifier
 * @flags: it calculates current flags
 * @precision: for spercification
 * @size: length specifier
 * Return: character number to be printed
 */
int _print_unsigned(va_list a, char buffer[], int flags,
		int width, int precision, int size)
{
	int k = BUFF_SIZE - 2;
	unsigned long int number = va_arg(a, unsigned long int);

	number = convert_unsg(number, size);

	if (number == 0)
		buffer[k] = '\0';
	while (number > 0)
	{
		buffer[k--] = (number % 10) + '0';
		number /= 10;
	}
	k++;
	return (write_unsg(0, k, buffer, flags, width, precision, size));
}
/***** OCTAL UNSIGNED NUM TO PRINT *****/
/**
 * _print_octal - function to print unsigned octal notation
 * @a: arguements
 * @flags: to calculate the current flags
 * @buffer: an array that handle print
 * @precision: for specifying
 * @width: specifier
 * @size: length specifier
 * Return: characters to be printed
 */
int _print_octal(va_list a, char buffer[], int flags,
		int width, int precision, int size)
{
	int k = BUFF_SIZE - 2;
	unsigned long int number = va_arg(a, unsigned long int);
	unsigned long int init_number = number;

	UNUSED(width);

	number = convert_unsg(number, size);

	if (number == 0)
		buffer[k--] = '\0';
	while (number > 0)
	{
		buffer[k--] = (number % 8) + '0';
		number /= 8;
	}
	if (flags & FL_HASH && init_number != 0)
		buffer[k++] = '0';
	k++;
	return (write_unsg(0, k, buffer, flags, width, precision, size));
}
/**** PRINTING UNSIGNED NUM IN HEX ******/
/**
 * _print_hex - function to print unsuigned num in hex
 * @a: the list of arguements
 * @buffer: an array to hold print
 * @flags: to calculate the current flags
 * @width: specifier
 * @precision: for specifying
 * @size: length specifier
 * Return: character to be printed
 */
int _print_hex(va_list a, char buffer[], int flags,
		int width, int precision, int size)
{
	return (_print_hexa(a, "0123456789abcdef", buffer, flags,
				'x', width, precision, size));
}
/****** PRINTING UNSIGNED NUM IN UPPER HEXA ******/
/**
 * _print_hex_upper - function to print unsigned num in upp hex
 * @buffer: it holds an array to print
 * @a: arguements
 * @flags: to calculate the current flags
 * @width: specifier
 * @precision: for specifying
 * @size: length specifier
 * Return: characters to be printed
 */
int _print_hex_upper(va_list a, char buffer[], int flags,
		int width, int precision, int size)
{
	return (_print_hexa(a, "0123456789ABCDEF",
				buffer, flags, 'X', width, precision, size));
}
/*** PRINTING HEXA IN LOWER OR UPPER ****/
/**
 * _print_hexa - funtion to print hex num in lower or upper
 * @a: Arguements
 * @m_t: this is array to map value to a number
 * @buffer: this holds an array to print
 * @flags: to calculate the current flags
 * @width: specifier
 * @flags_sh: to calculate the active flags
 * @precision: for specifying
 * @size: specifier
 * @size: for specifying
 * Return: characters to print
 */
int _print_hexa(va_list a, char m_t[], char buffer[], int flags,
		char flags_sh, int width, int precision, int size)
{
	int k = BUFF_SIZE - 2;
	unsigned long int number = va_arg(a, unsigned long int);
	unsigned long int init_number = number;

	UNUSED(width);
	number = convert_unsg(number, size);

	if (number == 0)
		buffer[k--] = '0';
	buffer[BUFF_SIZE - 1] = '\0';
	while (number > 0)
	{
		buffer[k--] = m_t[number % 16];
	}
	if (flags & FL_HASH && init_number != 0)
	{
		buffer[k--] = flags_sh;
		buffer[k--] = '0';
	}
	k++;
	return (write_unsg(0, k, buffer, flags, width, precision, size));
}
