#include <stdarg.h>
#include <unistd.h>

int	ft_putstr(char *str)
{
	int len = 0;
	if (!str) str = "(null)";
	while (str[len]) len++;
	return write(1, str, len);
}

int	ft_putnbr(int n)
{
	char c;
	int count = 0;
	if (n == -2147483648)
		return write(1, "-2147483648", 11);
	if (n < 0)
	{
		count += write(1, "-", 1);
		n = -n;
	}
	if (n >= 10) count += ft_putnbr(n / 10);
	c = (n % 10) + '0';
	return count + write(1, &c, 1);
}

int	ft_puthex(unsigned int n)
{
	char *hex = "0123456789abcdef";
	if (n >= 16) return ft_puthex(n / 16) + write(1, &hex[n % 16], 1);
	return write(1, &hex[n], 1);
}

int	ft_printf(const char *fmt, ...)
{
	va_list args;
	int count = 0;

	va_start(args, fmt);
	while (*fmt)
	{
		if (*fmt == '%' && *(++fmt))
			count += (*fmt == 's') ? ft_putstr(va_arg(args, char *)) :
				 (*fmt == 'd') ? ft_putnbr(va_arg(args, int)) :
				 (*fmt == 'x') ? ft_puthex(va_arg(args, unsigned int)) : 0;
		else
			count += write(1, fmt, 1);
		fmt++;
	}
	va_end(args);
	return count;
}
