/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrouille <rrouille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 11:11:32 by rrouille          #+#    #+#             */
/*   Updated: 2023/06/08 16:21:53 by rrouille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdbool.h>
#include <stdint.h>
#include <unistd.h>

void	print_string(va_list args)
{
	char	*str;

	str = va_arg(args, char *);
	while (*str++)
		write(1, str - 1, 1);
}

void	print_number_helper(int nbr, int base, const char *digits)
{
	if (nbr >= base)
		print_number_helper(nbr / base, base, digits);
	write(1, &digits[nbr % base], 1);
}

void	print_int(va_list args)
{
	int	num;

	num = va_arg(args, int);
	if (num < 0)
	{
		write(1, "-", 1);
		num = -num;
	}
	print_number_helper(num, 10, "0123456789");
}

void	print_hex(va_list args)
{
	unsigned int	num;
	const char		*digits;

	num = va_arg(args, unsigned int);
	digits = "0123456789abcdef";
	print_number_helper(num, 16, digits);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;

	va_start(args, format);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			switch (*format)
			{
				case 's':
					print_string(args);
					break;
				case 'd':
					print_int(args);
					break;
				case 'x':
					print_hex(args);
					break;
				default:
					write(1, "%", 1);
					write(1, format, 1);
					break;
			}
		}
		else
			write(1, format, 1);
		format++;
	}
	va_end(args);
	return (0);
}

int	main(void)
{
	ft_printf("Hello, %s! The number is %d, hex is %x\n", "world", -42, 42);
	return (0);
}
