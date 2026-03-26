/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cscaroni <cscaroni@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/26 14:55:40 by cscaroni          #+#    #+#             */
/*   Updated: 2026/03/26 14:55:41 by cscaroni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(t_stack *a, t_stack *b, t_counter *counter)
{
	t_node	*tmp;

	if (!a || !b || b->size == 0)
		return ;
	tmp = b->top;
	b->top = tmp->next;
	if (b->top)
		b->top->prev = NULL;
	else
		b->bottom = NULL;
	tmp->next = a->top;
	if (a->top)
		a->top->prev = tmp;
	else
		a->bottom = tmp;
	tmp->prev = NULL;
	a->top = tmp;
	a->size++;
	b->size--;
	if (counter)
	{
		counter->pa++;
		counter->total++;
	}
	write(1, "pa\n", 3);
}

void	pb(t_stack *a, t_stack *b, t_counter *counter)
{
	t_node	*tmp;

	if (!a || !b || a->size == 0)
		return ;
	tmp = a->top;
	a->top = tmp->next;
	if (a->top)
		a->top->prev = NULL;
	else
		a->bottom = NULL;
	tmp->next = b->top;
	if (b->top)
		b->top->prev = tmp;
	else
		b->bottom = tmp;
	tmp->prev = NULL;
	b->top = tmp;
	a->size--;
	b->size++;
	if (counter)
	{
		counter->pb++;
		counter->total++;
	}
	write(1, "pb\n", 3);
}
