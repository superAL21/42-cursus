/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lajen-li <lajen-li@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 12:14:41 by lajen-li          #+#    #+#             */
/*   Updated: 2026/02/03 16:27:54 by lajen-li         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	len_s;

	i = 0;
	len_s = ft_strlen(src);
	if (size == 0)
	{
		return (len_s);
	}
	while (src[i] != '\0' && i + 1 < size)
	{
		dst[i] = src [i];
		i++;
	}
	dst[i] = '\0';
	return (len_s);
}
/* 
#include <stdio.h>
int	main(void)
{
	char	dest[20] = "Hola a todo el mundo";
	size_t	res;

	res = ft_strlcpy(dest, "Hola Mundo", 20);
	printf("Texto original: %s | Retorno (len_src): %zu\n", dest, res);
	return (0);
} */
