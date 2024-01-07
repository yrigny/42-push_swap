/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yifanr <yifanr@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 23:35:19 by yrigny            #+#    #+#             */
/*   Updated: 2024/01/05 01:59:37 by yifanr           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	cost_optimize(t_cost *cost, int mincost, int times_rra, int times_rrb)
{
	if (max2(cost->times_ra, cost->times_rb) == mincost)
	{
		cost->times_rr = min2(cost->times_ra, cost->times_rb);
		cost->times_ra = cost->times_ra - cost->times_rr;
		cost->times_rb = cost->times_rb - cost->times_rr;
	}
	else if (max2(times_rra, times_rrb) == mincost)
	{
		cost->times_ra = 0;
		cost->times_rb = 0;
		cost->times_rrr = min2(times_rra, times_rrb);
		cost->times_rra = times_rra - cost->times_rrr;
		cost->times_rrb = times_rrb - cost->times_rrr;
	}
	else if (cost->times_ra + times_rrb == mincost)
	{
		cost->times_rb = 0;
		cost->times_rrb = times_rrb;
	}
	else
	{
		cost->times_ra = 0;
		cost->times_rra = times_rra;
	}
}

void	sort_three(t_list **stack, int stacksize)
{
	if (stacksize == 2)
	{
		sa(stack);
		return ;
	}
	if ((*stack)->idx < (*stack)->next->idx
		&& (*stack)->idx < ft_lstlast(*stack)->idx)
	{
		sa(stack);
		ra(stack);
	}
	if ((*stack)->idx > (*stack)->next->idx
		&& (*stack)->idx < ft_lstlast(*stack)->idx)
		sa(stack);
	if ((*stack)->idx < (*stack)->next->idx
		&& (*stack)->idx > ft_lstlast(*stack)->idx)
		rra(stack);
	if ((*stack)->idx > (*stack)->next->idx
		&& (*stack)->idx > ft_lstlast(*stack)->idx)
	{
		ra(stack);
		if (!order_ok(*stack))
			sa(stack);
	}
}

bool	order_ok(t_list *stack)
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

void	b_descend(t_list **stack_b, int b_max)
{
	int		rotate;
	t_list	*tmp;

	rotate = 0;
	tmp = *stack_b;
	if ((*stack_b)->data == b_max)
		return ;
	while (tmp && tmp->data != b_max)
	{
		rotate++;
		tmp = tmp->next;
	}
	if (rotate <= stacklen(*stack_b) - rotate)
	{
		while (rotate-- > 0)
			rb(stack_b);
	}
	else
	{
		rotate = stacklen(*stack_b) - rotate;
		while (rotate-- > 0)
			rrb(stack_b);
	}
}

void	a_ascend(t_list **stack_a)
{
	int		rotate;
	t_list	*tmp;

	rotate = 0;
	tmp = *stack_a;
	if ((*stack_a)->idx == 1)
		return ;
	while (tmp && tmp->idx != 1)
	{
		rotate++;
		tmp = tmp->next;
	}
	if (rotate <= stacklen(*stack_a) - rotate)
	{
		while (rotate-- > 0)
			ra(stack_a);
	}
	else
	{
		rotate = stacklen(*stack_a) - rotate;
		while (rotate-- > 0)
			rra(stack_a);
	}
}
