/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lajen-li <lajen-li@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 13:19:42 by lajen-li          #+#    #+#             */
/*   Updated: 2026/02/02 15:40:17 by lajen-li         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_tolower(int c)
{
	if (c >= 'A' && c <= 'Z')
	{
		c = c + 32;
	}
	return (c);
}

/* int	main(void)
{
	int	print;
	int	letter;

	letter = 'X';
	print = ft_tolower (letter);
	write (1, &print, 1);
	write (1, "\n", 1);
	return (0);
} */
