/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lajen-li <lajen-li@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 15:50:39 by lajen-li          #+#    #+#             */
/*   Updated: 2026/02/03 13:24:59 by lajen-li         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*ptr_1;
	unsigned char	*ptr_2;

	ptr_1 = (unsigned char *)s1;
	ptr_2 = (unsigned char *)s2;
	i = 0;
	while (i < n)
	{
		if (ptr_1[i] != ptr_2[i])
		{
			return (ptr_1[i] - ptr_2[i]);
		}
		i++;
	}
	return (0);
}
/* #include <stdio.h>

int	main(void)
{
	const void	*text1;
	const void	*text2;
	int			res;

	text1 = "Hola mundo";
	text2 =	"Hola m";
	res = ft_memcmp(text1, text2, 6);
	printf("resultado: %d\n", res);
	return(0);
} */