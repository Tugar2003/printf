#include "main.h"

/**
 * is_print - Entry of program
 * Description: checks if a char is printable
 * @c: Char to be checked.
 *
 * Return: 1 if printable, 0 otherwise
 *
 */
int is_print(char c)
{
if (c >= 32 && c < 127)
return (1);

return (0);
}

/**
 * append_hexa - Entry of program
 * Description: sends ascii in hexadecimal to buffer
 * @buf: Array of chars.
 * @ind: Index to start appending.
 * @ascii_code: ASSCI CODE.
 * Return: Always 3
 *
 */
int append_hexa(char ascii_code, char buf[], int ind)
{
char map_to[] = "0123456789ABCDEF";
if (ascii_code < 0)
ascii_code *= -1;

buf[ind++] = '\\';
buf[ind++] = 'x';

buf[ind++] = map_to[ascii_code / 16];
buf[ind] = map_to[ascii_code % 16];

return (3);
}

/**
 * is_dig - Entry of program
 * Description: Verifies if a char is a digit
 * @c: Char to be checked
 *
 * Return: 1 if c is a digit, 0 otherwise
 *
 */
int is_dig(char c)
{
if (c >= '0' && c <= '9')
return (1);

return (0);
}

/**
 * convert_number - Entry of program
 * Description: changes a number to a specified size
 * @num: Number to be changed.
 * @size: Number indicating the type to be changed.
 *
 * Return: value of num
 *
 */
long int convert_number(long int num, int size)
{
if (size == L_LONG)
return (num);
else if (size == S_SHORT)
return ((short)num);

return ((int)num);
}

/**
 * convert_unsg - Entry of program
 * Description: changes a number to specified size
 * @num: Number to be changed
 * @size: Number indicating the type of change
 *
 * Return: changed value of num
 *
 */
long int convert_unsg(unsigned long int num, int size)
{
if (size == L_LONG)
return (num);
else if (size == S_SHORT)
return ((unsigned short)num);

return ((unsigned int)num);
}
