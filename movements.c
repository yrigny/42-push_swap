/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrigny <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 23:36:07 by yrigny            #+#    #+#             */
/*   Updated: 2024/01/03 23:36:09 by yrigny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    swap(t_list **stack)
{
    t_list  *first;
    t_list  *second;

	if (*stack == NULL || (*stack)->next == NULL)
		return ;
    first = *stack;
    second = first->next;
    first->next = second->next;
    second->next = first;
    *stack = second;
}

void	push(t_list **from, t_list **to)
{
	t_list	*from_newhead;

	if (*from == NULL)
		return ;
	from_newhead = (*from)->next;
	(*from)->next = *to;
	*to = *from;
	*from = from_newhead;
}

void	rotate_up(t_list **stack)
{
    t_list  *newhead;

	if (*stack == NULL || (*stack)->next == NULL)
		return ;
    ft_lstlast(*stack)->next = *stack;
    newhead = (*stack)->next;
    (*stack)->next = NULL;
    *stack = newhead;
}

void	rotate_down(t_list **stack)
{
    t_list  *newhead;
    t_list  *newtail;

	if (*stack == NULL || (*stack)->next == NULL)
		return ;
    newhead = ft_lstlast(*stack);
    ft_lstlast(*stack)->next = *stack;
    newtail = *stack;
    while (newtail && newtail->next != newhead)
        newtail = newtail->next;
    newtail->next = NULL;
    *stack = newhead; 
}

void	sa(t_list **stack_a)
{
	swap(stack_a);
	ft_printf("sa\n");
}

void	rr(t_list **stack_a, t_list **stack_b)
{
	rotate_up(stack_a);
	rotate_up(stack_b);
	ft_printf("rr\n");
}

void	ra(t_list **stack_a)
{
	rotate_up(stack_a);
	ft_printf("ra\n");
}

void	rb(t_list **stack_b)
{
	rotate_up(stack_b);
	ft_printf("rb\n");
}

void	rrr(t_list **stack_a, t_list **stack_b)
{
	rotate_down(stack_a);
	rotate_down(stack_b);
	ft_printf("rrr\n");
}

void	rra(t_list **stack_a)
{
	rotate_down(stack_a);
	ft_printf("rra\n");
}

void	rrb(t_list **stack_b)
{
	rotate_down(stack_b);
	ft_printf("rrb\n");
}
