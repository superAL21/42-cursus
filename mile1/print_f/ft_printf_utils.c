/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lajen-li <lajen-li@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/05 15:05:18 by lajen-li          #+#    #+#             */
/*   Updated: 2026/02/05 18:12:38 by lajen-li         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdarg.h>
#include "ft_printf.h"

int	ft_putchar_int(char c)
{
	write(1, &c, 1);
	return (1);
}
int	ft_putstr_int(char *s)
{
	int	i;

	if(!s)
		return (0);
	i = 0;
	while (s[i])
	{
		write(1, &s[i],1);
		i++;
	}
	return (i);
}
int	ft_strlen(char *s)
{
	int	count;

	while(*s)
	{
		count++;
		s++;
	}
	return (count);
}
