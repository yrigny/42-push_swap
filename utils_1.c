/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrigny <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 16:24:00 by yrigny            #+#    #+#             */
/*   Updated: 2024/01/07 22:23:10 by yrigny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool	order_ok(t_stack *stack)
{
	if (stack->next == NULL)
		return (1);
	while (stack && stack->next)
	{
		if (stack->idx > stack->next->idx)
			return (0);
		stack = stack->next;
	}
	return (1);
}

int	stacklen(t_stack *stack)
{
	int	len_stack;

	len_stack = 0;
	while (stack)
	{
		len_stack++;
		stack = stack->next;
	}
	return (len_stack);
}

t_stack	*ft_lastn(t_stack *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

void	free_stack(t_stack **stack)
{
	t_stack	*tmp;

	tmp = NULL;
	if (stack == NULL || *stack == NULL)
		return ;
	while (*stack)
	{
		tmp = (*stack)->next;
		free(*stack);
		*stack = tmp;
	}
	return ;
}

void	free_arg(char **arg)
{
	int	i;

	i = 0;
	while (arg[i])
		i++;
	while (--i >= 0)
		free(arg[i]);
	free(arg);
}
