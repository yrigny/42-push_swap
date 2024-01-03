/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrigny <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 10:06:24 by yrigny            #+#    #+#             */
/*   Updated: 2023/12/20 16:07:08 by yrigny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool	numeric(char *ar)
{
	int	i;

	i = 0;
	if (ar[0] == '-' && ar[1] && ft_strchr("123456789", ar[1]))
		i++;
	while (ar[i])
	{
		if (!ft_strchr("0123456789", ar[i]))
			return (0);
		if (ar[i] == '0' && ar[i + 1])
			return (0);
		i++;
	}
	if (i == 0 || i > 11)
		return (0);
	return (1);
}

bool	unique(int num, t_list *stack)
{
	if (stack == NULL)
		return (1);
	while (stack)
	{
		if (stack->data == num)
			return (0);
		stack = stack->next;
	}
	return (1);
}

int	get_idx(int num, t_list *stack)
{
	int	idx;

	idx = 1;
	while (stack)
	{
		if (num == stack->data)
			return (0);
		if (num > stack->data)
			idx++;
		if (num < stack->data)
			stack->idx++;
		stack = stack->next;
	}
	return (idx);
}

bool	get_num(char *ar, t_list **stack)
{
	long	num;
	t_list	*new;

	new = NULL;
	if (!numeric(ar))
		return (0);
	num = ft_atoi(ar);
	if (num > INT_MAX || num < INT_MIN)
		return (0);
	if (!unique((int)num, *stack))
		return (0);
	new = malloc(sizeof(t_list));
	if (!new)
		return (0);
	new->data = (int)num;
	new->idx = get_idx((int)num, *stack);
	new->next = NULL;
	new->last = ft_lstlast(*stack);
	if (*stack == NULL)
		*stack = new;
	else
		new->last->next = new;
	return (1);
}

bool	parser(int argc, char **argv, t_list **stack_a)
{
	int	i;
	int	data_ok;

	i = 1;
	data_ok = 1;
	if (argc == 2)
		argv = ft_split(argv[1], ' ');
	if (argc == 2)
		i = 0;
	while (argv[i])
	{
		if (!get_num(argv[i], stack_a))
		{
			data_ok = 0;
			free_stack(stack_a);
			break ;
		}
		i++;
	}
	if (argc == 2)
		free_argv(argv);
	return (data_ok);
}
