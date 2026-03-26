/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   counter_initializer.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cscaroni <cscaroni@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/26 14:54:46 by cscaroni          #+#    #+#             */
/*   Updated: 2026/03/26 14:54:47 by cscaroni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_init_counter(t_counter *counter)
{
	counter -> pa = 0;
	counter -> pb = 0;
	counter -> sa = 0;
	counter -> sb = 0;
	counter -> ss = 0;
	counter -> ra = 0;
	counter -> rb = 0;
	counter -> rr = 0;
	counter -> rra = 0;
	counter -> rrb = 0;
	counter -> rrr = 0;
	counter -> total = 0;
}
