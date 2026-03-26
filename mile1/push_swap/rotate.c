/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cscaroni <cscaroni@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/26 14:55:50 by cscaroni          #+#    #+#             */
/*   Updated: 2026/03/26 14:55:51 by cscaroni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate(t_stack *stack)
{
	t_node	*tmp_top;
	t_node	*tmp_bottom;

	if (stack->size == 1 || stack->size == 0)
		return ;
	else if (stack->size == 2)
	{
		swap_one(stack);
		return ;
	}
	tmp_top = stack->top;
	tmp_bottom = stack->bottom;
	stack->bottom->next = tmp_top;
	stack->bottom = tmp_top;
	stack->top = stack->top->next;
	tmp_top->next = NULL;
	tmp_top->prev = tmp_bottom;
	stack->top->prev = NULL;
}

void	ra(t_stack *a, t_counter *counter)
{
	rotate(a);
	if (counter)
	{
		counter->ra++;
		counter->total++;
	}
	write(1, "ra", 2);
	write(1, "\n", 1);
}

void	rb(t_stack *b, t_counter *counter)
{
	rotate(b);
	if (counter)
	{
		counter->rb++;
		counter->total++;
	}
	write(1, "rb", 2);
	write(1, "\n", 1);
}

void	rr(t_stack *a, t_stack *b, t_counter *counter)
{
	rotate(a);
	rotate(b);
	if (counter)
	{
		counter->rr++;
		counter->total++;
	}
	write(1, "rr", 2);
	write(1, "\n", 1);
}
