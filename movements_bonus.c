/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrigny <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 18:59:47 by yrigny            #+#    #+#             */
/*   Updated: 2024/01/08 18:59:49 by yrigny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

bool	swap(t_stack **stack)
{
	t_stack	*first;
	t_stack	*second;

	if (*stack == NULL || (*stack)->next == NULL)
		return (1);
	first = *stack;
	second = first->next;
	first->next = second->next;
	second->next = first;
	*stack = second;
	return (1);
}

bool	push(t_stack **from, t_stack **to)
{
	t_stack	*from_newhead;

	if (*from == NULL)
		return (1);
	from_newhead = (*from)->next;
	(*from)->next = *to;
	*to = *from;
	*from = from_newhead;
	return (1);
}

bool	rotate_up(t_stack **stack)
{
	t_stack	*newhead;

	if (*stack == NULL || (*stack)->next == NULL)
		return (1);
	lastnb(*stack)->next = *stack;
	newhead = (*stack)->next;
	(*stack)->next = NULL;
	*stack = newhead;
	return (1);
}

bool	rotate_down(t_stack **stack)
{
	t_stack	*newhead;
	t_stack	*newtail;

	if (*stack == NULL || (*stack)->next == NULL)
		return (1);
	newhead = lastnb(*stack);
	lastnb(*stack)->next = *stack;
	newtail = *stack;
	while (newtail && newtail->next != newhead)
		newtail = newtail->next;
	newtail->next = NULL;
	*stack = newhead;
	return (1);
}
