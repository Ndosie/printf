#include "main.h"

/**
 * _printf - the function which formats the string as per specifier
 * @format: string to format
 *
 * Return: number of characters printed to the standard output
*/
int _printf(const char *format, ...)
{
	int ch;
	int count;
	va_list args_list;

	va_start(args_list, format);
	count = 0;
	indx = 0;

	while (*format != '\0')
	{
		if (*format != '%')
		{
			count++;
			putchar(*format);
		}
		else
		{
			switch (*++format)
			{
				case 'c':
					ch = va_arg(args_list, char);
					count++;
					putchar(ch);
					break;
				case 's':
					char *str = va_arg(args_list, char *);

					while (*str)
					{
						putchar(*str);
						*str++;
						count++;
					}
					break;
				case '%':
					count++;
					putchar('%');
					break;
				default:
					break;
			}
		}
		format++;
	}
	va_end(args_list);
	return (count);
}
