/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lajen-li <lajen-li@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 17:10:22 by lajen-li          #+#    #+#             */
/*   Updated: 2026/02/03 17:12:33 by lajen-li         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*last;
	size_t	len;

	len = ft_strlen(s);
	last = (char *)s + len;
	while (last >= s)
	{
		if (*last == (char)c)
		{
			return (last);
		}
		last--;
	}
	return (NULL);
}
/* 
#include <stdio.h>

int main(void)
{
    char *res;
    size_t place;
    
    res = ft_strrchr("abcdefghi", 'e');
    place = res - "abcdefghi";
    printf("%zu\n", place);
    return (0);
} */