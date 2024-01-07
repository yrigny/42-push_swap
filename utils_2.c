/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yifanr <yifanr@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 23:36:40 by yrigny            #+#    #+#             */
/*   Updated: 2024/01/07 21:10:03 by yrigny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long	ft_atol(const char *str)
{
	int		i;
	int		sign;
	long	num;

	i = 0;
	sign = 1;
	num = 0;
	if (str[i] == '-')
	{
		sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		num = num * 10 + str[i] - '0';
		i++;
	}
	return (sign * num);
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

int	get_cost(int ra, int rb, int len_a, int len_b)
{
	int	rra;
	int	rrb;
	int	mincost;

	rra = len_a - ra;
	rrb = len_b - rb;
	mincost = max2(ra, rb);
	if (max2(rra, rrb) < mincost)
		mincost = max2(rra, rrb);
	if (ra + rrb < mincost)
		mincost = ra + rrb;
	if (rra + rb < mincost)
		mincost = rra + rb;
	return (mincost);
}

void	cost_init(t_cost *cost)
{
	cost->cheap_nb = 0;
	cost->rr = 0;
	cost->ra = 0;
	cost->rb = 0;
	cost->rrr = 0;
	cost->rra = 0;
	cost->rrb = 0;
}
