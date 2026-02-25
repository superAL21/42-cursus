/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lajen-li <lajen-li@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 14:02:19 by lajen-li          #+#    #+#             */
/*   Updated: 2026/02/02 15:39:54 by lajen-li         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isdigit(int c)
{
	if (c > 47 && c < 58)
		return (1);
	else
		return (0);
}

/* int	main(void)
{
	int	var;
	int	num;

	num = '8';
	var = ft_isdigit(num) + '0';
	write (1, &var, 1);
	write (1, "\n", 1);
	return (0);
} */
