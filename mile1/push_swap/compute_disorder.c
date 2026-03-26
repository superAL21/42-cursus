/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compute_disorder.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cscaroni <cscaroni@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/26 14:54:42 by cscaroni          #+#    #+#             */
/*   Updated: 2026/03/26 14:54:43 by cscaroni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

double	ft_compute_disorder(t_stack *stack_a)
{
	double	mistakes;
	double	total_pairs;
	t_node	*first_node;
	t_node	*second_node;

	first_node = stack_a->top;
	second_node = NULL;
	mistakes = 0;
	total_pairs = 0;
	while (first_node != NULL)
	{
		second_node = first_node->next;
		while (second_node != NULL)
		{
			total_pairs++;
			if (first_node->content > second_node->content)
				mistakes++;
			second_node = second_node->next;
		}
		first_node = first_node->next;
	}
	return (mistakes / total_pairs);
}
