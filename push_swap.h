/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrigny <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 10:06:20 by yrigny            #+#    #+#             */
/*   Updated: 2023/12/18 17:00:15 by yrigny           ###   ########.fr       */
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
	int		data;
	struct s_list	*last;
	struct s_list	*next;
}			t_list;

bool	parser(char **argv, t_list **stack_a);
bool	get_num(char *ar, t_list **stack);
bool	unique(int num, t_list *stack);
long	ft_atoi(char *str);
bool	numeric(char *ar);
bool	ft_strchr(const char *s, char c);
t_list	*ft_lstlast(t_list *lst);
void	free_stack(t_list **stack);

#endif
