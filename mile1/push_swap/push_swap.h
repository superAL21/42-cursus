/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cscaroni <cscaroni@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/26 14:55:37 by cscaroni          #+#    #+#             */
/*   Updated: 2026/03/26 14:57:43 by cscaroni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# define STRATEGY_SIMPLE "Simple / O(n²)"
# define STRATEGY_MEDIUM "Medium / O(n√(n))"
# define STRATEGY_COMPLEX "Complex / O(n log n)"
# define STRATEGY_ADAPTIVE "Adaptive"

# include <unistd.h>
# include <stdarg.h>
# include "libft/libft.h"

typedef struct s_node
{
	long			content;
	struct s_node	*prev;
	struct s_node	*next;
	struct s_node	*target;

}					t_node;

typedef struct s_stack
{
	int		size;
	t_node	*top;
	t_node	*bottom;
}			t_stack;

typedef struct s_counter
{
	int	pa;
	int	pb;
	int	sa;
	int	sb;
	int	ss;
	int	ra;
	int	rb;
	int	rr;
	int	rra;
	int	rrb;
	int	rrr;
	int	total;
}			t_counter;

typedef struct s_range
{
	int	min_in_chunk;
	int	max_in_chunk;
}			t_range;

typedef struct s_sort_context
{
	char		*strategy;
	double		disorder;
	int			bench;
}			t_sort_context;

void	pb(t_stack *a, t_stack *b, t_counter *counter);
void	pa(t_stack *a, t_stack *b, t_counter *counter);
void	ft_error(void);
void	ft_free_char(char **data_parsed);
void	push_swap(int argc, char **argv);
void	ft_free_stack(t_stack *stack);
void	ft_node_to_bottom(t_stack *stack, long value);
void	free_stack_and_char(t_stack *stack_a, t_stack *stack_b, char **data);
void	sa(t_stack *a, t_counter *counter);
void	sb(t_stack *b, t_counter *counter);
void	ss(t_stack *a, t_stack *b, t_counter *counter);
void	rotate(t_stack *stack);
void	ra(t_stack *a, t_counter *counter);
void	rb(t_stack *b, t_counter *counter);
void	rr(t_stack *a, t_stack *b, t_counter *counter);
void	reverse_rotate(t_stack *stack);
void	rra(t_stack *a, t_counter *counter);
void	rrb(t_stack *b, t_counter *counter);
void	rrr(t_stack *a, t_stack *b, t_counter *counter);
void	sort_two(t_stack *stack, t_counter *counter);
void	sort_three(t_stack *stack, t_counter *counter);
void	sort_four(t_stack *stack_a, t_stack *stack_b, t_counter *counter);
void	sort_five(t_stack *stack_a, t_stack *stack_b, t_counter *counter);
void	ft_init_counter(t_counter *counter);
void	sort_simple(t_stack *stack_a, t_stack *stack_b, t_counter *counter);
void	final_order_and_push(t_stack *a, t_stack *b, t_counter *count);
void	ft_print_benchmark(t_counter *counter, double disorder, char *strategy);
void	sort_chunks(t_stack *stack_a, t_stack *stack_b, t_counter *counter);
void	sort_adaptive(t_stack *a, t_stack *b, t_counter *counter, float dis);
void	adptive_checker( double disorder, char *strategy);
void	sort_turk(t_stack *stack_a, t_stack *stack_b, t_counter *counter);
void	r_or_rr_moves(t_stack *a, t_stack *b, t_node *node, t_counter *count);
int		swap_one(t_stack *stack);
int		is_right_number(char *str);
int		is_duplicate(t_stack *stack, long num);
int		ft_strcmp(const char *s1, const char *s2);
int		find_min_pos(t_stack *stack_a);
int		find_max_pos(t_stack *stack_a);
int		find_min_num(t_stack *stack_a);
int		find_max_num(t_stack *stack_a);
int		is_ordered(t_stack *stack_a);
int		find_pos(t_stack *stack_a, t_node *node);
int		total_cost(t_stack *a, t_stack *b, t_node *node, t_node *target_b);
char	**ft_parser(int argc, char **argv, int i);
t_node	*find_target_in_b(t_stack *stack_b, int value);
t_node	*find_cheapest(t_stack *stack_a, t_stack *stack_b);
t_node	*find_extremum(t_stack *stack, int find_max);
t_stack	*ft_fill_stack(char **arg);
t_stack	*ft_create_stack(void);
double	ft_compute_disorder(t_stack *stack_a);

#endif