#include <unistd.h>

/**
 * _putchar - Entry of the prototype
 *
 * Descriptiom: creates the letter c
 * @c: will be the character to print
 *
 * Return: 1 as (succcess)
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}
