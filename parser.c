/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrigny <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 10:06:24 by yrigny            #+#    #+#             */
/*   Updated: 2023/12/18 18:23:37 by yrigny           ###   ########.fr       */
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
	if (i == 0 || i > 11) // empty argument or beyond int limits
		return (0);
	return (1);
}

long	ft_atoi(char *str)
{
	int	i;
	int	sign;
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

bool	get_num(char *ar, t_list **stack)
{
	long	num;
	t_list	*new;

	num = 0;
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
	new->next = NULL;
	new->last = ft_lstlast(*stack);
	if (*stack == NULL)
		*stack = new;
	else
		new->last->next = new;
	return (1);
}

bool	parser(char **argv, t_list **stack_a)
{
	int	i;

	i = 1;
	while (argv[i])
	{
		if (!get_num(argv[i], stack_a))
		{
			free_stack(stack_a);
			return (0);
		}
		i++;
	}
	return (1);
}

int	main(int argc, char **argv)
{
	t_list	*stack_a;

	stack_a = NULL;
	if (argc < 2)
	{
		printf("No data to sort. Exit.\n");
		return (-1);
	}
	if (!parser(argv, &stack_a))
	{
		printf("Invalid list of data. Exit.\n");
		return (-1);
	}
	while (stack_a)
	{
		printf("%d\n", stack_a->data);
		stack_a = stack_a->next;
	}
	free_stack(&stack_a);
	// iterate argv, check data, create the stack a along the way
	// once meeting a wrong data, free the list and print Error
	// when stack a is ok, start to sort
	// sorter(stack_a); // return the push swap instructions list
	// print the push swap instructions list
	return (0);
}
