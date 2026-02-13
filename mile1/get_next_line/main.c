/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lajen-li <lajen-li@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/12 18:39:29 by lajen-li          #+#    #+#             */
/*   Updated: 2026/02/13 12:08:56 by lajen-li         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "get_next_line.h"

int main(void)
{
    int fd = open("text.txt", O_RDONLY);
    char *line;
    
    line = get_next_line(fd);
    printf("Línea 1: %s", line);  // Debe ser "Hola\n"
    free(line);
    
    line = get_next_line(fd);
    printf("Línea 2: %s", line);  // Debe ser "Mundo\n"
    free(line);
    
    line = get_next_line(fd);
    printf("Línea 3: %p\n", line);  // Debe ser NULL
    free(line);
    close(fd);
}