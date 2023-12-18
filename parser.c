/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrigny <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 10:06:24 by yrigny            #+#    #+#             */
/*   Updated: 2023/12/18 13:25:00 by yrigny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool	numeric(char *ar)
{
	int	i;

	i = 0;
	if (ar == "")
		return (0);
	if (ar[0] == '-')
		i += 1;
	while (ar[i])
	{
		if (!ft_strchr("0123456789", ar[i]))
			return (0);
		i++;
	}
	if (i > 11) // beyond int limits
		return (0);
	return (1);
}

long	ft_atoi(char *str)
{
	int	sign;
	long	num;

	sign = 1;
	num = 0;
	if (*str == '-')
	{
		sign = -1;
		*str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		num = num * 10 + *str - '0';
		*str++;
	}
	return (sign * num);
}

bool	unique(int num, t_list *stack)
{
	if (stack == NULL)
		return (1);
	while (stack)
}

bool	get_num(char *ar, t_list *stack)
{
	long	num;

	num = 0;
	// invalid: not numeric, overflow, duplicate
	if (!numeric(ar))
		return (0);
	num = ft_atoi(ar);
	if (num == 0 && ar != "0")
		return (0);
	if (num > INT_MAX || num < INT_MIN)
		return (0);
	if (!unique((int)num, stack))
		return (0);
	// lst_add_back((int)num, stack_a);
	return (1);
}

bool	parser(int argc, char **argv, t_list **stack_a)
{
	int	i;

	i = 1;
	while (argv[i])
	{
		printf("%s ", argv[i]);
		if (!get_num(argv[i], *stack_a))
		{
			free_stack(stack_a);
			return (0);
		}
		i++;
	}
}

int	main(int argc, char **argv)
{
	t_list	*stack_a;

	stack_a = NULL;
	if (argc < 2)
	{
		printf("No data to sort. Exit.");
		return (-1);
	}
	if (!parser(argc, argv, *stack_a))
	{
		printf("Invalid list of data. Exit.");
		return (-1);
	}
	// iterate argv, check data, create the stack a along the way
	// once meeting a wrong data, free the list and print Error
	// when stack a is ok, start to sort
	sorter(stack_a); // return the push swap instructions list
	// print the push swap instructions list
	return (0);
}
