/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lajen-li <lajen-li@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/12 18:39:29 by lajen-li          #+#    #+#             */
/*   Updated: 2026/02/17 16:47:18 by lajen-li         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(void)
{
    int     fd;
    char    *line;
    int     i = 1;

    fd = open("test.txt", O_RDONLY);
    if (fd == -1)
    {
        perror("Error al abrir test.txt");
        return (1);
    }

    // Leemos hasta que get_next_line devuelva NULL
    while ((line = get_next_line(fd)) != NULL)
    {
        printf("Jugadora %02d: %s", i++, line);
        free(line);
    }

    close(fd);
    return (0);
}