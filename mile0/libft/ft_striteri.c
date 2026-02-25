/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lajen-li <lajen-li@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/27 15:27:10 by lajen-li          #+#    #+#             */
/*   Updated: 2026/01/28 13:22:24 by lajen-li         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	unsigned int	i;

	if (!s || !f)
		return ;
	i = 0;
	while (s[i])
	{
		f(i, &s[i]);
		i++;
	}
	return ;
}
/*
#include <stdio.h>

void	capital(unsigned int, char *c)
{
	if (*c >= 'a' && *c <= 'z')
	{
		*c = *c - 32;
	}
}
int	main(void)
{
	char text[]	= "esta cadena es de prueba";
	ft_striteri(text, &capital);
	printf("El resultado: %s\n", text);
	return (0);
}
*/