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

int	min4(int a, int b, int c, int d)
{
	int	min;

	min = a;
	if (b < min)
		min = b;
	if (c < min)
		min = c;
	if (d < min)
		min = d;
	return (min);
}

int	get_pushcost(int ra, int rb, t_list *stack_a, t_list *stack_b)
{
	rra = stacklen(stack_a) - ra;
	rrb = stacklen(stack_b) - rb;
	return (min4(max2(ra, rb), max2(rra, rrb), ra + rrb, rra + rb));
}
