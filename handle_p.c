#include "main.h"
/**
 * handle_p - Prints argument based on type
 * @fmt: Formatted string to print the arguments.
 * @l: arguments to be printed.
 * @ind: ind.
 * @buffer: Array to handle print.
 * @flags: computes active flags
 * @width: get width.
 * @precision: Precision specification
 * @size: Size specifier
 * Return: 1 or 2;
 *
 */
int handle_p(const char *fmt, int *ind, va_list l, char buffer[], int flags,
int width, int precision, int size)
{
int a, kl, pc;
kl = 0;
pc = -1;
fmt_t fmt_types[] = {
{'c', print_char}, {'s', print_string}, {'%', print_percent},
{'i', print_int}, {'d', print_int}, {'b', print_binary},
{'u', print_unsigned}, {'o', print_octal}, {'x', print_hexadecimal},
{'X', print_hexa_upper}, {'p', print_pointer}, {'S', print_non_printable},
{'r', print_reverse}, {'R', print_rot13string}, {'\0', NULL}
};
for (a = 0; fmt_types[a].fmt != '\0'; a++)
if (fmt[*ind] == fmt_types[a].fmt)
return (fmt_types[a].fn(l, buffer, flags, width, precision, size));

if (fmt_types[a].fmt == '\0')
{
if (fmt[*ind] == '\0')
return (-1);
kl += write(1, "%%", 1);
if (fmt[*ind - 1] == ' ')
kl += write(1, " ", 1);
else if (width)
{
--(*ind);
while (fmt[*ind] != ' ' && fmt[*ind] != '%')
--(*ind);
if (fmt[*ind] == ' ')
--(*ind);
return (1);
}
kl += write(1, &fmt[*ind], 1);
return (kl);
}
return (pc);
}
