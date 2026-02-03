/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lajen-li <lajen-li@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 12:58:16 by lajen-li          #+#    #+#             */
/*   Updated: 2026/02/03 13:56:05 by lajen-li         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*ptr_d;
	unsigned char	*ptr_s;
	size_t			i;

	ptr_d = (unsigned char *)dest;
	ptr_s = (unsigned char *)src;
	i = 0;
	if (!dest && !src)
	{
		return (NULL);
	}
	while (i < n)
	{
		ptr_d[i] = ptr_s[i];
		i++;
	}
	return (dest);
}
/* #include <stdio.h>

int	main(void)
{
	char		text1[] = "Holaaaa";
	void		*res;
	const char	*text2;
	
	text2 = "aa";
	res = ft_memcpy(text1, text2, 2);
	printf("Este es el resultado: %s\n", (char *)res);
	return (0);
} */