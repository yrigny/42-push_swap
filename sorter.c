/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorter.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yifanr <yifanr@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 23:36:21 by yrigny            #+#    #+#             */
/*   Updated: 2024/01/07 03:13:15 by yifanr           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sorter(t_list **stack_a, int stacksize)
{
	t_list		*stack_b;
	static int	b_min;
	static int	b_max;

	stack_b = NULL;
	if (stacksize == 1 || (stacksize > 1 && order_ok(*stack_a)))
		return ;
	else if (stacksize == 2 || stacksize == 3)
		sort_three(stack_a, stacksize);
	else
	{
		push(stack_a, &stack_b);
		push(stack_a, &stack_b);
		ft_printf("pb\npb\n");
		b_min = min2(stack_b->data, stack_b->next->data);
		b_max = max2(stack_b->data, stack_b->next->data);
		while (stacklen(*stack_a) > 3)
			a_to_b(stack_a, &stack_b, &b_min, &b_max, stacklen(*stack_a));
		b_descend(&stack_b, b_max);
		if (!order_ok(*stack_a))
			sort_three(stack_a, stacklen(*stack_a));
		while (stacklen(stack_b) > 0)
			b_to_a(stack_a, &stack_b);
		a_ascend(stack_a);
	}
}

void	b_to_a(t_list **stack_a, t_list **stack_b)
{
	int		rotate;
	t_list	*tmp;

	rotate = 0;
	tmp = *stack_a;
	while (tmp && tmp->idx != (*stack_b)->idx + 1)
	{
		rotate++;
		tmp = tmp->next;
	}
	if (rotate != 0 && rotate <= stacklen(*stack_a) - rotate)
	{
		while (rotate-- > 0)
			ra(stack_a);
	}
	if (rotate != 0 && rotate > stacklen(*stack_a) - rotate)
	{
		rotate = stacklen(*stack_a) - rotate;
		while (rotate-- > 0)
			rra(stack_a);
	}
	push(stack_b, stack_a);
	ft_printf("pa\n");
}

void	a_to_b(t_list **stack_a, t_list **stack_b, int *b_min, int *b_max, int stacklen_a)
{
	t_cost	cost;

	cost = get_cheapest(*stack_a, *stack_b, *b_min, *b_max, stacklen_a);
	while (cost.times_rr-- > 0)
		rr(stack_a, stack_b);
	while (cost.times_ra-- > 0)
		ra(stack_a);
	while (cost.times_rb-- > 0)
		rb(stack_b);
	while (cost.times_rrr-- > 0)
		rrr(stack_a, stack_b);
	while (cost.times_rra-- > 0)
		rra(stack_a);
	while (cost.times_rrb-- > 0)
		rrb(stack_b);
	push(stack_a, stack_b);
	ft_printf("pb\n");
	if (cost.cheap_nb < *b_min)
		*b_min = cost.cheap_nb;
	if (cost.cheap_nb > *b_max)
		*b_max = cost.cheap_nb;
}

t_cost	get_cheapest(t_list *stack_a, t_list *stack_b, int b_min, int b_max, int stacklen_a)
{
	int		ra_needed;
	int		rb_needed;
	int		mincost;
	int		pushcost;
	t_cost	cost;

	ra_needed = 0;
	mincost = -1;
	cost_initiate(&cost);
	while (stack_a)
	{
		rb_needed = get_rb_needed(stack_a, stack_b, b_min, b_max);
		pushcost = get_pushcost(ra_needed, rb_needed, stacklen_a, stacklen(stack_b));
		if (mincost < 0 || pushcost < mincost)
		{
			mincost = pushcost;
			cost.cheap_nb = stack_a->data;
			cost.times_ra = ra_needed;
			cost.times_rb = rb_needed;
		}
		stack_a = stack_a->next;
		ra_needed++;
	}
	cost_optimize(&cost, mincost, stacklen_a - cost.times_ra, stacklen(stack_b) - cost.times_rb);
	return (cost);
}

int	get_rb_needed(t_list *a, t_list *b, int b_min, int b_max)
{
	int	rb_needed;

	rb_needed = 0;
	if (a->data < b_min || a->data > b_max)
	{
		while (b->data != b_max)
		{
			rb_needed++;
			b = b->next;
		}
		return (rb_needed);
	}
	if (a->idx > b->idx && a->idx < ft_lstlast(b)->idx)
		return (rb_needed);
	rb_needed += 1;
	while (b && b->next)
	{
		if (a->idx > b->next->idx && a->idx < b->idx)
			break ;
		rb_needed++;
		b = b->next;
	}
	return (rb_needed);
}
