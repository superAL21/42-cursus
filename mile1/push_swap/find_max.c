/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_max.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cscaroni <cscaroni@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/26 14:54:55 by cscaroni          #+#    #+#             */
/*   Updated: 2026/03/26 14:54:56 by cscaroni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_max_pos(t_stack *stack_a)
{
	int		index;
	int		current_max_num_position;
	int		node_content;
	t_node	*current;

	if (!stack_a || !stack_a->top)
		return (-1);
	index = 0;
	current_max_num_position = 0;
	current = stack_a->top;
	node_content = stack_a->top->content;
	while (current != NULL)
	{
		if (current->content > node_content)
		{
			node_content = current->content;
			current_max_num_position = index;
		}
		index++;
		current = current->next;
	}
	return (current_max_num_position);
}

int	find_max_num(t_stack *stack_a)
{
	int		max;
	t_node	*current;

	if (!stack_a || !stack_a->top)
		return (-1);
	current = stack_a->top;
	max = stack_a->top->content;
	while (current != NULL)
	{
		if (current->content > max)
			max = current->content;
		current = current->next;
	}
	return (max);
}
