/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lajen-li <lajen-li@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 11:24:22 by lajen-li          #+#    #+#             */
/*   Updated: 2026/02/03 15:03:16 by lajen-li         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isprint(int c)
{
	return (c >= 32 && c <= 126);
}

/* int	main(void)
{
	int	num;
	int	var;

	num = 'L';
	var = ft_isprint(num) + '0';
	write (1, &var, 1);
	write (1, "\n", 1);
	return (0);
} */