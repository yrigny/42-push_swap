/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrigny <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 23:36:40 by yrigny            #+#    #+#             */
/*   Updated: 2024/01/03 23:36:42 by yrigny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	stacklen(t_list *stack)
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

int	max2(int a, int b)
{
	if (a > b)
		return (a);
	else
		return (b);
}

int	min2(int a, int b)
{
	if (a > b)
		return (b);
	else
		return (a);
}

int	get_pushcost(int times_ra, int times_rb, int stacklen_a, int stacklen_b)
{
	int	times_rra;
	int	times_rrb;
	int	mincost;

	times_rra = stacklen_a - times_ra;
	times_rrb = stacklen_b - times_rb;
	mincost = max2(times_ra, times_rb);
	if (max2(times_rra, times_rrb) < mincost)
		mincost = max2(times_rra, times_rrb);
	if (times_ra + times_rrb < mincost)
		mincost = times_ra + times_rrb;
	if (times_rra + times_rb < mincost)
		mincost = times_rra + times_rb;
	return (mincost);
}

void	cost_initiate(t_cost *cost)
{
	cost->cheap_nb = 0;
	cost->times_rr = 0;
	cost->times_ra = 0;
	cost->times_rb = 0;
	cost->times_rrr = 0;
	cost->times_rra = 0;
	cost->times_rrb = 0;
}
