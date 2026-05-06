/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prueba_char.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lajen-li <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 14:43:53 by lajen-li          #+#    #+#             */
/*   Updated: 2025/10/31 14:45:49 by lajen-li         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>
#include <stdio.h>

int	ft_putstr(char *str)
{	
	int	count;
	
	count = 0;
	while ( *str != '\0')
	{
		count++;
		str++;
	}
	return (count);
}

int	main (void)
{
	int	cuenta;
	
	cuenta = ft_putstr("TEXTO DE STRING creo");
	printf("Esta es la cuenta: %d\n", cuenta);
	return (0);
}
