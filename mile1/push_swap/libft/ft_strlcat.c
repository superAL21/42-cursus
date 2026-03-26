/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lajen-li <lajen-li@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 16:46:39 by lajen-li          #+#    #+#             */
/*   Updated: 2026/02/03 16:25:32 by lajen-li         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	len_s;
	size_t	len_d;

	len_s = ft_strlen(src);
	if (size == 0)
	{
		return (len_s);
	}
	len_d = ft_strlen(dst);
	if (size <= len_d)
	{
		return (len_s + size);
	}
	i = 0;
	while (src[i] != '\0' && len_d + i < size -1)
	{
		dst[len_d + i] = src[i];
		i++;
	}
	dst[len_d + i] = '\0';
	return (len_s + len_d);
}

/* #include <stdio.h>
int	main(void)
{
	char	dst1[20] = "Hola";
	char	*src1;
	size_t	res;
	
	src1 = " Mundo";
	res = ft_strlcat(dst1, src1, 20);
	printf("Resultado: %zu\n", res);
	return (0);
} */
