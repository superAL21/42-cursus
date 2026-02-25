/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lajen-li <lajen-li@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 17:22:32 by lajen-li          #+#    #+#             */
/*   Updated: 2026/02/03 11:14:59 by lajen-li         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*ptr_d;
	unsigned char	*ptr_s;

	if (!dest && !src)
		return (NULL);
	ptr_d = (unsigned char *)dest;
	ptr_s = (unsigned char *)src;
	if (dest == src)
		return (dest);
	if (ptr_d < ptr_s)
	{
		while (n--)
			*ptr_d++ = *ptr_s++;
	}
	else
	{
		while (n--)
			ptr_d[n] = ptr_s[n];
	}
	return (dest);
}
/* 
#include <stdio.h>
int	main(void)
{
	char dest[] = "I HATE YOU";
	char *src = "LOVE";
	
	ft_memmove(dest +2, src, 4);
	printf("Este es el nuevo texto %s\n", dest);
	return (0);
} */