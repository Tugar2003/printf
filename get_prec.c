#include "main.h"

/**
 * get_prec - function that calc the precision to print
 * @format: this print formatted string
 * @a: arguements
 * @k: arguements to be printed
 * Return: precision
 */
int get_prec(const char *format, int *k, va_list a)
{
	int prec = -1;
	int curr_k = *k + 1;

	if (format[curr_k] != '.')
		return (prec);
	prec = 0;
	for (curr_k + 1; format[curr_k] != '\0'; curr_k++)
	{
		if (dig(format[curr_k]))
		{
			prec *= 10;
			prec += format[curr_k] - '0';
		}
		else if (format[curr_k] == '*')
		{
			curr_k++;
			prec = va_arg(a, int);
			break;
		}
		else
			break;
	}
	*k = curr_k - 1;

	return (prec);
}
