/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_parser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cscaroni <cscaroni@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/26 14:55:27 by cscaroni          #+#    #+#             */
/*   Updated: 2026/03/26 14:55:28 by cscaroni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	read_flags(char *argv)
{
	if (ft_strcmp(argv, "--bench") == 0)
		return (1);
	else if (ft_strcmp(argv, "--simple") == 0)
		return (2);
	else if (ft_strcmp(argv, "--medium") == 0)
		return (2);
	else if (ft_strcmp(argv, "--complex") == 0)
		return (2);
	else if (ft_strcmp(argv, "--adaptive") == 0)
		return (2);
	return (0);
}

char	**ft_parser(int argc, char **argv, int i)
{
	char	*temp;
	char	**final_data;
	char	*full_string;

	if (argc == 2)
		full_string = ft_strdup(argv[i]);
	else
	{
		full_string = ft_strdup("");
		while (i < argc)
		{
			if (read_flags(argv[i]) != 0)
			{
				i++;
				continue ;
			}
			temp = ft_strjoin(full_string, " ");
			free(full_string);
			full_string = ft_strjoin(temp, argv[i]);
			free(temp);
			i++;
		}
	}
	final_data = ft_split(full_string, ' ');
	return (free(full_string), final_data);
}

static int	convert(char *arg, t_stack *stack_a)
{
	long	num;

	num = ft_atol(arg);
	if (num > 2147483647 || num < -2147483648)
		return (0);
	if (is_duplicate(stack_a, num))
		return (0);
	ft_node_to_bottom(stack_a, num);
	return (1);
}

t_stack	*ft_fill_stack(char **arg)
{
	int		i;
	t_stack	*stack_a;

	stack_a = ft_create_stack();
	i = 0;
	if (!arg || !arg[i])
		return (ft_free_stack(stack_a), NULL);
	if (!arg[i])
		return (ft_free_stack(stack_a), NULL);
	while (arg[i])
	{
		if (!is_right_number(arg[i]))
			return (ft_free_stack(stack_a), ft_error(), NULL);
		if (!convert(arg[i], stack_a))
			return (ft_free_stack(stack_a), ft_error(), NULL);
		i++;
	}
	return (stack_a);
}
