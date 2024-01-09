/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrigny <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 19:14:42 by yrigny            #+#    #+#             */
/*   Updated: 2024/01/08 19:14:44 by yrigny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_BONUS_H

# define PUSH_SWAP_BONUS_H
# include <stdlib.h>
# include <stdbool.h>
# include <stdarg.h>
# include <limits.h>
# include "libft/libft.h"

typedef struct s_stack
{
	int				data;
	int				idx;
	struct s_stack	*next;
}					t_stack;

/* main */
bool	order_ok(t_stack *stack);
bool	isvalid(char *line, t_stack **a, t_stack **b);
bool	read_and_do(t_stack **a, t_stack **b);

/* parsing */
int		get_idx(int nb, t_stack *a);
bool	unique(int nb, t_stack *a);
bool	numeric(char *ar);
bool	get_nb(char *ar, t_stack **a);
bool	parser(int argc, char **argv, t_stack **a);

/* movements */
bool	swap(t_stack **stack);
bool	push(t_stack **from, t_stack **to);
bool	rotate_up(t_stack **stack);
bool	rotate_down(t_stack **stack);

/* utils */
long	ft_atol(const char *str);
t_stack	*lastnb(t_stack *stack);
void	free_arg(char **arg);
void	free_stack(t_stack **stack);

#endif
