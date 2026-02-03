/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lajen-li <lajen-li@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 16:46:39 by lajen-li          #+#    #+#             */
/*   Updated: 2026/02/03 14:52:07 by lajen-li         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	len_s;
	size_t	len_d;

	len_s = ft_strlen(src);
	if (size == 0)
	{
		return (len_s);
	}
	len_d = ft_strlen(dst);
	if (size <= len_d)
	{
		return (len_s + size);
	}
	i = 0;
	while (src[i] != '\0' && len_d + i < size -1)
	{
		dst[len_d + i] = src[i];
		i++;
	}
	dst[len_d + i] = '\0';
	return (len_s + len_d);
}
/*
#include <string.h>
#include <stdio.h>
int	main(void)
{
	char	dst1[20] = "Hola";
	char	*src1 = " Mundo";
	size_t	res1;
	
	res1 = ft_strlcat(dst1, src1, 20);
	printf("PRUEBA 1 (Espacio suficiente):\n");
	printf("  Resultado: [%s]\n", dst1);
	printf("  Retorno: %zu (Esperado: 10)\n\n", res1);

	// --- ESCENARIO 2: Truncamiento (No cabe todo) ---
	char	dst2[10] = "Buenas";
	char	*src2 = " noches";
	size_t	res2;

	// El buffer es de 10. "Buenas" (6) + " noches" (7) = 13.
	// Solo debería pegar " no" + '\0' (total 10 caracteres)
	res2 = ft_strlcat(dst2, src2, 10);
	printf("PRUEBA 2 (Truncamiento):\n");
	printf("  Resultado: [%s]\n", dst2); 
	printf("  Retorno: %zu (Esperado: 13)\n", res2);
	if (res2 >= 10)
		printf("  Aviso: El texto fue cortado.\n\n");

	return (0);
}
*/