/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cscaroni <cscaroni@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/26 14:55:46 by cscaroni          #+#    #+#             */
/*   Updated: 2026/03/26 14:55:47 by cscaroni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	reverse_rotate(t_stack *stack)
{
	t_node	*tmp_bottom;
	t_node	*tmp_top;

	if (stack->size == 1 || stack->size == 0)
		return ;
	else if (stack->size == 2)
	{
		swap_one(stack);
		return ;
	}
	tmp_bottom = stack->bottom;
	tmp_top = stack->top;
	stack->top->prev = tmp_bottom;
	stack->top = tmp_bottom;
	stack->bottom = stack->bottom->prev;
	tmp_bottom->prev = NULL;
	tmp_bottom->next = tmp_top;
	stack->bottom->next = NULL;
}

void	rra(t_stack *a, t_counter *counter)
{
	reverse_rotate(a);
	if (counter)
	{
		counter->rra++;
		counter->total++;
	}
	write(1, "rra", 3);
	write(1, "\n", 1);
}

void	rrb(t_stack *b, t_counter *counter)
{
	reverse_rotate(b);
	if (counter)
	{
		counter->rrb++;
		counter->total++;
	}
	write(1, "rrb", 3);
	write(1, "\n", 1);
}

void	rrr(t_stack *a, t_stack *b, t_counter *counter)
{
	reverse_rotate(a);
	reverse_rotate(b);
	if (counter)
	{
		counter->rrr++;
		counter->total++;
	}
	write(1, "rrr", 3);
	write(1, "\n", 1);
}
