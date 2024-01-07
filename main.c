/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yifanr <yifanr@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 23:35:58 by yrigny            #+#    #+#             */
/*   Updated: 2024/01/05 17:50:18 by yifanr           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

/*
void	print_stack(t_list *stack)
{
	while (stack)
	{
		ft_printf("%d\n", stack->data);
		stack = stack->next;
	}
}
*/
int	main(int argc, char **argv)
{
	t_list	*stack_a;
	char	**arg;

	stack_a = NULL;
	arg = NULL;
	if (argc < 2)
		return (0);
	else if (argc == 2)
		arg = ft_split(argv[1], ' ');
	else
		arg = &argv[1];
	if (!parser(argc, arg, &stack_a))
		ft_printf("Error\n");
	else
	{
		sorter(&stack_a, stacklen(stack_a));
		free_stack(&stack_a);
	}
	return (0);
}
