/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lajen-li <lajen-li@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/05 11:52:23 by lajen-li          #+#    #+#             */
/*   Updated: 2026/02/10 12:41:54 by lajen-li         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>

int	ft_printf(char const *format, ...);
int	ft_check(char specifier, va_list list_args, int count);
int	ft_putnbr_int(int n);
int	ft_putnbr_unsi(unsigned int n);
int	ft_puthex_int(unsigned int n, char *base);
int	ft_puthex_long(unsigned long long n, char *base);
int	ft_putchar_int(char c);
int	ft_putstr_int(char *s);

#endif