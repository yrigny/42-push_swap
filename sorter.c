/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorter.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrigny <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 19:24:19 by yrigny            #+#    #+#             */
/*   Updated: 2024/01/08 19:24:21 by yrigny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sorter(t_stack **a, int stacksize)
{
	t_stack			*b;
	static t_range	range_b;

	b = NULL;
	if (stacksize == 1 || (stacksize > 1 && order_ok(*a)))
		return ;
	else if (stacksize == 2 || stacksize == 3)
		sort_three(a, stacksize);
	else
	{
		push(a, &b);
		push(a, &b);
		ft_printf("pb\npb\n");
		range_b.min = min(b->data, b->next->data);
		range_b.max = max(b->data, b->next->data);
		while (stacklen(*a) > 3)
			a_to_b(a, &b, &range_b, stacklen(*a));
		b_descend(&b, range_b.max);
		if (!order_ok(*a))
			sort_three(a, stacklen(*a));
		while (stacklen(b) > 0)
			b_to_a(a, &b);
		a_ascend(a);
	}
}

void	b_to_a(t_stack **a, t_stack **b)
{
	int		rotate;
	t_stack	*tmp;

	rotate = 0;
	tmp = *a;
	while (tmp && tmp->idx != (*b)->idx + 1)
	{
		rotate++;
		tmp = tmp->next;
	}
	if (rotate != 0 && rotate <= stacklen(*a) - rotate)
	{
		while (rotate-- > 0)
			ra(a);
	}
	if (rotate != 0 && rotate > stacklen(*a) - rotate)
	{
		rotate = stacklen(*a) - rotate;
		while (rotate-- > 0)
			rra(a);
	}
	push(b, a);
	ft_printf("pa\n");
}

void	a_to_b(t_stack **a, t_stack **b, t_range *range_b, int len_a)
{
	t_cost	cost;

	cost = cheapest(*a, *b, *range_b, len_a);
	while (cost.rr-- > 0)
		rr(a, b);
	while (cost.ra-- > 0)
		ra(a);
	while (cost.rb-- > 0)
		rb(b);
	while (cost.rrr-- > 0)
		rrr(a, b);
	while (cost.rra-- > 0)
		rra(a);
	while (cost.rrb-- > 0)
		rrb(b);
	push(a, b);
	ft_printf("pb\n");
	if (cost.cheap_nb < (*range_b).min)
		(*range_b).min = cost.cheap_nb;
	if (cost.cheap_nb > (*range_b).max)
		(*range_b).max = cost.cheap_nb;
}

t_cost	cheapest(t_stack *a, t_stack *b, t_range range_b, int len_a)
{
	int		ra_needed;
	int		rb_needed;
	int		mincost;
	int		pushcost;
	t_cost	cost;

	ra_needed = 0;
	mincost = -1;
	cost_init(&cost);
	while (a)
	{
		rb_needed = get_rb_needed(a, b, range_b.min, range_b.max);
		pushcost = get_cost(ra_needed, rb_needed, len_a, stacklen(b));
		if (mincost < 0 || pushcost < mincost)
		{
			mincost = pushcost;
			cost.cheap_nb = a->data;
			cost.ra = ra_needed;
			cost.rb = rb_needed;
		}
		a = a->next;
		ra_needed++;
	}
	cost_opti(&cost, mincost, len_a - cost.ra, stacklen(b) - cost.rb);
	return (cost);
}

int	get_rb_needed(t_stack *a, t_stack *b, int b_min, int b_max)
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
	if (a->idx > b->idx && a->idx < lastnb(b)->idx)
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
