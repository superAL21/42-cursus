/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lajen-li <lajen-li@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 18:37:54 by lajen-li          #+#    #+#             */
/*   Updated: 2026/01/29 12:10:33 by lajen-li         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	end;
	char	*new;

	if (!s1 || !set)
		return (NULL);
	start = 0;
	while (s1[start] && ft_strchr(set, s1[start]))
		start++;
	end = ft_strlen(s1);
	while (end > start && ft_strchr(set, s1[end - 1]))
		end--;
	new = ft_substr(s1, start, end - start);
	return (new);
}
/*
#include <stdio.h>

int	main(void)
{
	const char	*text;
	const char	*set;
	char	*res;

	text = "--Lesly--Ajen--Licas----";
	set = "-";
	res = ft_strtrim(text, set);
	printf("Resultado : %s\n", res);
	free(res);
	return(0);
}
*/