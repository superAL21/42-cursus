/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lajen-li <lajen-li@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/23 14:46:01 by lajen-li          #+#    #+#             */
/*   Updated: 2026/01/23 16:23:25 by lajen-li         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*ptr;

	ptr = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		if (ptr[i] == ((unsigned char)c))
		{
			return ((void *)ptr + i);
		}
		i++;
	}
	return (NULL);
}
/*
#include <stdio.h>
int	main(void)
{
	char	FRASE[] = "No todo lo que brilla es oro";
	char	*res;

	res = ft_memchr(FRASE, 'r', 100);
	printf("Dentro de la frase...%s\n", res);
	return(0);
}
*/