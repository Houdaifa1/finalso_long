/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdrahm <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 22:27:40 by hdrahm            #+#    #+#             */
/*   Updated: 2023/12/22 16:42:18 by hdrahm           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_putnbr(int n, int base, char *hex)
{
	long	x;
	int		count;

	x = n;
	count = 0;
	if (base == 16)
		x = (unsigned int)x;
	if (x < 0)
	{
		write(1, "-", 1);
		x = -x;
		count++;
	}
	if (x >= base)
	{
		count = count + ft_putnbr(x / base, base, hex);
		count = count + ft_putnbr(x % base, base, hex);
	}
	if (x < base)
	{
		count++;
		write(1, &hex[x], 1);
	}
	return (count);
}

int	ft_unsigned(unsigned int u)
{
	int		count;
	char	c;

	count = 0;
	if (u >= 10)
	{
		count += ft_unsigned(u / 10);
		count += ft_unsigned(u % 10);
	}
	if (u < 10)
	{
		count++;
		c = u + 48;
		write(1, &c, 1);
	}
	return (count);
}

int	ft_ptradd(unsigned long n)
{
	char	*hex;
	int		count;

	hex = "0123456789abcdef";
	count = 0;
	if (n >= 16)
	{
		count += ft_ptradd(n / 16);
		count += ft_ptradd(n % 16);
	}
	if (n < 16)
	{
		count++;
		write(1, &hex[n], 1);
	}
	return (count);
}

int	ft_operation(va_list ap, char o)
{
	int	count;

	count = 0;
	if (o == 'c')
		count += ft_putchar(va_arg(ap, int));
	if (o == 'i' || o == 'd')
		count += ft_putnbr(va_arg(ap, int), 10, "0123456789abcdef");
	if (o == 'x')
		count += ft_putnbr(va_arg(ap, int), 16, "0123456789abcdef");
	if (o == 'X')
		count += ft_putnbr(va_arg(ap, int), 16, "0123456789ABCDEF");
	if (o == 's')
		count += ft_putstr(va_arg(ap, char *));
	if (o == 'u')
		count += ft_unsigned(va_arg(ap, unsigned int));
	if (o == 'p')
	{
		write(1, "0x", 2);
		count += 2;
		count += ft_ptradd(va_arg(ap, unsigned long));
	}
	return (count);
}

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int		count;

	va_start(ap, format);
	count = 0;
	while (*format != '\0')
	{
		if (*format == '%')
		{
			format++;
			count += ft_operation(ap, *format);
			if (*format == '%')
				count += write(1, "%", 1);
			if (*format == '\0')
				format--;
		}
		else
			count += ft_putchar(*format);
		format++;
	}
	va_end(ap);
	return (count);
}
