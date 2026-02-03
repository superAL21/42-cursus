/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lajen-li <lajen-li@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 15:15:52 by lajen-li          #+#    #+#             */
/*   Updated: 2026/01/22 11:50:20 by lajen-li         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	if (*little == '\0')
	{
		return ((char *) big);
	}
	i = 0;
	while (big[i] && i < len)
	{
		j = 0;
		while (big[i + j] == little[j] && (i + j) < len)
		{
			if (little [j + 1] == '\0')
			{
				return ((char *)&big[i]);
			}
			j++;
		}
		i++;
	}
	return (NULL);
}

/*
#include <stdio.h>
#include <string.h>

void run_test(const char *big, const char *little, size_t len, int test_num)
{
    char *res = ft_strnstr(big, little, len);
    
    printf("Test %d: big=\"%s\", little=\"%s\", len=%zu\n",
	\ test_num, big, little, len);
    if (res)
        printf("   👉 Encontrado: \"%s\" (en la dirección %p)\n", res, res);
    else
        printf("   👉 Resultado: NULL\n");
    printf("--------------------------------------------------\n");
}

int main(void)
{
    printf("=== PRUEBAS PARA FT_STRNSTR ===\n\n");

    // 1. Caso básico: coincidencia exacta al inicio
    run_test("Hola Mundo", "Hola", 10, 1);

    // 2. Caso básico: coincidencia en el medio
    run_test("Hola Mundo", "Mundo", 10, 2);

    // 3. El límite 'len' corta la búsqueda (debe dar NULL)
    // "Mundo" empieza en el índice 5. Si len es 5, no debería encontrarlo.
    run_test("Hola Mundo", "Mundo", 5, 3);

    // 4. Little es cadena vacía (debe devolver 'big' completo)
    run_test("Cualquier cosa", "", 10, 4);

    // 5. Coincidencia parcial que no llega a ser total (debe dar NULL)
    run_test("Hola Mundo", "Mundi", 10, 5);

    // 6. Len es 0 (siempre debe dar NULL, a menos que little sea "")
    run_test("Hola", "Hola", 0, 6);

    // 7. Buscar algo más largo que big
    run_test("Breve", "Una frase muy larga", 20, 7);

    // 8. Coincidencia justo en el último carácter permitido por len
    run_test("123456789", "567", 7, 8);

    return (0);
}
*/