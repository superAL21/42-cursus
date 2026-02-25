/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lajen-li <lajen-li@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/18 13:23:30 by lajen-li          #+#    #+#             */
/*   Updated: 2026/02/19 13:29:37 by lajen-li         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int	main(void)
{
	int		fd;
	int		fd2;
	int		fd3;

	fd = open ("quixote.txt", O_RDONLY);
	if (fd == -1)
	{
		printf("Error al abrir el archivo");
		return (1);
	}
	fd2 = open ("arch.txt", O_RDONLY);
	if (fd == -1)
	{
		printf("Error al abrir el archivo");
		return (1);
	}
	fd3 = open ("bent.txt", O_RDONLY);
	if (fd == -1)
	{
		printf("Error al abrir el archivo");
		return (1);
	}
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd2));
	printf("%s", get_next_line(fd3));
	close(fd);
	close(fd2);
	close(fd3);
	return (0);
}
