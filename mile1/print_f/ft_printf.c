/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lajen-li <lajen-li@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/05 11:58:26 by lajen-li          #+#    #+#             */
/*   Updated: 2026/02/06 16:01:27 by lajen-li         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdarg.h>
#include "ft_printf.h"

int	ft_printf(char const *str, ...)
{
	int		count;
	va_list	args;

	count = 0;
	va_start(args, str);
	while (*str != '\0')
	{
		if (*str == '%')
		{
			str++;
			count += ft_check(*str, args, 0);
		}
		else
			count += ft_putchar_int(*str);
		str++;
	}
	va_end(args);
	return (count);
}

int	ft_check(char spec, va_list list_args, int count)
{
	unsigned long ul;
	
	if (spec == 'c')
		count += ft_putchar_int(va_arg(list_args, int));
	else if (spec == 's')
		count += ft_putstr_int(va_arg(list_args, char *));
	else if (spec == 'd' || spec == 'i')
		count += ft_putnbr_int(va_arg(list_args, int));
	else if (spec == 'u')
		count += ft_putnbr_unsi(va_arg(list_args, unsigned int));
	else if (spec == 'x')
		count += ft_puthex_int(va_arg(list_args, unsigned int), "0123456789abcdef");
	else if (spec == 'X')
		count += ft_puthex_int(va_arg(list_args, unsigned int), "0123456789ABCDEF");
	else if (spec == 'p')
	{
		ul = va_arg(list_args, unsigned long);
		if (ul == 0)
			return (ft_putstr_int("(nil)"));
		count += ft_putstr_int("0x");
		count += ft_puthex_long(ul, "0123456789abcdef");
	}
	else if (spec == '%')
		count += ft_putchar_int('%');
	return (count);
}

#include <stdio.h>
#include <limits.h>
#include "ft_printf.h"

int main(void)
{
    int len;
    int len_ft;

    printf("--- TEST CASE: Caracteres y Strings ---\n");
    len = printf("Original: %c %s %%\n", 'A', "Hola Mundo");
    len_ft = ft_printf("Mine    : %c %s %%\n", 'A', "Hola Mundo");
    printf("Return -> Orig: %d | Mine: %d\n\n", len, len_ft);

    printf("--- TEST CASE: Punteros ---\n");
    void *ptr = &len;
    len = printf("Original: %p %p\n", ptr, NULL);
    len_ft = ft_printf("Mine    : %p %p\n", ptr, NULL);
    printf("Return -> Orig: %d | Mine: %d\n\n", len, len_ft);

    printf("--- TEST CASE: Números Enteros (d/i) ---\n");
    len = printf("Original: %d %i %d %d\n", 0, -42, INT_MAX, INT_MIN);
    len_ft = ft_printf("Mine    : %d %i %d %d\n", 0, -42, INT_MAX, INT_MIN);
    printf("Return -> Orig: %d | Mine: %d\n\n", len, len_ft);

    printf("--- TEST CASE: Unsigned y Hexadecimal ---\n");
    len = printf("Original: %u %x %X %x\n", 4294967295U, 255, 255, 0);
    len_ft = ft_printf("Mine    : %u %x %X %x\n", 4294967295U, 255, 255, 0);
    printf("Return -> Orig: %d | Mine: %d\n\n", len, len_ft);

    printf("--- TEST CASE: String NULL ---\n");
    // Nota: Algunos sistemas imprimen (null), comprueba tu sistema
    len_ft = ft_printf("Mine    : %s\n", (char *)NULL);
    printf("Return -> Orig: %d | Mine: %d\n\n", len, len_ft);

    return (0);
}