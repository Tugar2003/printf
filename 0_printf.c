#include "main.h"
void print_buffer(char buffer[], int *buff_ind);
/**
 * _printf - cutomized printf function
 * @format: format string
 *
 * Return: Print characters
 */
int _printf(const char *format, ...)
{
	int k, p = 0, pc = 0;
	int width, flags, precision, size, buff_ind = 0;
	char buffer[BUFF_SIZE];
	va_list a;

	va_start(a, fmt);

	if (format == NULL)
		return (-1);

	for (k = 0; format && format[k] != '\0'; k++)
	{
		if (format[k] != '%')
		{
			buffer[buff_ind++] = format[k];
			if (buff_ind == BUFF_SIZE)
				print_buffer(buffer, &buff_ind);
			pc++;
		}
		else
		{
			print_buffer(buffer, &buff_ind);
			flags = get_flag(formatt, &k);
			width = get_wid(format, &k, a);
			precision = get_prec(format, &k, a);
			size = get_siz(format, &k);
			++k;
			p = handle_print(format, &k, a, buffer, flags, width, precision, size);
			if (p == -1)
				return (-1);
			pc += p;
		}
	}
	print_buffer(buffer, &buff_ind);

	va_end(a);
	return (pc);
}

/**
 * print_buffer - see the content of buffer when it exist
 * @buffer: array characters
 * @buff_ind:represent the length of index to the next character
 */
void print_buffer(char buffer[], int *buff_ind)
{
	if (*buff_ind > 0)
		write(1, &buffer[0], *buff_ind);
	*buff_ind = 0;
}
