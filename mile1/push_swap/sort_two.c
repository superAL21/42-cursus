/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_two.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cscaroni <cscaroni@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/26 14:56:03 by cscaroni          #+#    #+#             */
/*   Updated: 2026/03/26 14:56:04 by cscaroni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_two(t_stack *stack, t_counter *counter)
{
	t_node	*first;
	t_node	*second;

	first = stack->top;
	second = first->next;
	if (first->content < second->content)
		return ;
	else
		sa(stack, counter);
}
