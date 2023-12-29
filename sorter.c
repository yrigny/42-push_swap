#include "push_swap.h"

char	**sorter(t_list **stack_a)
{
	t_list		*stack_b;
	static int	*b_min;
	static int	*b_max;

	push(stack_a, &stack_b);
	push(stack_a, &stack_b);
	b_min = &(stack_b->data);
	b_max = &(stack_b->data);
	if (stack_b->next->data < stack_b->data)
		b_min = &(stack_b->next->data);
	else
		b_max = &(stack_b->next->data);
	// do the calculation before making a move
	// apply the best move on the stack(s)
	// record the move in a linked list (return value)
	// if stack a is full and stack b is empty, check if the order's good
	// return the move_log if the order's good
	while (stacklen(stack_a) > 3)
		a_to_b(stack_a, &stack_b, b_min, b_max);
	sort_three(stack_a);
	while (stacklen(stack_b) > 0)
		b_to_a(stack_a, &stack_b);
}

void	a_to_b(t_list **stack_a, t_list **stack_b, int *b_min, int *b_max)
{
	int		*cheapest;

	cheapest = get_cheapest(*stack_a, stack_b, *b_min, *b_max);
	// rotate a, rotate b, pb, update b_min & b_max if needed
}

int	*get_cheapest(t_list *stack_a, t_list *stack_b, int b_min, int b_max)
{
	int	ra_needed;
	int	rb_needed;
	int	pushcost;
	int	mincost;
	int	*cheapest;

	ra_needed = 0;
	mincost = -1;
	cheapest = NULL;
	while (stack_a)
	{
		rb_needed = get_rb_needed(stack_a, stack_b, b_min, b_max);
		pushcost = get_pushcost(ra_needed, rb_needed, stack_a, stack_b);
		if (mincost < 0 || pushcost < mincost)
		{
			mincost = pushcost;
			cheapest = &(stack_a->data);
		}
		stack_a = stack_a->next;
		ra_needed++;
	}
	return (cheapest);
}

int	get_rb_needed(t_list *stack_a, t_list *stack_b, int b_min, int b_max)
{
	int	rb_needed;

	rb_needed = 0;
	if (stack_a->data < b_min || stack_a->data > b_max)
	{
		while (stack_b->data != b_max)
		{
			rb_needed++;
			stack_b = stack_b->next;
		}
		return (rb_needed);
	}
	while (stack_b)
	{
		if (stack_a->idx > stack_b->idx && !stack_b->last && stack_a->idx < ft_lstlast(stack_b)->idx)
			break ;
		if (stack_a->idx > stack_b->idx && stack_b->last && stack_a->idx < stack_b->last->idx)
			break ;
		rb_needed++;
		stack_b = stack_b->next;
	}
	return (rb_needed);
}
