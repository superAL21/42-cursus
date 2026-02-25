/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lajen-li <lajen-li@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 18:02:22 by lajen-li          #+#    #+#             */
/*   Updated: 2026/01/27 13:37:30 by lajen-li         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	len_1;
	size_t	len_2;
	char	*new;

	if (!s1 || !s2)
		return (NULL);
	len_1 = ft_strlen(s1);
	len_2 = ft_strlen(s2);
	new = malloc((len_1 + len_2 + 1) * sizeof(char));
	if (!new)
		return (NULL);
	ft_strlcpy(new, s1, len_1 + len_2 + 1);
	ft_strlcat(new, s2, len_1 + len_2 + 1);
	return (new);
}
/*
#include <stdio.h>
int	main(void)
{
	const char	*text1;
	const char	*text2;
	char		*text3;
	
	text1 = "Ser o no ser ";
	text2 = "he ahí el dilema...";
	text3 = ft_strjoin(text1, text2);
	printf("Este es el texto unido : %s\n", text3);
	free(text3);
	return (0);
}
*/