#include "push_swap.h"

void	swap(t_list **stack)
{
	if (!(*stack) || !(*stack)->next)
		return ;
	(*stack)->last = (*stack)->next;
	(*stack)->next = (*stack)->next->next;
	*stack = (*stack)->last;
	(*stack)->next = (*stack)->last;
	(*stack)->last = NULL;
}

void	push(t_list **from, t_list **to)
{
	if (!(*from))
		return ;
	(*to)->last = *from;
	(*from)->next = *to;
	*to = (*to)->last;
	*from = (*from)->next;
	*from->last = NULL;
}

void	rotate_up(t_list **stack)
{
	if (!(*stack) || !(*stack)->next)
		return ;
	(*stack)->last = ft_lstlast(*stack);
	(*stack)->last->next = *stack;
	*stack = (*stack)->next;
	(*stack)->last = NULL;
	ft_lstlast(*stack)->next = NULL;
}

void	rotate_down(t_list **stack)
{
	if (!(*stack) || !(*stack)->next)
		return ;
	(*stack)->last = ft_lstlast(*stack);
	(*stack)->last->next = *stack;
	*stack = (*stack)->last;
	(*stack)->last = NULL;;
	ft_lstlast(*stack)->next = NULL;
}
