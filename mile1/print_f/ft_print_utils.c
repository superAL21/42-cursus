/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lajen-li <lajen-li@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/05 15:05:18 by lajen-li          #+#    #+#             */
/*   Updated: 2026/02/10 12:39:44 by lajen-li         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar_int(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putstr_int(char *s)
{
	int	i;

	if (!s)
		return (ft_putstr_int("(null)"));
	i = 0;
	while (s[i])
	{
		write(1, &s[i], 1);
		i++;
	}
	return (i);
}
