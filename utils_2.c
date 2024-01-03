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

int	get_pushcost(int ra, int rb, t_list *stack_a, t_list *stack_b)
{
	int	rra;
	int rrb;
	int min;

	rra = stacklen(stack_a) - ra;
	rrb = stacklen(stack_b) - rb;
	min = max2(ra, rb);
	if (max2(rra, rrb) < min)
		min = max2(rra, rrb);
	if (ra + rrb < min)
		min = ra + rrb;
	if (rra + rb)
		min = rra + rb;
	return (min);
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
