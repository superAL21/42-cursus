/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lajen-li <lajen-li@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 17:10:22 by lajen-li          #+#    #+#             */
/*   Updated: 2026/01/20 15:14:54 by lajen-li         ###   ########.fr       */
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
#include <string.h>


void test_strrchr(const char *s, int c, char *test_name)
{
    char *res_ft = ft_strrchr(s, c);
    char *res_or = strrchr(s, c);
    
    printf("--- %s ---\n", test_name);
    printf("Cadena: \"%s\" | Buscar: '%c' (int %d)\n", s, c, c);
    
    if (res_ft == res_or)
        printf("✅ OK: Ambos coinciden en [%p]\n", res_ft);
    else
    {
        printf("❌ ERROR!\n");
        printf("  ft_strrchr: [%p] -> %s\n", res_ft, res_ft ? res_ft : "NULL");
        printf("  strrchr original: [%p] -> %s\n", res_or, res_or ? 
		\res_or : "NULL");
    }
    
    if (res_ft)
        printf("  Contenido desde ahí: \"%s\"\n", res_ft);
    printf("\n");
}

int main(void)
{
    // 1. Caso: Carácter repetido (debe encontrar el ÚLTIMO)
    test_strrchr("bonjour", 'o', "Carácter repetido");

    // 2. Caso: Carácter al puro final
    test_strrchr("Tripouille", 'e', "Carácter al final");

    // 3. Caso: Carácter al puro principio
    test_strrchr("Tripouille", 'T', "Carácter al principio");

    // 4. Caso: Buscar el nulo (debe devolver el puntero al '\0')
    test_strrchr("42 Madrid", '\0', "Buscar el nulo");

    // 5. Caso: No existe
    test_strrchr("Libft", 'Z', "Inexistente");

    // 6. Caso: Cadena vacía
    test_strrchr("", 'A', "Cadena vacía");
    test_strrchr("", '\0', "Cadena vacía buscando nulo");

    return (0);
}
    */