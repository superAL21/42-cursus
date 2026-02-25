/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lajen-li <lajen-li@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 17:10:04 by lajen-li          #+#    #+#             */
/*   Updated: 2026/02/19 15:43:34 by lajen-li         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	main(void)
{
	char	*texto;
	int		fd;
	int		i;

	fd = open ("quixote.txt", O_RDONLY);
	if (fd == -1)
	{
		printf("Error al abrir el archivo");
		return (1);
	}
	i = 0;
	texto = get_next_line(fd);
	while (texto != NULL)
	{
		printf("line %d, %s", i, texto);
		i++;
		free(texto);
		texto = get_next_line(fd);
	}
	close(fd);
	return (0);
}
