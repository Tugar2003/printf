#ifndef MAIN_H
#define MAIN_H
#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

#define UNUSED(x) (void)(x)
#define BUFF_SIZE 1024

#define FL_MINUS 1
#define FL_PLUS 2
#define FL_ZERO 4
#define FL_HASH 8
#define FL_SPACE 16

#define L_LONG 2
#define S_SHORT 1

/**
 * struct fmt - Structure op
 *
 * @fmt: format.
 * @fn: associated function.
 *
 */
struct fmt
{
char fmt;
int (*fn)(va_list, char[], int, int, int, int);
};

/**
 * typedef struct fmt fmt_t - Structure op
 *
 * @fmt: format.
 * @fm_t: associated function.
 *
 *
 */
typedef struct fmt fmt_t;

int _printf(const char *format, ...);
int handle_p(const char *fmt, int *ind, va_list l, char buffer[], int flags,
int width, int precision, int size);
void print_buffer(char buffer[], int *buff_ind);
int _putchar(char c);


int print_char(va_list a, char buffer[], int flags, int width,
int precision, int size);
int print_string(va_list a, char buffer[], int flags, int width,
int precision, int size);
int print_percent(va_list a, char buffer[], int flags, int width,
int precision, int size);

int print_int(va_list a, char buffer[], int flags, int width,
int precision, int size);
int print_binary(va_list a, char buffer[], int flags, int width,
int precision, int size);
int _print_unsigned(va_list a, char buffer[], int flags, int width,
int precision, int size);
int _print_octal(va_list a, char buffer[], int flags, int width,
int precision, int size);
int _print_hex(va_list a, char buffer[], int flags, int width,
int precision, int size);
int _print_hex_upper(va_list a, char buffer[], int flags, int width,
int precision, int size);

int _print_hexa(va_list a, char m_t[], char buffer[], int flags,
char flag_sh, int width, int precision, int size);

int print_non_printable(va_list a, char buffer[], int flags, int width,
int precision, int size);

int _print_pointer(va_list a, char buffer[], int flags, int width,
int precision, int size);

int get_flag(const char *format, int *k);
int get_wid(const char *format, int *a, va_list l);
int get_prec(const char *format, int *k, va_list a);
int get_siz(const char *format, int *k);

int print_reverse(va_list a, char buffer[], int flags, int width,
int precision, int size);

int _print_rot13string(va_list a, char buffer[], int flags, int width,
int precision, int size);

int handle_w(char c, char buffer[], int flags, int width,
int precision, int size);
int write_number(int is_positive, int ind, char buffer[], int flags, int width,
int precision, int size);
int write_num(int ind, char buffer[], int flags, int width, int precision,
int length, char padd, char extra_c);
int write_p(char buffer[], int ind, int length, int width, int flags,
char p, char ec, int padd_start);

int write_unsg(int negative, int ind, char buffer[],

int flags, int width, int precision, int size);

int is_print(char);
int is_dig(char);
int append_hexa_code(char ascii_code, char buffer[], int i);

long int convert_number(long int num, int size);
long int convert_unsg(unsigned long int num, int size);

#endif
