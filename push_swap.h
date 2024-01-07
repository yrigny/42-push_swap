/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yifanr <yifanr@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 10:06:20 by yrigny            #+#    #+#             */
/*   Updated: 2024/01/07 03:11:46 by yifanr           ###   ########.fr       */
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

typedef struct s_list
{
	int				data;
	int				idx;
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
	int	times_rrb;
}		t_cost;

/* parsing */
bool	parser(int argc, char **argv, t_list **stack_a);
bool	get_num(char *ar, t_list **stack);
bool	unique(int num, t_list *stack);
int		get_idx(int num, t_list *stack);
long	ft_atoi(const char *str);
bool	numeric(char *ar);

/* sorting */
void	sorter(t_list **stack_a, int stacksize);
void	a_to_b(t_list **stack_a, t_list **stack_b, int *b_min, int *b_max, int stacklen_a);
void	sort_three(t_list **stack_a, int stacksize);
void	b_to_a(t_list **stack_a, t_list **stack_b);
t_cost	get_cheapest(t_list *stack_a, t_list *stack_b, int b_min, int b_max, int stacklen_a);
int		get_rb_needed(t_list *a, t_list *b, int b_min, int b_max);
void	sort_three(t_list **stack, int stacksize);
bool	order_ok(t_list *stack);
void	b_descend(t_list **stack_b, int b_max);
void	a_ascend(t_list **stack_a);

/* utils */
void	print_stack(t_list *stack);
size_t	ft_strlen(const char *s);
bool	ft_strchr(const char *s, char c);
t_list	*ft_lstlast(t_list *lst);
void	free_stack(t_list **stack);
void	free_arg(char **arg);
char	**ft_split(char const *s, char c);
int		stacklen(t_list *stack);
int		max2(int a, int b);
int		min2(int a, int b);
int		get_pushcost(int times_ra, int times_rb, int stacklen_a, int stacklen_b);
void	cost_initiate(t_cost *cost);
void	cost_optimize(t_cost *cost, int mincost, int times_rra, int times_rrb);

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

/* ft_ptintf */
typedef struct s_flags
{
	bool	left;
	bool	plus;
	bool	space;
	bool	hash;
	bool	zero;
	int		width;
	bool	dot;
	int		precis;
	char	type;
}		t_flags;

int		ft_printf(const char *fstr, ...);
int		putnchar(int n, char c);
int		getulen(unsigned long num, unsigned int baselen);
long	unsign(long n);
void	printer(const char *fstr, va_list *p_args, int *p_n);
void	fprinter(const char *fstr, va_list *p_args, int *p_n);
void	iniflagset(t_flags *p_flagset);
void	parseflag(t_flags *p_flagset, const char *fstr);
void	putunbr_base(unsigned long nbr, char *base, unsigned int baselen);
void	fprinter_c(t_flags flagset, va_list *p_args, int *p_n);
void	fprinter_s(t_flags flagset, va_list *p_args, int *p_n);
void	fprinter_p(t_flags flagset, va_list *p_args, int *p_n);
void	fprinter_d(t_flags flagset, va_list *p_args, int *p_n);
void	fprinter_u(t_flags flagset, va_list *p_args, int *p_n);
void	fprinter_x(t_flags flags, va_list *p_args, int *p_n, char *base);

#endif
