/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yifanr <yifanr@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 10:06:20 by yrigny            #+#    #+#             */
/*   Updated: 2024/01/07 22:22:14 by yrigny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H

# define PUSH_SWAP_H
# include <stdio.h>
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
int		get_idx(int num, t_stack *stack);
long	ft_atol(const char *str);
bool	numeric(char *ar);
bool	parser(int argc, char **argv, t_stack **a);
bool	get_num(char *ar, t_stack **stack);
bool	unique(int num, t_stack *stack);

/* sorting */
int		get_rb_needed(t_stack *a, t_stack *b, int b_min, int b_max);
void	sorter(t_stack **a, int stacksize);
void	a_to_b(t_stack **a, t_stack **b, t_range *range_b, int len_a);
void	b_to_a(t_stack **a, t_stack **b);
void	sort_three(t_stack **stack, int stacksize);
bool	order_ok(t_stack *stack);
void	b_descend(t_stack **b, int b_max);
void	a_ascend(t_stack **a);
t_cost	cheapest(t_stack *a, t_stack *b, t_range range_b, int len_a);

/* utils */
int		stacklen(t_stack *stack);
int		max2(int a, int b);
int		min2(int a, int b);
int		get_cost(int times_ra, int times_rb, int len_a, int len_b);
void	free_stack(t_stack **stack);
void	free_arg(char **arg);
void	cost_init(t_cost *cost);
void	cost_opti(t_cost *cost, int mincost, int times_rra, int times_rrb);
t_stack	*ft_lastn(t_stack *lst);

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
