/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrigny <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 16:24:00 by yrigny            #+#    #+#             */
/*   Updated: 2023/12/18 16:55:16 by yrigny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool	ft_strchr(const char *s, char c)
{
	while (*s)
	{
		if (*s == (const char)c)
			return (1);
		s++;
	}
	if (*s == (const char)c)
		return (1);
	return (0);
}

t_list	*ft_lstlast(t_list *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

void	free_stack(t_list **stack)
{
	t_list	*tmp;

	tmp = NULL;
	if (stack == NULL || *stack == NULL)
		return ;
	while (*stack)
	{
		tmp = (*stack)->next;
		free(*stack);
		*stack = tmp;
	}
}
