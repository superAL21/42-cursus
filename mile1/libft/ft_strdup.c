/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lajen-li <lajen-li@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 13:59:58 by lajen-li          #+#    #+#             */
/*   Updated: 2026/02/03 14:51:20 by lajen-li         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*new;
	size_t	i;

	new = malloc((ft_strlen(s) + 1) * sizeof(char));
	if (!new)
		return (NULL);
	i = 0;
	while (s[i] != '\0')
	{
		new[i] = s[i];
		i++;
	}
	new[i] = '\0';
	return (new);
}

/* #include <stdio.h>

int main(void)
{
	char	*original;
	char	*copia;
	
	original = "Mi nombre es Tom Riddle!";
	printf("Original: %s (Dirección: %p)\n", original, (void*)original);

	copia = ft_strdup(original);

	printf("Copia:    %s (Dirección: %p)\n", copia, (void*)copia);

	free(copia);
	return (0);
} */
