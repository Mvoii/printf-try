#include <stdio.h>
#include <string.h>
#include "main.h"

/**
 * _prntf - produces output according to a format
 * 
 * @format: a character string
 * 
 * Return: The number of characters tat were printed
*/
int _printf(const char *format, ...)
{
    va_list ap;
    int count;

    va_start(ap, format);
    count = 0;
    while (*format != '\0')
    {
        if ((*format) == '%')
            count += print_format(*(++format), ap);
        
        else
        //return amount of bytes
            count += write(1, format, 1);
        ++format;
    }
    va_end(ap);
    return count;
}

int print_format(char specifier, va_list ap)
{
    int count = 0;

    if (specifier == 'c')
        count += print_char(va_arg(ap, int));
    
    else if (specifier == 's')
        count += print_string(va_arg(ap, char *));

    else if (specifier == 'd')
        count += print_digit(va_arg(ap, int));

    else if (specifier == 'x')
        count += print_digit(va_arg(ap, unsigned int), 16);
    
    else
        count += write(1, &specifier, 1);
    
    return count;
    /**
     * promotion of data types to higher data types eg int to float
     * char and short to int, float becomes double
     * 
    */
}

int main()
{
    int count;

    count = _printf("hello, %s\n", "John");
    _printf("The chars written are %d\n",count);

    return 0;
}