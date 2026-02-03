/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lajen-li <lajen-li@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/27 17:18:32 by lajen-li          #+#    #+#             */
/*   Updated: 2026/01/28 14:52:40 by lajen-li         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	len_num(int n)
{
	size_t	count;

	count = 0;
	if (n <= 0)
		count++;
	while (n != 0)
	{
		n = n / 10;
		count++;
	}
	return (count);
}

char	*ft_itoa(int n)
{
	char	*str;
	size_t	len;
	long	nbr;

	nbr = (long)n;
	len = len_num(nbr);
	str = malloc((len +1) * sizeof(char));
	if (!str)
		return (NULL);
	if (nbr == 0)
		str[0] = '0';
	if (nbr < 0)
	{
		str[0] = '-';
		nbr = -nbr;
	}
	str[len] = '\0';
	while (nbr > 0)
	{
		len--;
		str[len] = ((nbr % 10) + '0');
		nbr = nbr / 10;
	}
	return (str);
}
/*
#include <stdio.h>

int	main(void)
{
	int	num;
	size_t	res;
	
	num = 0123456789;
	res = len_num(num);
	printf("Hay: %ld\n", res);
	return (0);
}

int	main(void)
{
	long		num;
	char	*res;
	
	num = -2147483648;
	res = ft_itoa(num);
	printf("El número: %s\n", res);
	free(res);
	return (0);
}
*/