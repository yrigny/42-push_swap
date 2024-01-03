#include "push_swap.h"

void	cost_optimize(t_cost *cost, int mincost, int rra, int rrb)
{
	if (max2(cost->times_ra, cost->times_rb) == mincost)
	{
		cost->times_rr = min2(cost->times_ra, cost->times_rb);
		if (ra >= rb)
			cost->times_ra -= cost->times_rr;
		else
			cost->times_rb -= cost->times_rr;
	}
	else if (max2(rra, rrb) == mincost) // rra + rrb is the fastest
	{
		cost->times_ra = 0;
		cost->times_rb = 0;
		cost->times_rrr = min2(rra, rrb);
		if (rra >= rrb)
			cost->times_rra -= cost->times_rrr;
		else
			cost->times_rrb -= cost->times_rrr;
	}
	else if (cost->times_ra + rrb == mincost) // ra + rrb is the fastest
	{
		cost->times_rb = 0;
		cost->times_rrb = rrb;
	}
	else // rra + rb is the fastest
	{
		cost->times_ra = 0;
		cost->times_rra = rra;
	}
}

void    sort_three(t_list **stack, int stacksize)
{
    if (stacksize == 2)
    {
        sa(stack);
        return ;
    }
    if ((*stack)->idx < (*stack)->next->idx && (*stack)->idx < ft_lstlast(*stack)->idx)
    {
        sa(stack);
        ra(stack);
    }
    if ((*stack)->idx > (*stack)->next->idx && (*stack)->idx < ft_lstlast(*stack)->idx)
        sa(stack);
    if ((*stack)->idx < (*stack)->next->idx && (*stack)->idx > ft_lstlast(*stack)->idx)
        rra(stack);
    if ((*stack)->idx > (*stack)->next->idx && (*stack)->idx > ft_lstlast(*stack)->idx)
    {
        ra(stack);
        if (!order_ok(*stack))
            sa(stack);
    }
}

bool    order_ok(t_list *stack)
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
