#include "main.h"

/**
 * get_wid - Entry of program
 * Description: computes width for printing
 * @format: customized string to print the arguments.
 * @a: arguments to be printed.
 * @l: arguments list.
 *
 * Return: width.
 *
 */
int get_wid(const char *format, int *a, va_list l)
{
int c, width;
c = 0;
width = 0;

for (c = *a + 1; format[c] != '\0'; c++)
{
if (is_dig(format[c]))
{
width *= 10;
width += format[c] - '0';
}
else if (format[c] == '*')
{
c++;
width = va_arg(l, int);
break;
}
else
break;
}

*a = c - 1;

return (width);
}
