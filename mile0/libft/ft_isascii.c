/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lajen-li <lajen-li@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 15:44:42 by lajen-li          #+#    #+#             */
/*   Updated: 2026/02/02 15:39:46 by lajen-li         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isascii(int c)
{
	if (c >= 0 && c <= 127)
		return (1);
	else
		return (0);
}

/* 
int	main(void)
{
	int	var;
	int	out;

	var = 'A';
	out = ft_isascii(var) + '0';
	write (1, &out, 1);
	write (1, "\n", 1);
	return (0);
} 
*/
