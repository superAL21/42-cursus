/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lajen-li <lajen-li@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 11:16:56 by lajen-li          #+#    #+#             */
/*   Updated: 2026/02/23 18:35:43 by lajen-li         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalpha(char c)
{
	return ((c > 64 && c < 91) || (c > 96 && c < 123));
}

/* int	main(void)
{
	char	letter;
	int		var;

	letter = 'l';
	var = ft_isalpha(letter) + '0';
	write (1, &var, 1);
	write (1, "\n", 1);
	return (0);
}
 */