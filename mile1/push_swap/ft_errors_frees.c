/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_errors_frees.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cscaroni <cscaroni@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/26 14:54:58 by cscaroni          #+#    #+#             */
/*   Updated: 2026/03/26 14:54:59 by cscaroni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_error(void)
{
	write(2, "Error\n", 6);
	return ;
}

void	ft_free_stack(t_stack *stack)
{
	t_node	*current;
	t_node	*next;

	if (!stack)
		return ;
	current = stack -> top;
	while (current)
	{
		next = current -> next;
		free(current);
		current = next;
	}
	free(stack);
}

void	ft_free_char(char **data_parsed)
{
	int	i;

	if (!data_parsed)
		return ;
	i = 0;
	while (data_parsed[i])
	{
		free(data_parsed[i]);
		i++;
	}
	free(data_parsed);
}

void	free_stack_and_char(t_stack *stack_a, t_stack *stack_b, char **data)
{
	ft_free_stack(stack_a);
	ft_free_stack(stack_b);
	ft_free_char(data);
}
