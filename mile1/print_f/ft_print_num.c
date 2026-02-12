/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_num.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lajen-li <lajen-li@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/05 16:35:30 by lajen-li          #+#    #+#             */
/*   Updated: 2026/02/12 12:26:48 by lajen-li         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	if (n >= 10)
	{
		count += ft_putnbr_unsi(n / 10);
	}
	count += ft_putchar_int((n % 10) + '0');
	return (count);
}

int	ft_puthex_int(unsigned long long n, char *base)
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

int	ft_put_ptr(void *ptr, char *base)
{
	int					count;
	unsigned long long	n;

	count = 0;
	n = (unsigned long long)ptr;
	if (ptr == 0)
		return (ft_putstr_int("(nil)"));
	count += ft_putstr_int("0x");
	count += ft_puthex_int(n, base);
	return (count);
}
