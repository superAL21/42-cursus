/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lajen-li <lajen-li@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 13:31:05 by lajen-li          #+#    #+#             */
/*   Updated: 2026/01/20 13:26:15 by lajen-li         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	ch;

	ch = (char)c;
	while (*s != '\0')
	{
		if (*s == ch)
		{
			return ((char *)s);
		}
		s++;
	}
	if (ch == '\0')
	{
		return ((char *)s);
	}
	return (NULL);
}
/*
int	main(void)
{
	char	*var;

	var = ft_strchr("Una cadena de texto", 'd');
	if (var != NULL)
	{
		write (1, var, 1);
		write (1, "\n", 1);
	}
	return (0);
}
*/