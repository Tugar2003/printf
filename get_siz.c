#include "main.h"
/**
 * get_siz - function to calc / cast length of arguements
 * @format: this print formatted string arguements
 * @k: number of arguements
 * Return: precision
 */
int get_siz(const char *format, int *k)
{
	int siz = 0;
	int curr_k = *k + 1;

	if (format[curr_k] == 'l')
		siz = L_LONG;
	else if (format[curr_k] == 'h')
		siz = S_SHORT;
	if (siz == 0)
		*k = curr_k - 1;
	else
		*k = curr_k;

	return (siz);
}
