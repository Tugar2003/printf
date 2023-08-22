#include "main.h"

/**
 * get_flag - function to calc the current flags
 * @k: this takes parameter
 * @format: this takes in formatted string to print
 * Return: current flags
 */
int get_flag(const char *format, int *k)
{
	int flag = 0;
	int s, curr_k;
	const int FLAG_ARR[] = {FL_MINUS, FL_PLUS, FL_ZERO,
		FL_HASH, FL_SPACE, 0};
	const char FLAG_CH[] = {'-', '+', '0', '#', '', '\0'};

	for (curr_k = *k + 1; format[curr_k] != '\0', curr_k++)
	{
		for (s = 0; FLAG_ch[s] != '\0'; s++)
			if (format[curr_k] == FLAG_CH[S])
			{
				flag |= FLAG_ARR[s];
				break;
			}
		if (FLAG_CH[s] == 0)
			break;
	}
	*k = curr_k - 1;
	return (flag);
}
