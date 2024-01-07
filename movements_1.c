/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements_1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yifanr <yifanr@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 23:11:48 by yifanr            #+#    #+#             */
/*   Updated: 2024/01/07 22:20:27 by yrigny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_stack **stack)
{
	t_stack	*first;
	t_stack	*second;

	if (*stack == NULL || (*stack)->next == NULL)
		return ;
	first = *stack;
	second = first->next;
	first->next = second->next;
	second->next = first;
	*stack = second;
}

void	push(t_stack **from, t_stack **to)
{
	t_stack	*from_newhead;

	if (*from == NULL)
		return ;
	from_newhead = (*from)->next;
	(*from)->next = *to;
	*to = *from;
	*from = from_newhead;
}

void	rotate_up(t_stack **stack)
{
	t_stack	*newhead;

	if (*stack == NULL || (*stack)->next == NULL)
		return ;
	lastnb(*stack)->next = *stack;
	newhead = (*stack)->next;
	(*stack)->next = NULL;
	*stack = newhead;
}

void	rotate_down(t_stack **stack)
{
	t_stack	*newhead;
	t_stack	*newtail;

	if (*stack == NULL || (*stack)->next == NULL)
		return ;
	newhead = lastnb(*stack);
	lastnb(*stack)->next = *stack;
	newtail = *stack;
	while (newtail && newtail->next != newhead)
		newtail = newtail->next;
	newtail->next = NULL;
	*stack = newhead;
}

void	rr(t_stack **a, t_stack **b)
{
	rotate_up(a);
	rotate_up(b);
	ft_printf("rr\n");
}
