/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lajen-li <lajen-li@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/23 18:21:06 by lajen-li          #+#    #+#             */
/*   Updated: 2026/01/26 15:13:06 by lajen-li         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	unsigned char	*ptr;
	size_t			i;

	i = 0;
	ptr = malloc(nmemb * size);
	if (!ptr)
		return (NULL);
	while (i < nmemb * size)
	{
		ptr[i] = 0;
		i++;
	}
	return (ptr);
}
/*
#include <stdio.h>
#include <stdlib.h>

int	main() {
    int n;
	int	i;
    int *array;

	n = 10;
    array = (int *)ft_calloc(n, sizeof(int));

    printf("\nContenido del array (inicializado por calloc):\n");
    for (i = 0; i < n; i++) {
        printf("Elemento %d: %d\n", i, array[i]);
    }

    for (i = 0; i < n; i++) {
        array[i] = i + '5';
    }

    printf("\nContenido del array después de modificarlo:\n");
    for (i = 0; i < n; i++) {
        printf("Elemento %d: %d\n", i, array[i]);
    }
    free(array);
    return 0;
}
*/