/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrouille <rrouille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 11:11:32 by rrouille          #+#    #+#             */
/*   Updated: 2023/08/12 16:28:33 by rrouille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

int	print_nbr_base(unsigned int nbr, unsigned int base, const char *str_base)
{
	int	nbr_tmp;
	int	len;

	len = 0;
	if (nbr >= base)
	{
		nbr_tmp = nbr / base;
		len += print_nbr_base(nbr_tmp, base, str_base);
		len += print_nbr_base(nbr % base, base, str_base);
	}
	else
	{
		write(1, &str_base[nbr], 1);
		len++;
	}
	return (len);
}

int	print_str(char *str)
{
	int	len;

	len = 0;
	if (!str)
	{
		write(1, "(null)", 6);
		return (len + 6);
	}
	while (*str)
	{
		write(1, str, 1);
		str++;
		len++;
	}
	return (len);
}

int	print_nbr(int nbr)
{
	int	len;

	len = 0;
	if (nbr == -2147483648)
	{
		write(1, "-2147483648", 11);
		return (len + 11);
	}
	else if (nbr < 0)
	{
		write(1, "-", 1);
		nbr = -nbr;
		len++;
	}
	return (len + print_nbr_base(nbr, 10, "0123456789"));
}

int	print_hex(unsigned int hex)
{
	int	len;

	len = 0;
	if (hex == 2147483648)
	{
		write(1, "80000000", 8);
		return (len + 8);
	}
	if (hex == 4294967295)
	{
		write(1, "ffffffff", 8);
		return (len + 8);
	}
	return (len + print_nbr_base(hex, 16, "0123456789abcdef"));
}

int	ft_printf(const char *arg, ...)
{
	va_list	ap;
	int		len;

	va_start(ap, arg);
	len = 0;
	while (*arg)
	{
		if (*arg == '%')
		{
			if (*++arg == 'd')
				len += print_nbr(va_arg(ap, int));
			else if (*arg == 'x')
				len += print_hex(va_arg(ap, unsigned int));
			else if (*arg == 's')
				len += print_str(va_arg(ap, char *));
			else
			{
				write(1, "%", 1);
				write(1, arg, 1);
				len++;
			}
		}
		else
		{
			write(1, arg, 1);
			len++;
		}
		arg++;
	}
	va_end(ap);
	return (len);
}

// int	main(void)
// {
// 	ft_printf("%s\n", "Hello World!");
// 	ft_printf("%d\n", 42);
// 	ft_printf("%x\n", 42);
// }
