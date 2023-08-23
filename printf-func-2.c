#include "main.h"
/**** PRINTING POINTER *****/
/**
 * _print_pointer - function to print a pointer value
 * @buffer: an array to hold print
 * @a: arguements
 * @flags: to calc the current flags
 * @width: specifier
 * @precision: for specifying
 * @size: length specifier
 * Return: character to be printed
 */
int _print_pointer(va_list a, char buffer[], int flags,
		int width, int precision, int size)
{
	char ex_s = 0, caad = ' ';
	unsigned long numb_addr;
	int init = BUFF_SIZE - 2, len = 2, caad_start = 1;
	char m_t[] = "0123456789abcdef";
	void *addr = va_arg(a, void *);

	UNUSED(width);
	UNUSED(size);

	if (addr == NULL)
		return (write(1, "(nil)", 5));

	buffer[BUFF_SIZE - 1] = '\0';
	UNUSED(precision);

	numb_addr = (unsigned long)addr;
	while (numb_addr > 0)
	{
		buffer[init--] = m_t[numb_addr % 16];
		numb_addr /= 16;
		len++;
	}
	if ((flags & FL_ZERO) && !(FL_MINUS))
		caad = '0';
	if (flags & FL_PLUS)
		ex_s = '+', len++;
	else if (flags & FL_SPACE)
		ex_s = ' ', len++;
	init++;

	return (write_p(buffer, init, len, width, flags, caad, ex_s, caad_start));
}
/***** PRINTING THE NON PRINTABLE *****/
/**
 * print_non_printable - function to print the ascii codes in hex
 * @a: arguements
 * @buffer: this holds the array to be printed
 * @flags: it calc the current flags
 * @width: specifier
 * @precision: for specifying
 * @size: length specifier
 * Return: char to be printed
 */
int print_non_printable(va_list a, char buffer[], int flags,
		int width, int precision, int size)
{
	int k = 0, offst = 0;
	char *str;

	str = va_arg(a, char *);

	UNUSED(width);
	UNUSED(flags);
	UNUSED(precision);
	UNUSED(size);

	if (str == NULL)
		return (write(1, "(nil)", 6));
	while (str[k] != '\0')
	{
		if (is_print(str[k]))
			buffer[k + offst] = str[k];
		else
			offst += append_hexa(str[k], buffer, k + offst);
		k++;
	}
	buffer[k + offst] = '\0';
	return (write(1, buffer, k + offst));
}
/**** STRING PRINTING IN REVERSE *****/
/**
 * print_reverse - function that print string in reverse
 * @a: arguements
 * @buffer: this holds the array to be printed
 * @flags: it calc the current flags
 * @width: specifier
 * @precision: for specifying
 * @size: length specifier
 * Return: char to be printed
 */
int print_reverse(va_list a, char buffer[], int flags,
		int width, int precision, int size)
{
	int k, counter = 0;
	char *str;
	char v;

	UNUSED(width);
	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(size);

	str = va_arg(a, char *);
	if (str == NULL)
	{
		UNUSED(precision);
		str = ")Null(";
	}
	for (k = 0; str[k]; k++)
		;

	for (k = k - 1; k >= 0; k--)
	{
		v = str[k];

		write(1, &v, 1);
		counter++;
	}
	return (counter);
}
/**** PRINTING STRING IN ROT13 *****/
/**
 * _print_rot13string - function to print string in rot13
 * @a: arguements
 * @buffer: this holds the array to be printed
 * @flags: it calc the current flags
 * @width: specifier
 * @precision: for specifying
 * @size: length specifier
 * Return: char to be printed
 */
int _print_rot13string(va_list a, char buffer[], int flags,
		int width, int precision, int size)
{
	char *str;
	char b;
	int counter = 0;
	unsigned int k, s;
	char tk[] =
	"ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrtsuvwxyz";
	char br[] =
	"NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";
	str = va_arg(a, char *);

	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);

	if (str == NULL)
		str = "(AHYY)";
	for (k = 0; str[k]; k++)
	{
		for (s = 0; tk[s]; s++)
		{
			if (tk[s] == str[k])
			{
				b = br[s];
				write(1, &b, 1);
				counter++;
				break;
			}
		}
		if (!tk[s])
		{
			b = str[k];
			write(1, &b, 1);
			counter++;
		}
	}
	return (counter);
}
