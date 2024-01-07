/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yifanr <yifanr@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 23:35:19 by yrigny            #+#    #+#             */
/*   Updated: 2024/01/07 22:23:51 by yrigny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	cost_opti(t_cost *cost, int mincost, int rra, int rrb)
{
	if (max2(cost->ra, cost->rb) == mincost)
	{
		cost->rr = min2(cost->ra, cost->rb);
		cost->ra = cost->ra - cost->rr;
		cost->rb = cost->rb - cost->rr;
	}
	else if (max2(rra, rrb) == mincost)
	{
		cost->ra = 0;
		cost->rb = 0;
		cost->rrr = min2(rra, rrb);
		cost->rra = rra - cost->rrr;
		cost->rrb = rrb - cost->rrr;
	}
	else if (cost->ra + rrb == mincost)
	{
		cost->rb = 0;
		cost->rrb = rrb;
	}
	else
	{
		cost->ra = 0;
		cost->rra = rra;
	}
}

void	sa(t_stack **a)
{
	swap(a);
	ft_printf("sa\n");
}

void	sort_three(t_stack **stack, int stacksize)
{
	if (stacksize == 2)
	{
		sa(stack);
		return ;
	}
	if ((*stack)->idx < (*stack)->next->idx
		&& (*stack)->idx < ft_lastn(*stack)->idx)
	{
		sa(stack);
		ra(stack);
	}
	if ((*stack)->idx > (*stack)->next->idx
		&& (*stack)->idx < ft_lastn(*stack)->idx)
		sa(stack);
	if ((*stack)->idx < (*stack)->next->idx
		&& (*stack)->idx > ft_lastn(*stack)->idx)
		rra(stack);
	if ((*stack)->idx > (*stack)->next->idx
		&& (*stack)->idx > ft_lastn(*stack)->idx)
	{
		ra(stack);
		if (!order_ok(*stack))
			sa(stack);
	}
}

void	b_descend(t_stack **b, int b_max)
{
	int		rotate;
	t_stack	*tmp;

	rotate = 0;
	tmp = *b;
	if ((*b)->data == b_max)
		return ;
	while (tmp && tmp->data != b_max)
	{
		rotate++;
		tmp = tmp->next;
	}
	if (rotate <= stacklen(*b) - rotate)
	{
		while (rotate-- > 0)
			rb(b);
	}
	else
	{
		rotate = stacklen(*b) - rotate;
		while (rotate-- > 0)
			rrb(b);
	}
}

void	a_ascend(t_stack **a)
{
	int		rotate;
	t_stack	*tmp;

	rotate = 0;
	tmp = *a;
	if ((*a)->idx == 1)
		return ;
	while (tmp && tmp->idx != 1)
	{
		rotate++;
		tmp = tmp->next;
	}
	if (rotate <= stacklen(*a) - rotate)
	{
		while (rotate-- > 0)
			ra(a);
	}
	else
	{
		rotate = stacklen(*a) - rotate;
		while (rotate-- > 0)
			rra(a);
	}
}
