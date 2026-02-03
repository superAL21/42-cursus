/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lajen-li <lajen-li@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 12:14:41 by lajen-li          #+#    #+#             */
/*   Updated: 2026/02/02 18:01:46 by lajen-li         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	len_s;

	i = 0;
	len_s = ft_strlen(src);
	if (size == 0)
	{
		return (len_s);
	}
	while (src[i] != '\0' && i + 1 < size)
	{
		dst[i] = src [i];
		i++;
	}
	dst[i] = '\0';
	return (len_s);
}
/*
#include <stdio.h>

int	main(void)
{
	char	dest[20];
	size_t	ret;

	printf("--- Test 1: Copia normal (Buffer suficiente) ---\n");
	ret = ft_strlcpy(dest, "Hola Mundo", 20);
	printf("Destino: [%s] | Retorno (len_src): %zu\n\n", dest, ret);

	printf("--- Test 2: Truncado (Buffer pequeño de 5) ---\n");
	// Solo deberían copiarse 4 caracteres + '\0'
	ret = ft_strlcpy(dest, "Hola Mundo", 5);
	printf("Destino: [%s] | Retorno (len_src): %zu\n", dest, ret);
	pero solo copia 'Hola'\n\n");

	printf("--- Test 3: Tamaño 0 (Protección) ---\n");
	char	dest_zero[5] = "ABC";
	ret = ft_strlcpy(dest_zero, "Hola", 0);
	printf("Retorno: %zu (Debe ser 4)
	 | Destino sigue igual: [%s]\n", \addtogroup, dest_zero);

	return (0);
}
*/