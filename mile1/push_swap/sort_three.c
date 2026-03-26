/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cscaroni <cscaroni@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/26 14:55:59 by cscaroni          #+#    #+#             */
/*   Updated: 2026/03/26 14:56:00 by cscaroni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_stack *stack, t_counter *counter)
{
	t_node	*first;
	t_node	*second;
	t_node	*third;

	first = stack->top;
	second = first->next;
	third = second ->next;
	if (first->content < second->content && third->content < second->content
		&& first->content > third->content)
		return (rra(stack, counter), (void)(0));
	if (first->content > second->content && second->content > third->content)
		return (sa(stack, counter), rra(stack, counter), (void)(0));
	if (first->content < second->content && second->content > third->content
		&& first->content < third->content)
		return (rra(stack, counter), sa(stack, counter), (void)(0));
	if (first->content > second->content && second->content < third->content
		&& first->content < third->content)
		return (sa(stack, counter), (void)(0));
	if (first->content > second->content && second->content < third->content
		&& first->content > third->content)
		return (ra(stack, counter), (void)(0));
	return ;
}
