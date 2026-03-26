/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm_turk_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cscaroni <cscaroni@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/26 14:54:17 by cscaroni          #+#    #+#             */
/*   Updated: 2026/03/26 14:54:18 by cscaroni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_pos(t_stack *stack_a, t_node *node)
{
	int		position;
	t_node	*current;

	if (!stack_a || !stack_a->top)
		return (-1);
	position = 0;
	current = stack_a->top;
	while (current != NULL)
	{
		if (current == node)
			return (position);
		position++;
		current = current->next;
	}
	return (-1);
}

t_node	*find_extremum(t_stack *stack, int find_max)
{
	t_node	*wanted;
	t_node	*current;

	if (!stack || !stack->top)
		return (NULL);
	current = stack->top;
	wanted = current;
	while (current != NULL)
	{
		if (find_max == 1 && current->content > wanted->content)
			wanted = current;
		else if (find_max == 0 && current->content < wanted->content)
			wanted = current;
		current = current->next;
	}
	return (wanted);
}

t_node	*find_target_in_b(t_stack *stack_b, int value)
{
	t_node	*target;
	t_node	*current;

	target = NULL;
	current = stack_b->top;
	while (current)
	{
		if (current->content < value)
		{
			if (target == NULL || current->content > target->content)
				target = current;
		}
		current = current->next;
	}
	if (target == NULL)
		target = find_extremum(stack_b, 1);
	return (target);
}

static	int	calculate_cost(t_stack *stack, t_node *node)
{
	int	pos;
	int	size;
	int	cost;

	pos = find_pos(stack, node);
	size = stack->size;
	if (pos <= size / 2)
		cost = pos;
	else
		cost = size - pos;
	return (cost);
}

int	total_cost(t_stack *a, t_stack *b, t_node *node, t_node *target_b)
{
	int	cost_a;
	int	cost_b;
	int	position_a;
	int	position_b;

	position_a = find_pos(a, node);
	position_b = find_pos(b, target_b);
	cost_a = calculate_cost(a, node);
	cost_b = calculate_cost(b, target_b);
	if ((position_a <= a->size / 2 && position_b <= b->size / 2)
		|| (position_a > a->size / 2 && position_b > b->size / 2))
	{
		if (cost_a > cost_b)
			return (cost_a);
		else
			return (cost_b);
	}
	else
		return (cost_a + cost_b);
}
