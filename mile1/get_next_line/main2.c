/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lajen-li <lajen-li@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/19 15:43:51 by lajen-li          #+#    #+#             */
/*   Updated: 2026/02/20 12:28:04 by lajen-li         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	main(void)
{
	char	*line;
	int		fd;
	int		i;

	fd = open("test.txt", O_RDONLY);
	i = 1;
	if (fd == -1)
	{
		printf("ERROR AL LEER EL DOCUMENTO.");
		return (1);
	}
	line = get_next_line(fd);
	while (line != NULL)
	{
		printf("%d: %s\n", i, line);
		i++;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return(0);
}