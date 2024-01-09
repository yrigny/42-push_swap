/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrigny <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 19:23:55 by yrigny            #+#    #+#             */
/*   Updated: 2024/01/08 19:23:57 by yrigny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H

# define PUSH_SWAP_H
# include <unistd.h>
# include <stdlib.h>
# include <stdbool.h>
# include <limits.h>
# include <stdarg.h>
# include "libft/libft.h"

typedef struct s_stack
{
	int				data;
	int				idx;
	struct s_stack	*next;
}					t_stack;

typedef struct s_range
{
	int	min;
	int	max;
}			t_range;

typedef struct s_cost
{
	int	cheap_nb;
	int	rr;
	int	ra;
	int	rb;
	int	rrr;
	int	rra;
	int	rrb;
}		t_cost;

/* parsing */
int		get_idx(int nb, t_stack *a);
long	ft_atol(const char *str);
bool	unique(int nb, t_stack *a);
bool	numeric(char *ar);
bool	get_nb(char *ar, t_stack **a);
bool	parser(int argc, char **argv, t_stack **a);

/* sorting */
int		get_rb_needed(t_stack *a, t_stack *b, int b_min, int b_max);
bool	order_ok(t_stack *stack);
void	a_to_b(t_stack **a, t_stack **b, t_range *range_b, int len_a);
void	b_to_a(t_stack **a, t_stack **b);
void	sort_three(t_stack **a, int stacksize);
void	b_descend(t_stack **b, int b_max);
void	a_ascend(t_stack **a);
void	sorter(t_stack **a, int stacksize);
t_cost	cheapest(t_stack *a, t_stack *b, t_range range_b, int len_a);

/* utils */
int		stacklen(t_stack *stack);
int		max(int a, int b);
int		min(int a, int b);
int		get_cost(int times_ra, int times_rb, int len_a, int len_b);
void	free_stack(t_stack **stack);
void	free_arg(char **arg);
void	cost_init(t_cost *cost);
void	cost_opti(t_cost *cost, int mincost, int times_rra, int times_rrb);
t_stack	*lastnb(t_stack *stack);

/* movements */
void	swap(t_stack **stack);
void	push(t_stack **from, t_stack **to);
void	rotate_up(t_stack **stack);
void	rotate_down(t_stack **stack);
void	sa(t_stack **a);
void	rr(t_stack **a, t_stack **b);
void	ra(t_stack **a);
void	rb(t_stack **b);
void	rrr(t_stack **a, t_stack **b);
void	rra(t_stack **a);
void	rrb(t_stack **b);

#endif
