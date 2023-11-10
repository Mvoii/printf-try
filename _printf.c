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


int print_char(int c)
{
    return write(1, &c, 1);
}

int print_string(char *str)
{
    int count;

    count - 0;
    while(*str != '\0')
    {
        print_char((int)*str);
        count++;
        str++;
    }
    return count;
}


int print_digit(long n, int base)
{
    int count;
    char *symbols;

    symbols = "0123456789abcdef";
    if (n < 0)
    {
        write(1, "-", 1);
        return print_digit(-n, base) + 1;
    }
    else if (n < base)
        return print_char(symbols[n]);

    else
    {
        count = print_digit(n / base, base);
        return count + print_digit(n % base, base);
    }
    
}

int print_format(char specifier, va_list ap)
{
    int count = 0;

    if (specifier == 'c')
        count += print_char(va_arg(ap, int));
    
    else if (specifier == 's')
        count += print_string(va_arg(ap, char *));

    else if (specifier == 'd')
        count += print_digit((long)(va_arg(ap, int)), 10);

    else if (specifier == 'x')
        count += print_digit((long)(va_arg(ap, unsigned int)), 16);
    
    else
        count += write(1, &specifier, 1);
    
    return count;
    /**
     * promotion of data types to higher data types eg int to float
     * char and short to int, float becomes double
     * 
    */
}




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


int main()
{
    int count;

    //count = _printf("hello, %s\n", "John");
    _printf("Hello %s, today is %d, in hex %x, char->%c\n", "John", 27, 27, 'z');
/*    count = _printf("%d\n", __INT32_MAX__);
    _printf("the chars written are %d\n", count);

    count = printf("%d\n", __INT32_MAX__);
    printf("The chars written are %d\n", count);
*/
    return 0;
}