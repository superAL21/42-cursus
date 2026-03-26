/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm_selection_sort.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cscaroni <cscaroni@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/26 14:54:10 by cscaroni          #+#    #+#             */
/*   Updated: 2026/03/26 14:54:11 by cscaroni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_min_pos(t_stack *stack_a)
{
	int		index;
	int		current_min_num_position;
	t_node	*current;
	int		node_content;

	if (!stack_a || !stack_a->top)
		return (-1);
	index = 0;
	current_min_num_position = 0;
	current = stack_a->top;
	node_content = stack_a->top->content;
	while (current != NULL)
	{
		if (current->content < node_content)
		{
			node_content = current->content;
			current_min_num_position = index;
		}
		index++;
		current = current->next;
	}
	return (current_min_num_position);
}

int	find_min_num(t_stack *stack_a)
{
	int		min;
	t_node	*current;

	if (!stack_a || !stack_a->top)
		return (-1);
	current = stack_a->top;
	min = stack_a->top->content;
	while (current != NULL)
	{
		if (current->content < min)
			min = current->content;
		current = current->next;
	}
	return (min);
}

void	sort_simple(t_stack *stack_a, t_stack *stack_b, t_counter *counter)
{
	int	min_pos;

	while (stack_a->size > 5)
	{
		min_pos = find_min_pos(stack_a);
		if (min_pos <= stack_a->size / 2)
		{
			while (stack_a->top->content != find_min_num(stack_a))
				ra(stack_a, counter);
		}
		else
		{
			while (stack_a->top->content != find_min_num(stack_a))
				rra(stack_a, counter);
		}
		pb(stack_a, stack_b, counter);
	}
	sort_five(stack_a, stack_b, counter);
	while (stack_b->top != NULL)
		pa(stack_a, stack_b, counter);
}
