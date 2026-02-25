/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lajen-li <lajen-li@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 11:50:26 by lajen-li          #+#    #+#             */
/*   Updated: 2026/01/20 14:52:40 by lajen-li         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *s)
{
	size_t	count;

	count = 0;
	while (*s)
	{
		count++;
		s++;
	}
	return (count);
}

/*
int	main(void)
{
	char	*text;
	char	len;

	text = "Lesly";
	len = ft_strlen(text) + '0';
	write (1, &len, 1);
	write (1, "\n", 1);
	return (0);
}
*/