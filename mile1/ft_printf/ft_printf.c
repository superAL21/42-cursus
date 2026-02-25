/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lajen-li <lajen-li@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/05 11:58:26 by lajen-li          #+#    #+#             */
/*   Updated: 2026/02/19 12:53:31 by lajen-li         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(char const *format, ...)
{
	int		count;
	va_list	args;

	if (!format)
		return (-1);
	count = 0;
	va_start(args, format);
	while (*format != '\0')
	{
		if (*format == '%' && *(format + 1) != '\0')
		{
			format++;
			count += ft_check(*format, args);
		}
		else if (*format != '%')
			count += ft_putchar_int(*format);
		format++;
	}
	va_end(args);
	return (count);
}

int	ft_check(char spec, va_list l_arg)
{
	int	count;

	count = 0;
	if (spec == 'c')
		count += ft_putchar_int(va_arg(l_arg, int));
	else if (spec == 's')
		count += ft_putstr_int(va_arg(l_arg, char *));
	else if (spec == 'd' || spec == 'i')
		count += ft_putnbr_int(va_arg(l_arg, int));
	else if (spec == 'u')
		count += ft_putnbr_unsi(va_arg(l_arg, unsigned int));
	else if (spec == 'x')
		count += ft_puthex_int(va_arg(l_arg, unsigned int), "0123456789abcdef");
	else if (spec == 'X')
		count += ft_puthex_int(va_arg(l_arg, unsigned int), "0123456789ABCDEF");
	else if (spec == 'p')
		count += ft_put_ptr(va_arg(l_arg, void *), "0123456789abcdef");
	else if (spec == 'a')
		count += ft_putstr_int("My awesome 42");
	else if (spec == '%')
		count += ft_putchar_int('%');
	return (count);
}
