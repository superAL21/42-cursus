/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lajen-li <lajen-li@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/05 11:52:23 by lajen-li          #+#    #+#             */
/*   Updated: 2026/02/05 18:14:12 by lajen-li         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define    FT_PRINTF_H

#include <unistd.h>

int	ft_printf(char const *str, ...);
int	ft_check(char specifier, va_list list_args);
int	ft_putnbr_int(int n);
int	ft_puthex_int(unsigned int n);
int	ft_putchar_int(char c);
int	ft_putstr_int(char *s);
int	ft_strlen(char *s);

#endif