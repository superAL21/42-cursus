/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lajen-li <lajen-li@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/27 16:28:22 by lajen-li          #+#    #+#             */
/*   Updated: 2026/01/28 13:22:17 by lajen-li         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*new;

	if (!s || !f)
		return (NULL);
	i = 0;
	new = malloc ((ft_strlen(s) +1) * sizeof(char));
	if (!new)
		return (NULL);
	while (s[i])
	{
		new[i] = f(i, s[i]);
		i++;
	}
	new [i] = '\0';
	return (new);
}
/*
#include <stdio.h>

char	capital(unsigned int, char c)
{
	if (c >= 'a' && c <= 'z')
	{
		c = c - 32;
	}
	return (c);
}
int	main(void)
{
	char *res;
	char text[]	= "esta cadena es de prueba";

	res = ft_strmapi(text, &capital);
	printf("El resultado: %s\n", res);
	free(res);
	return (0);
}
*/