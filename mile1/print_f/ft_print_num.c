/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_num.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lajen-li <lajen-li@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/05 16:35:30 by lajen-li          #+#    #+#             */
/*   Updated: 2026/02/06 15:37:08 by lajen-li         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdarg.h>
#include "ft_printf.h"

int	ft_putnbr_int(int n)
{
	int	count;

	count = 0;
	if (n == -2147483648)
	{
		return (ft_putstr_int("-2147483648"));
	}
	if (n < 0)
	{
		write(1, "-", 1);
		n = -n;
		count++;
	}
	if (n >= 10)
	{
		count += ft_putnbr_int(n / 10);
	}
	count += ft_putchar_int((n % 10) + '0');
	return (count);
}

int	ft_putnbr_unsi(unsigned int n)
{
	int	count;

	count = 0;
	if (n  >= 10)
	{
		count += ft_putnbr_unsi(n / 10);
	}
	count += ft_putchar_int((n % 10) + '0');
	return (count);
}

int	ft_puthex_int(unsigned int n, char *base)
{
	int	count;

	count = 0;
	if (n >= 16)
	{
		count += ft_puthex_int(n / 16, base);
	}
	count += ft_putchar_int(base[n % 16]);
	return (count);
}

int	ft_puthex_long(unsigned long n, char *base)
{
	int	count;

	count = 0;
	if (n >= 16)
	{
		count += ft_puthex_long(n / 16, base);
	}
	count += ft_putchar_int(base[n % 16]);
	return (count);
}
