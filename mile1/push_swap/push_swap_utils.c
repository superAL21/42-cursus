/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cscaroni <cscaroni@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/26 14:55:30 by cscaroni          #+#    #+#             */
/*   Updated: 2026/03/26 14:55:31 by cscaroni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_duplicate(t_stack *stack, long num)
{
	t_node	*current;

	if (!stack)
		return (1);
	current = stack -> top;
	while (current != NULL)
	{
		if (current -> content == num)
			return (1);
		current = current -> next;
	}
	return (0);
}

int	is_right_number(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '+' || str[i] == '-')
		i++;
	if (!str[i])
		return (0);
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

long	ft_is_valid_num(char *str)
{
	long	num;

	if (!is_right_number(str))
		return (ft_error(), (0));
	num = ft_atol(str);
	if (num > 2147483647 || num < -2147483648)
		return (ft_error(), (0));
	return (num);
}

int	ft_strcmp(const char *s1, const char *s2)
{
	int		i;

	i = 0;
	while (s1[i] && s1[i] == s2[i])
	{
		i++;
	}
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

int	is_ordered(t_stack *stack_a)
{
	t_node	*current;

	if (!stack_a->top)
		return (0);
	current = stack_a->top;
	while (current->next != NULL)
	{
		if (current->content < current->next->content)
			current = current->next;
		else
			return (0);
	}
	return (1);
}
