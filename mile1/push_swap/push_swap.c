/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cscaroni <cscaroni@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/26 14:55:34 by cscaroni          #+#    #+#             */
/*   Updated: 2026/03/26 14:55:35 by cscaroni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_get_strategy(int argc, char **argv, int *bench, char **strategy)
{
	int	i;

	i = 0;
	*bench = 0;
	*strategy = NULL;
	while (i < argc)
	{
		if (ft_strncmp(argv[i], "--bench", 7) == 0)
			*bench = 1;
		else if (ft_strncmp(argv[i], "--simple", 8) == 0)
			*strategy = STRATEGY_SIMPLE;
		else if (ft_strncmp(argv[i], "--medium", 8) == 0)
			*strategy = STRATEGY_MEDIUM;
		else if (ft_strncmp(argv[i], "--complex", 9) == 0)
			*strategy = STRATEGY_COMPLEX;
		else if (ft_strncmp(argv[i], "--adaptive", 10) == 0)
			*strategy = STRATEGY_ADAPTIVE;
		i++;
	}
	if (!*strategy)
		*strategy = STRATEGY_ADAPTIVE;
}

static void	ft_execute_sort(t_stack *stack_a, t_stack *stack_b,
			t_counter *counter, char *strategy)
{
	float		disorder;

	disorder = ft_compute_disorder(stack_a);
	if (stack_a->size == 2)
		sort_two(stack_a, counter);
	else if (stack_a->size == 3)
		sort_three(stack_a, counter);
	else if (stack_a->size == 4)
		sort_four(stack_a, stack_b, counter);
	else if (stack_a->size == 5)
		sort_five(stack_a, stack_b, counter);
	else if (stack_a->size > 5)
	{
		if (ft_strcmp(strategy, STRATEGY_SIMPLE) == 0)
			sort_simple(stack_a, stack_b, counter);
		else if (ft_strcmp(strategy, STRATEGY_MEDIUM) == 0)
			sort_chunks(stack_a, stack_b, counter);
		else if (ft_strcmp(strategy, STRATEGY_COMPLEX) == 0)
			sort_turk(stack_a, stack_b, counter);
		else
			sort_adaptive(stack_a, stack_b, counter, disorder);
	}
}

void	push_swap(int argc, char **argv)
{
	t_stack			*stack_b;
	t_stack			*stack_a;
	char			**data_parsed;
	t_counter		counter;
	t_sort_context	context;

	ft_get_strategy(argc, argv, &context.bench, &context.strategy);
	ft_init_counter(&counter);
	data_parsed = ft_parser(argc, argv, 1);
	stack_a = ft_fill_stack(data_parsed);
	stack_b = ft_create_stack();
	if (!stack_a || !stack_b)
		return (free_stack_and_char(stack_a, stack_b, data_parsed), (void)(0));
	context.disorder = ft_compute_disorder(stack_a);
	if (is_ordered(stack_a))
	{
		if (context.bench == 1)
			ft_print_benchmark(&counter, context.disorder, context.strategy);
		return (free_stack_and_char(stack_a, stack_b, data_parsed), (void)(0));
	}
	ft_execute_sort(stack_a, stack_b, &counter, context.strategy);
	if (context.bench == 1)
		ft_print_benchmark(&counter, context.disorder, context.strategy);
	free_stack_and_char(stack_a, stack_b, data_parsed);
}

int	main(int argc, char **argv)
{
	push_swap(argc, argv);
	return (0);
}
