/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm_chunks.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cscaroni <cscaroni@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/26 14:54:06 by cscaroni          #+#    #+#             */
/*   Updated: 2026/03/26 14:54:07 by cscaroni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_sqrt(int size)
{
	int	i;

	i = 0;
	while (i * i <= size)
	{
		if (i * i == size)
			return (i);
		i++;
	}
	return (i);
}

static void	pb_or_ra(t_stack *a, t_stack *b, t_counter *count, t_range *range)
{
	int	size;
	int	checked_items;

	size = a->size;
	checked_items = 0;
	while (checked_items < size)
	{
		if (!a->top)
			break ;
		if (a->top->content >= range->min_in_chunk
			&& a->top->content <= range->max_in_chunk)
			pb(a, b, count);
		else
			ra(a, count);
		checked_items++;
	}
}

void	final_order_and_push(t_stack *a, t_stack *b, t_counter *count)
{
	int	max_pos;
	int	max_val;

	while (b->size != 0)
	{
		max_pos = find_max_pos(b);
		max_val = find_max_num(b);
		if (max_pos <= b-> size / 2)
		{
			while (b->top->content != max_val)
				rb(b, count);
		}
		else
		{
			while (b->top->content != max_val)
				rrb(b, count);
		}
		pa(a, b, count);
	}
}

static void	init_vars(t_stack *a, int *min_val, long *range, int *chunks_num)
{
	*min_val = find_min_num(a);
	*range = find_max_num(a) - find_min_num(a);
	*chunks_num = ft_sqrt(a->size);
}

void	sort_chunks(t_stack *stack_a, t_stack *stack_b, t_counter *counter)
{
	int		i;
	int		min_value;
	long	range_of_chunk;
	int		num_of_chunks;
	t_range	r;

	i = 0;
	init_vars(stack_a, &min_value, &range_of_chunk, &num_of_chunks);
	while (i < num_of_chunks)
	{
		if (!stack_a->top)
			break ;
		r.min_in_chunk = min_value + i * range_of_chunk / num_of_chunks;
		r.max_in_chunk = min_value + (i + 1) * range_of_chunk / num_of_chunks;
		if (i == num_of_chunks - 1)
			r.max_in_chunk = find_max_num(stack_a);
		pb_or_ra(stack_a, stack_b, counter, &r);
		i++;
	}
	final_order_and_push(stack_a, stack_b, counter);
}
