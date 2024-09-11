#include <stdarg.h>
#include <unistd.h>

static int ft_putchar(char c) {
	return write(1, &c, 1);
}

static int ft_putstr(char *str) {
	int len = 0;
	if (!str) str = "(null)";
	while (str[len]) len++;
	return write(1, str, len);
}

static int ft_putnbr(int n) {
	char c;
	int count = 0;
	if (n == -2147483648) return write(1, "-2147483648", 11);
	if (n < 0) { count += ft_putchar('-'); n = -n; }
	if (n >= 10) count += ft_putnbr(n / 10);
	c = (n % 10) + '0';
	return count + ft_putchar(c);
}

static int ft_puthex(unsigned int n) {
	char *hex = "0123456789abcdef";
	if (n >= 16) return ft_puthex(n / 16) + write(1, &hex[n % 16], 1);
	return write(1, &hex[n], 1);
}

int ft_printf(const char *fmt, ...) {
	va_list args;
	int count = 0;

	va_start(args, fmt);
	while (*fmt) {
		if (*fmt == '%') {
			fmt++;
			if (*fmt == 's') count += ft_putstr(va_arg(args, char *));
			else if (*fmt == 'd') count += ft_putnbr(va_arg(args, int));
			else if (*fmt == 'x') count += ft_puthex(va_arg(args, unsigned int));
		} else {
			count += ft_putchar(*fmt);
		}
		fmt++;
	}
	va_end(args);
	return count;
}
