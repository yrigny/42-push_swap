/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrigny <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 19:59:12 by yrigny            #+#    #+#             */
/*   Updated: 2024/01/07 22:21:00 by yrigny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_stack **a)
{
	rotate_up(a);
	ft_printf("ra\n");
}

void	rb(t_stack **b)
{
	rotate_up(b);
	ft_printf("rb\n");
}

void	rrr(t_stack **a, t_stack **b)
{
	rotate_down(a);
	rotate_down(b);
	ft_printf("rrr\n");
}

void	rra(t_stack **a)
{
	rotate_down(a);
	ft_printf("rra\n");
}

void	rrb(t_stack **b)
{
	rotate_down(b);
	ft_printf("rrb\n");
}
