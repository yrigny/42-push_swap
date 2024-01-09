/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrigny <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 21:33:26 by yrigny            #+#    #+#             */
/*   Updated: 2024/01/07 21:40:34 by yrigny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

bool	order_ok(t_stack *stack)
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

bool	isvalid(char *line, t_stack **a, t_stack **b)
{
	if (ft_strncmp(line, "sa\n", 4) == 0)
		return (swap(a));
	if (ft_strncmp(line, "sb\n", 4) == 0)
		return (swap(b));
	if (ft_strncmp(line, "ss\n", 4) == 0)
		return (swap(a) && swap(b));
	if (ft_strncmp(line, "pa\n", 4) == 0)
		return (push(b, a));
	if (ft_strncmp(line, "pb\n", 4) == 0)
		return (push(a, b));
	if (ft_strncmp(line, "ra\n", 4) == 0)
		return (rotate_up(a));
	if (ft_strncmp(line, "rb\n", 4) == 0)
		return (rotate_up(b));
	if (ft_strncmp(line, "rr\n", 4) == 0)
		return (rotate_up(a) && rotate_up(b));
	if (ft_strncmp(line, "rra\n", 5) == 0)
		return (rotate_down(a));
	if (ft_strncmp(line, "rrb\n", 5) == 0)
		return (rotate_down(b));
	if (ft_strncmp(line, "rrr\n", 5) == 0)
		return (rotate_down(a) && rotate_down(b));
	return (0);
}

bool	read_and_do(t_stack **a, t_stack **b)
{
	char	*line;

	line = get_next_line(0);
	while (line)
	{
		if (!isvalid(line, a, b))
		{
			free(line);
			return (0);
		}
		free(line);
		line = get_next_line(0);
	}
	return (1);
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;
	char	**arg;

	a = NULL;
	b = NULL;
	arg = NULL;
	if (argc < 2)
		return (0);
	arg = &argv[1];
	if (argc == 2)
		arg = ft_split(argv[1], ' ');
	if (!parser(argc, arg, &a) || !read_and_do(&a, &b))
	{
		ft_putstr_fd("Error\n", 2);
		return (0);
	}
	if (order_ok(a) && !b)
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
	free_stack(&a);
	free_stack(&b);
	return (0);
}
