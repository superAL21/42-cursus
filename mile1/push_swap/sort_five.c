/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_five.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cscaroni <cscaroni@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/26 14:55:53 by cscaroni          #+#    #+#             */
/*   Updated: 2026/03/26 14:55:54 by cscaroni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static	void	base_move(t_stack *stack_a, t_stack *stack_b,
			t_counter *counter)
{
	pb(stack_a, stack_b, counter);
	sort_four(stack_a, stack_b, counter);
	pa(stack_a, stack_b, counter);
}

static	void	base_ra(t_stack *stack_a, t_counter *counter)
{
	ra(stack_a, counter);
	ra(stack_a, counter);
}

static	void	base_rra(t_stack *stack_a, t_counter *counter)
{
	rra(stack_a, counter);
	rra(stack_a, counter);
}

void	sort_five(t_stack *stack_a, t_stack *stack_b, t_counter *counter)
{
	long	first;
	long	second;
	long	third;
	long	fourth;
	long	fifth;

	first = stack_a->top->content;
	second = stack_a->top->next->content;
	third = stack_a->top->next->next->content;
	fourth = stack_a->top->next->next->next->content;
	fifth = stack_a->bottom->content;
	if (first < second && second < third && third < fourth && fourth < fifth)
		return ;
	if (first < second && first < third && first < fourth && first < fifth)
		base_move(stack_a, stack_b, counter);
	if (second < first && second < third && second < fourth && second < fifth)
		sa(stack_a, counter);
	if (third < first && third < second && third < fourth && third < fifth)
		base_ra(stack_a, counter);
	if (fourth < first && fourth < second && fourth < third && fourth < fifth)
		base_rra(stack_a, counter);
	if (fifth < fourth && fifth < third && fifth < second && fifth < first)
		rra(stack_a, counter);
	return (base_move(stack_a, stack_b, counter), (void)(0));
}
