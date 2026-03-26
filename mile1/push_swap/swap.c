/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cscaroni <cscaroni@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/26 14:56:06 by cscaroni          #+#    #+#             */
/*   Updated: 2026/03/26 14:56:07 by cscaroni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	swap_one(t_stack *stack)
{
	t_node	*tmp_top;
	t_node	*tmp_second;

	if (!stack || stack->size < 2)
		return (1);
	tmp_top = stack->top;
	tmp_second = stack->top->next;
	tmp_top->prev = tmp_second;
	if (stack->size == 2)
		tmp_top->next = NULL;
	else
		tmp_top->next = tmp_second->next;
	stack->top = tmp_second;
	stack->top->next = tmp_top;
	stack->top->prev = NULL;
	if (tmp_top->next == NULL)
		stack->bottom = tmp_top;
	else
		tmp_top->next->prev = tmp_top;
	return (0);
}

void	sa(t_stack *a, t_counter *counter)
{
	if (!swap_one(a))
	{
		if (counter)
		{
			counter->sa++;
			counter->total++;
		}
		write(1, "sa", 2);
		write(1, "\n", 1);
	}
}

void	sb(t_stack *b, t_counter *counter)
{
	if (!swap_one(b))
	{
		if (counter)
		{
			counter->sb++;
			counter->total++;
		}
		write(1, "sb", 2);
		write(1, "\n", 1);
	}
}

void	ss(t_stack *a, t_stack *b, t_counter *counter)
{
	swap_one(a);
	swap_one(b);
	if (counter)
	{
		counter->ss++;
		counter->total++;
	}
	write(1, "ss", 2);
	write(1, "\n", 1);
}
