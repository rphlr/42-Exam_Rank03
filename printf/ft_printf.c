#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>


// #include <stdarg.h>
// #include <stdbool.h>
// #include <stdint.h>
// #include <unistd.h>

// void	print_string(va_list args)
// {
// 	char	*str;

// 	str = va_arg(args, char *);
// 	while (*str++)
// 		write(1, str - 1, 1);
// }

// void	print_nbr_base(int nbr, int base, const char *digits)
// {
// 	if (nbr >= base)
// 		print_number_helper(nbr / base, base, digits);
// 	write(1, &digits[nbr % base], 1);
// }

// void	print_int(va_list args)
// {
// 	int	num;

// 	num = va_arg(args, int);
// 	if (num < 0)
// 	{
// 		write(1, "-", 1);
// 		num = -num;
// 	}
// 	print_number_helper(num, 10, "0123456789");
// }

// void	print_hex(va_list args)
// {
// 	unsigned int	num;
// 	const char		*digits;

// 	num = va_arg(args, unsigned int);
// 	digits = "0123456789abcdef";
// 	print_number_helper(num, 16, digits);
// }

// int	ft_printf(const char *format, ...)
// {
// 	va_list	args;

// 	va_start(args, format);
// 	while (*format)
// 	{
// 		if (*format == '%')
// 		{
// 			format++;
// 			switch (*format)
// 			{
// 				case 's':
// 					print_string(args);
// 					break;
// 				case 'd':
// 					print_int(args);
// 					break;
// 				case 'x':
// 					print_hex(args);
// 					break;
// 				default:
// 					write(1, "%", 1);
// 					write(1, format, 1);
// 					break;
// 			}
// 		}
// 		else
// 			write(1, format, 1);
// 		format++;
// 	}
// 	va_end(args);
// 	return (0);
// }

// int	main(void)
// {
// 	ft_printf("Hello, %s! The number is %d, hex is %x\n", "world", -42, 42);
// 	return (0);
// }

void	print_nbr_base(int nbr, int base, const char *digits)
{
	if (nbr >= base)
		print_nbr_base(nbr / base, base, digits);
	write(1, &digits[nbr % base], 1);
}

void print_hex(va_list args)
{
        unsigned int hex = va_arg(args, unsigned int);
        const char *digits = "0123456789abcdef";
        print_nbr_base(hex, 16, digits);
}

void print_nbr(va_list args)
{
        int nbr = va_arg(args, int);
        if (nbr < 0)
        {
                write(1, "-", 1);
                nbr = -nbr;
        }
        print_nbr_base(nbr, 10, "0123456789");
}

void print_str(va_list args)
{
        char	*str;

	str = va_arg(args, char *);
	while (*str++)
		write(1, str - 1, 1);
}

void ft_printf(char *fmt, ...)
{
    va_list ap;

    va_start(ap, fmt);
    while (*fmt)
    {
        if (*fmt == '%')
        {
                fmt++;
                switch (*fmt)
                {
                        case 's':
                                print_str(ap);
                                break;
                        case 'd':
                                print_nbr(ap);
                                // d = va_arg(ap, double);
                                // printf("%c", c);
                                break;
                        case 'x':
                                print_hex(ap);
                                // x = va_arg(ap, unsigned int);
                                // printf("%c", c);
                                break;
                        default:
                                write(1, "%", 1);
                                write(1, fmt, 1);
                                break;
                }
        }
        else
                write(1, fmt, 1);
        fmt++;
    }
    va_end(ap);
}

// int main()
// {
//     ft_printf("%s\n", "toto");
//     ft_printf("Magic %s is %d", "number", 42);
//     ft_printf("\n");
//     ft_printf("Hexadecimal for %d is %x\n", 42, 42);
// }