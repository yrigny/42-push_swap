/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrigny <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 10:06:20 by yrigny            #+#    #+#             */
/*   Updated: 2023/12/20 16:04:34 by yrigny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H

# define PUSH_SWAP_H
# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>
# include <limits.h>

typedef struct s_list
{
	int				data;
	int				idx;
	struct s_list	*last;
	struct s_list	*next;
}					t_list;

typedef struct s_cost
{
	int	cheap_nb;
	int	times_rr;
	int	times_ra;
	int	times_rb;
	int	times_rrr;
	int	times_rra;
	int times_rrb;
}		t_cost;

/* parsing */
bool	parser(int argc, char **argv, t_list **stack_a);
bool	get_num(char *ar, t_list **stack);
bool	unique(int num, t_list *stack);
int		get_idx(int num, t_list *stack);
long	ft_atoi(char *str);
bool	numeric(char *ar);

/* sorting */
void	sorter(t_list **stack_a, int stacksize);
void	a_to_b(t_list **stack_a, t_list **stack_b, int *b_min, int *b_max);
void	sort_three(stack_a);
void	b_to_a(t_list **stack_a, t_list **stack_b);
t_cost	get_cheapest(t_list *stack_a, t_list *stack_b, int b_min, int b_max);
int		get_rb_needed(t_list *stack_a, t_list *stack_b, int b_min, int b_max);

/* utils */
bool	ft_strchr(const char *s, char c);
t_list	*ft_lstlast(t_list *lst);
void	free_stack(t_list **stack);
void	free_argv(char **argv);
char	**ft_split(char const *s, char c);
int		stacklen(t_list *stack);
int		max2(int a, int b);
int		min2(int a, int b);
int		get_pushcost(int ra, int rb, t_list *stack_a, t_list *stack_b);
void	cost_initiate(t_cost *cost);
void	cost_optimize(t_cost *cost, int mincost, int rra, int rrb);
void    sort_three(t_list **stack, int stacksize);
bool    order_ok(t_list *stack);

/* movements */
void	swap(t_list **stack);
void	push(t_list **from, t_list **to);
void	rotate_up(t_list **stack);
void	rotate_down(t_list **stack);
void	sa(t_list **stack_a);
void	rr(t_list **stack_a, t_list **stack_b);
void	ra(t_list **stack_a);
void	rb(t_list **stack_b);
void	rrr(t_list **stack_a, t_list **stack_b);
void	rra(t_list **stack_a);
void	rrb(t_list **stack_b);

#endif
