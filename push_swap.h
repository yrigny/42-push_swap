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

bool	parser(int argc, char **argv, t_list **stack_a);
bool	get_num(char *ar, t_list **stack);
bool	unique(int num, t_list *stack);
long	ft_atoi(char *str);
bool	numeric(char *ar);
bool	ft_strchr(const char *s, char c);
t_list	*ft_lstlast(t_list *lst);
void	free_stack(t_list **stack);
char	**ft_split(char const *s, char c);
void	free_argv(char **argv);
int		stacklen(t_list *stack);
int		max2(int a, int b);
int		min4(int a, int b, int c, int d);
int		get_pushcost(int ra, int rb, t_list *stack_a, t_list *stack_b);

#endif
