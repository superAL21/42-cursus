/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_benchmark.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cscaroni <cscaroni@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/26 14:55:02 by cscaroni          #+#    #+#             */
/*   Updated: 2026/03/26 14:55:03 by cscaroni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_print_moves(t_counter *counter)
{
	ft_putstr_fd("[bench] sa: ", 2);
	ft_putnbr_fd(counter->sa, 2);
	ft_putstr_fd(" sb: ", 2);
	ft_putnbr_fd(counter->sb, 2);
	ft_putstr_fd(" ss: ", 2);
	ft_putnbr_fd(counter->ss, 2);
	ft_putstr_fd(" pa: ", 2);
	ft_putnbr_fd(counter->pa, 2);
	ft_putstr_fd(" pb: ", 2);
	ft_putnbr_fd(counter->pb, 2);
	ft_putchar_fd('\n', 2);
	ft_putstr_fd("[bench] ra: ", 2);
	ft_putnbr_fd(counter->ra, 2);
	ft_putstr_fd(" rb: ", 2);
	ft_putnbr_fd(counter->rb, 2);
	ft_putstr_fd(" rr: ", 2);
	ft_putnbr_fd(counter->rr, 2);
	ft_putstr_fd(" rra: ", 2);
	ft_putnbr_fd(counter->rra, 2);
	ft_putstr_fd(" rrb: ", 2);
	ft_putnbr_fd(counter->rrb, 2);
	ft_putstr_fd(" rrr: ", 2);
	ft_putnbr_fd(counter->rrr, 2);
	ft_putchar_fd('\n', 2);
}

void	ft_print_benchmark(t_counter *counter, double disorder, char *strategy)
{
	int	integer_num;
	int	float_num;

	integer_num = (int)(disorder * 100);
	float_num = (int)(disorder * 10000) % 100;
	ft_putstr_fd("[bench] disorder: ", 2);
	ft_putnbr_fd(integer_num, 2);
	ft_putchar_fd('.', 2);
	ft_putnbr_fd(float_num, 2);
	ft_putstr_fd("%\n", 2);
	ft_putstr_fd("[bench] strategy: ", 2);
	ft_putstr_fd(strategy, 2);
	adptive_checker(disorder, strategy);
	ft_putchar_fd('\n', 2);
	ft_putstr_fd("[bench] total_ops: ", 2);
	ft_putnbr_fd(counter->total, 2);
	ft_putchar_fd('\n', 2);
	ft_print_moves(counter);
}

void	adptive_checker(double disorder, char *strategy)
{
	if (strategy != NULL && ft_strcmp(strategy, STRATEGY_ADAPTIVE) == 0)
	{
		if (disorder < 0.2)
			ft_putstr_fd(" O(n²)", 2);
		else if (disorder < 0.5)
			ft_putstr_fd(" O(n√(n))", 2);
		else
			ft_putstr_fd(" O(n log n)", 2);
	}
}
