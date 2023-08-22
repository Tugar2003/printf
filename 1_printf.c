#include "main.h"
/*****PRINT CHARACTER******/

/**
 * print_char - function to print character
 * @a: arguements
 * @buffer: an array to handle print
 * @flags: it calculate current flags
 * @width: width specifier
 * @size: length specifier
 * @precision: precision specifier
 * Return: character printed
 */
int print_char(va_list a, char buffer[], int flags,
		int width, int precision, int size)
{
	char w = va_arg(a, int);

	return (handle_write_char(w, buffer, flags, width, precision, size));
}
/******PRINT STRING*****/
/**
 * print_string - function to print string
 * @a: arguements
 * @buffer: an array to handle print
 * @flags: it calculate current flags
 * @precision: specifier
 * @width: specifier
 * @size: specifier
 * Return: characters to be printed
 */
int print_string(va_list a, char buffer[], int flags,
		int width, int precision, int size)
{
	int len = 0, k;
	char *str;

	str = va_arg(a, char *);
	UNUSED(buffer);
	UNUSED(size);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(flags);
	if (str == NULL)
	{
		str = "(null)";
		if (precision >= 6)
			str = "   ";
	}
	while (str[len] != '\0')
		len++;
	if (precision >= 0 && precision < len)
		len = precision;
	if (width > len)
	{
		if (flags & FL_MINUS)
		{
			write(1, &str[0], len);
			for (k = width - len; k > 0; k--)
				write(1, "", 1);
			write(1, &str[0], len);
			return (width);
		}
	}
	return (write(1, str, len));
}
/****** (%) SIGN ******/
/**
 * print_percent - funtion to print percentage sign
 * @a: arguements
 * @buffer: this is to handle buffer array
 * @flags: it calculate current flags
 * @width: specifier
 * @size: specifier
 * @precision: spercifier
 * Return: characters to be printed
 */
int print_percent(va_list a, char buffer[], int flags,
		int width, int precision, int size)
{
	UNUSED(a);
	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);

	return (write(1, "%%" 1));
}
/***** INTEGER TO PRINT *****/
/**
 * print_int - a function to print integer
 * @a: arguements
 * @buffer: an array to hold print
 * @flags: its calculate current flags
 * @precision: for specifying
 * @width: spercifier
 * @size: spercifier
 * Return: characters printed
 */
int print_int(va_list a, char buffer[], int flags,
		int width, int precision, int size)
{
	int k = BUFF_SIZE - 2;
	int neg = 0;
	unsigned long int number;
	long int c = va_arg(a, long int);

	c = conversion_num(c, size);

	if (c == 0)
		buffer[k--] = '\0';
	buffer[BUFF_SIZE - 1] = '\0';
	number = (unsigned long int)c;
	if (n < 0)
	{
		number = (unsigned long int)((-1) * c);
		neg = 1;
	}
	while (number > 0)
	{
		buffer[k--] = (number % 10) + '0';
		number /= 10;
	}
	k++;
	return (write_num(neg, k, buffer, flags, width, precision, size));
}
/**** BINARY TO BE PRINTED *****/
/**
 * print_binary - function to print unsigned num
 * @a: arguements
 * @buffer: an array yo hold buffer
 * @flags: it calculate current flags
 * @width: specifier
 * @size: its specifies size
 * @precision: specifier
 * Return: character to be printed
 */
int print_binary(va_list a, char buffer[], int flags,
		int width, int precision, int size)
{
	unsigned int s[32];
	unsigned int c, x, k, sum;
	int counter;

	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);

	c = va_arg(a, unsigned int);
	x = 2147483648;
	s[0] = c / x;

	for (k = 1; k < 32; k++)
	{
		x /= 2;
		s[k] = (c / x) % 2;
	}
	for (k = 0, sum = 0, counter = 0; k < 32; k++)
	{
		sum += s[k];
		if (sum || k == 31)
		{
			char n = '0' + s[k];

			write(1, &n, 1);
			counter++;
		}
	}
	return (counter);
}
