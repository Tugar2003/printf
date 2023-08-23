#include "main.h"

/**
 * handle_w - Entry of program
 * Description: Prints a string
 * @c: char types.
 * @buffer: Buffer array to handle print
 * @flags:  Calculates active flags.
 * @width: get width.
 * @precision: precision specifier
 * @size: Size specifier
 *
 * Return: Number of chars printed.
 *
 */
int handle_w(char c, char buffer[], int flags, int width,
int precision, int size)
{
int a;
char p;
a = 0;
p = ' ';

UNUSED(precision);
UNUSED(size);

if (flags & FL_ZERO)
p = '0';

buffer[a++] = c;
buffer[a] = '\0';

if (width > 1)
{
buffer[BUFF_SIZE - 1] = '\0';
for (a = 0; a < width - 1; a++)
buffer[BUFF_SIZE - a - 2] = p;

if (flags & FL_MINUS)
return (write(1, &buffer[0], 1) +
write(1, &buffer[BUFF_SIZE - a - 1], width - 1));
else
return (write(1, &buffer[BUFF_SIZE - a - 1], width - 1) +
write(1, &buffer[0], 1));
}
return (write(1, &buffer[0], 1));
}
/**
 * write_number - Entry of program
 * Description: Prints a string
 * @is_positive: Lista of arguments
 * @ind: char types.
 * @buffer: Buffer array to handle print
 * @flags:  Calculates active flags
 * @width: get width.
 * @precision: precision specifier
 * @size: Size specifier
 *
 * Return: Number of chars printed.
 *
 */
int write_number(int is_positive, int ind, char buffer[], int flags, int width,
int precision, int size)
{
int l = BUFF_SIZE - ind - 1;
char p = ' ', ech = 0;

UNUSED(size);

if ((flags & FL_ZERO) && !(flags & FL_MINUS))
p = '0';
if (is_positive)
ech = '-';
else if (flags & FL_PLUS)
ech = '+';
else if (flags & FL_SPACE)
ech = ' ';
return (write_num(ind, buffer, flags, width, precision,
l, p, ech));
}

/**
 * write_num - Entry of program
 * Description: Write a number using a bufffer
 * @ind: Index at which the number starts on the buffer
 * @buffer: Buffer
 * @flags: Flags
 * @width: width
 * @prec: Precision specifier
 * @length: Number length
 * @p: Pading char
 * @ec: Extra char
 *
 * Return: Number of printed chars.
 *
 */
int write_num(int ind, char buffer[], int flags, int width, int prec,
int length, char p, char ec)
{
int i, padd_start = 1;

if (prec == 0 && ind == BUFF_SIZE - 2 && buffer[ind] == '0' && width == 0)
return (0);
if (prec == 0 && ind == BUFF_SIZE - 2 && buffer[ind] == '0')
buffer[ind] = p = ' ';
if (prec > 0 && prec < length)
p = ' ';
while (prec > length)
buffer[--ind] = '0', length++;
if (ec != 0)
length++;
if (width > length)
{
for (i = 1; i < width - length + 1; i++)
buffer[i] = p;
buffer[i] = '\0';
if (flags & FL_MINUS && p == ' ')
{
if (ec)
buffer[--ind] = ec;
return (write(1, &buffer[ind], length) + write(1, &buffer[1], i - 1));
}
else if (!(flags & FL_MINUS) && p == ' ')
{
if (ec)
buffer[--ind] = ec;
return (write(1, &buffer[1], i - 1) + write(1, &buffer[ind], length));
}
else if (!(flags & FL_MINUS) && p == '0')
{
if (ec)
buffer[--padd_start] = ec;
return (write(1, &buffer[padd_start], i - padd_start) +
write(1, &buffer[ind], length - (1 - padd_start)));
}
}
if (ec)
buffer[--ind] = ec;
return (write(1, &buffer[ind], length));
}
/**
 * write_unsg - Writes an unsigned number
 * @negative: Number indicating if the num is negative
 * @ind: Index at which the number starts in the buffer
 * @buffer: Array of chars
 * @flags: Flags specifiers
 * @width: Width specifier
 * @precision: Precision specifier
 * @size: Size specifier
 *
 * Return: Number of written chars.
 *
 */
int write_unsg(int negative, int ind, char buffer[], int flags, int width,
int precision, int size)
{
int length = BUFF_SIZE - ind - 1, i = 0;
char p = ' ';

UNUSED(negative);
UNUSED(size);

if (precision == 0 && ind == BUFF_SIZE - 2 && buffer[ind] == '0')
return (0);

if (precision > 0 && precision < length)
p = ' ';

while (precision > length)
{
buffer[--ind] = '0';
length++;
}

if ((flags & FL_ZERO) && !(flags & FL_MINUS))
p = '0';

if (width > length)
{
for (i = 0; i < width - length; i++)
buffer[i] = p;

buffer[i] = '\0';

if (flags & FL_MINUS)
{
return (write(1, &buffer[ind], length) + write(1, &buffer[0], i));
}
else
{
return (write(1, &buffer[0], i) + write(1, &buffer[ind], length));
}
}

return (write(1, &buffer[ind], length));
}

/**
 * write_p - Entry of program
 * Description: Writes memory address
 * @buffer: Arrays of chars
 * @ind: Index of number in the buffer
 * @length: Length of number
 * @width: Width specifier
 * @flags: Flags specifier
 * @p: Char representing the padding
 * @ec: Char representing extra char
 * @padd_start: Index at which padding should start
 *
 * Return: Number of written chars.
 *
 */
int write_p(char buffer[], int ind, int length, int width, int flags,
char p, char ec, int padd_start)
{
int a;

if (width > length)
{
for (a = 3; a < width - length + 3; a++)
buffer[a] = p;
buffer[a] = '\0';
if (flags & FL_MINUS && p == ' ')
{
buffer[--ind] = 'x';
buffer[--ind] = '0';
if (ec)
buffer[--ind] = ec;
return (write(1, &buffer[ind], length) + write(1, &buffer[3], a - 3));
}
else if (!(flags & FL_MINUS) && p == ' ')
{
buffer[--ind] = 'x';
buffer[--ind] = '0';
if (ec)
buffer[--ind] = ec;
return (write(1, &buffer[3], a - 3) + write(1, &buffer[ind], length));
}
else if (!(flags & FL_MINUS) && p == '0')
{
if (ec)
buffer[--padd_start] = ec;
buffer[1] = '0';
buffer[2] = 'x';
return (write(1, &buffer[padd_start], a - padd_start) +
write(1, &buffer[ind], length - (1 - padd_start) - 2));
}
}
buffer[--ind] = 'x';
buffer[--ind] = '0';
if (ec)
buffer[--ind] = ec;
return (write(1, &buffer[ind], BUFF_SIZE - ind - 1));
}
