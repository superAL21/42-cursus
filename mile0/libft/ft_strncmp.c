/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lajen-li <lajen-li@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 15:21:48 by lajen-li          #+#    #+#             */
/*   Updated: 2026/01/22 15:39:33 by lajen-li         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t		i;

	i = 0;
	if (n == 0)
	{
		return (0);
	}
	while (s1[i] && s1[i] == s2[i] && i < n - 1)
	{
		i++;
	}
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

/*	
#include <stdio.h>
#include <string.h>
#include <unistd.h>

void	test_strncmp(char *s1, char *s2, size_t n, int test_num)
{
	int res_ft = ft_strncmp(s1, s2, n);
	int res_or = strncmp(s1, s2, n);

	printf("Test %d: s1=\"%s\", s2=\"%s\", n=%zu\n", test_num, s1, s2, n);
	
	// Verificamos el signo del resultado, que es lo que importa
	if ((res_ft > 0 && res_or > 0) 
	|| (res_ft < 0 && res_or < 0) || (res_ft == 0 && res_or == 0))
		printf("✅ OK! (ft: %d, or: %d)\n", res_ft, res_or);
	else
		printf("❌ ERROR! (ft: %d, or: %d)\n", res_ft, res_or);
	printf("-------------------------------------------\n");
}

int	main(void)
{
	printf("=== PRUEBAS PARA FT_STRNCMP ===\n\n");

	// 1. Caso estándar: Iguales
	test_strncmp("Hola", "Hola", 4, 1);

	// 2. Caso estándar: Diferentes al final
	test_strncmp("Hola Mundo", "Hola Mundi", 10, 2);

	// 3. Diferencia después de n (deben ser iguales hasta n)
	test_strncmp("Cerveza", "Cerveza artesana", 7, 3);

	// 4. n = 0 (Debe devolver siempre 0)
	test_strncmp("Algo", "Otra cosa", 0, 4);

	// 5. Comparar con cadena vacía
	test_strncmp("", "42", 2, 5);

	// 6. Caso crítico: Unsigned char (Caracteres extendidos)
	// Usamos \200 que es un valor alto (128 decimal)
	test_strncmp("test\200", "test\0", 6, 6);

	// 7. n es mayor que la longitud de la cadena
	test_strncmp("ABC", "ABC", 10, 7);

	return (0);
}
*/