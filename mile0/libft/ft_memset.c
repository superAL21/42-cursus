/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lajen-li <lajen-li@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 18:12:05 by lajen-li          #+#    #+#             */
/*   Updated: 2026/02/03 14:04:02 by lajen-li         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*ptr;

	ptr = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		ptr[i] = (unsigned char)c;
		i++;
	}
	return (s);
}
/* #include <stdio.h>

int	main(void)
{
	char	text1[] = "Hola mundo";
	void	*res;
	
	res = ft_memset(text1, 'a', 4);
	printf("Este es el resultado : %s\n", (char *)res);
	return (0);
	
} */