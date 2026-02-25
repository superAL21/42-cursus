/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lajen-li <lajen-li@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/05 11:52:23 by lajen-li          #+#    #+#             */
/*   Updated: 2026/02/17 11:55:24 by lajen-li         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>

int	ft_printf(char const *format, ...);
int	ft_check(char specifier, va_list list_args);
int	ft_putnbr_int(int n);
int	ft_putnbr_unsi(unsigned int n);
int	ft_puthex_int(unsigned long long n, char *base);
int	ft_put_ptr(void *ptr, char *base);
int	ft_putchar_int(char c);
int	ft_putstr_int(char *s);

#endif