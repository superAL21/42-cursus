/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm_turk.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cscaroni <cscaroni@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/26 14:54:32 by cscaroni          #+#    #+#             */
/*   Updated: 2026/03/26 14:54:33 by cscaroni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	r_or_rr_moves(t_stack *stack_a, t_stack *stack_b,
			t_node *node, t_counter *count)
{
	while (stack_a->top != node)
	{
		if (find_pos(stack_a, node) <= stack_a->size / 2)
			ra(stack_a, count);
		else
			rra(stack_a, count);
	}
	while (stack_b->top != node->target)
	{
		if (find_pos(stack_b, node->target) <= stack_b->size / 2)
			rb(stack_b, count);
		else
			rrb(stack_b, count);
	}
}

static void	execute_move(t_stack *a, t_stack *b, t_node *node, t_counter *count)
{
	if (!a || !b || !node)
		return ;
	while (a->top != node && b->top != node->target)
	{
		if (find_pos(a, node) <= a->size / 2
			&& find_pos(b, node->target) <= b->size / 2)
			rr(a, b, count);
		else if (find_pos(a, node) > a->size / 2
			&& find_pos(b, node->target) > b->size / 2)
			rrr(a, b, count);
		else
			break ;
	}
	r_or_rr_moves(a, b, node, count);
	pb(a, b, count);
}

t_node	*find_cheapest(t_stack *stack_a, t_stack *stack_b)
{
	int		min_cost;
	int		total;
	t_node	*cheapest;
	t_node	*current;
	t_node	*target;

	min_cost = 2147483647;
	cheapest = NULL;
	current = stack_a->top;
	while (current)
	{
		target = find_target_in_b(stack_b, current->content);
		total = total_cost(stack_a, stack_b, current, target);
		if (total < min_cost)
		{
			min_cost = total;
			cheapest = current;
		}
		current = current->next;
	}
	return (cheapest);
}

static void	push_max_to_a(t_stack *b, t_stack *a, t_counter *counter)
{
	while (b->size > 0)
	{
		while (b->top != find_extremum(b, 1))
		{
			if (find_pos(b, find_extremum(b, 1)) <= b->size / 2)
				rb(b, counter);
			else
				rrb(b, counter);
		}
		pa(a, b, counter);
	}
}

void	sort_turk(t_stack *stack_a, t_stack *stack_b, t_counter *counter)
{
	t_node	*cheapest;

	if (stack_a->size > 3)
		pb(stack_a, stack_b, counter);
	if (stack_a->size > 3)
		pb(stack_a, stack_b, counter);
	if (find_extremum(stack_b, 1) != stack_b->top)
		sb(stack_b, counter);
	while (stack_a->size > 0)
	{
		cheapest = find_cheapest(stack_a, stack_b);
		cheapest->target = find_target_in_b(stack_b, cheapest->content);
		execute_move(stack_a, stack_b, cheapest, counter);
	}
	push_max_to_a(stack_b, stack_a, counter);
}
