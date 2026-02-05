/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lajen-li <lajen-li@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/05 11:58:26 by lajen-li          #+#    #+#             */
/*   Updated: 2026/02/05 18:42:49 by lajen-li         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdarg.h>
#include "ft_printf.h"

int	ft_printf(char const *str, ...)
{
	int		count;
	va_list	args;

	va_start(args, int);
	while (*str != '\0')
	{
		if(str == '%')
		{
			str++;
			ft_check(str,va_list);
		}
		str++;
		count++;
	}
	va_end(args);
	return (count);

}
 int	ft_check(char specifier, va_list list_args)
 {
	int	count;
	
	count = 0;
	if (specifier == 'c')
	{
		count += ft_putchar_int(va_arg(list_args, int));
	}
	else if (specifier == 's')
	{
		count += ft_putstr_int(va_arg(list_args, char *));
	}
	else if (specifier == 'd' || specifier == 'i')
	{
		count += ft_putnbr_int(va_arg(list_args, int));
	}
	else if (specifier == 'u')
	{
		count += ft_puthex(va_arg(list_args, unsigned int), "0123456789");
	}
	else if (specifier == 'x')
	{
		count += ft_puthex(va_arg(list_args, unsigned int), "0123456789abcdef");
	}
	else if (specifier == 'X')
	{
		count += ft_puthex(va_arg(list_args, unsigned int), "0123456789ABCDEF");
	}
	else if (specifier == 'p')
	{
		count += ft_
	}
	else if (specifier == '%')
	{
		count += ft_putchar_int('%');
	}
	return (count);
 }
