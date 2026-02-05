/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_num.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lajen-li <lajen-li@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/05 16:35:30 by lajen-li          #+#    #+#             */
/*   Updated: 2026/02/05 18:40:41 by lajen-li         ###   ########.fr       */
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
		return(ft_putstr_int("-2147483648"));
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
int	ft_puthex(unsigned long long n, char *base)
{
	int	count;
	unsigned long long	l_base;

	count = 0;
	l_base = ft_strlen(base);
	if (n >= l_base)
	{
		count += ft_puthex(n / l_base, base);
	}
	count += ft_putchar_int(base[n % l_base]);
	return (count);
	
}
