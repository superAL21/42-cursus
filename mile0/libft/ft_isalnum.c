/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lajen-li <lajen-li@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 15:15:06 by lajen-li          #+#    #+#             */
/*   Updated: 2026/02/02 15:39:23 by lajen-li         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(int c)
{
	if ((c >= '0' && c <= '9')
		|| (c >= 'A' && c <= 'Z')
		|| (c >= 'a' && c <= 'z'))
		return (1);
	else
		return (0);
}

/* int	main(void)
{
	int	cont;
	int	var;

	cont = '/';
	var = ft_isalnum(cont) + '0';
	write (1, &var, 1);
	write (1, "\n", 1);
	return (0);
} */
