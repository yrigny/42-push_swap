/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrigny <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 19:22:16 by yrigny            #+#    #+#             */
/*   Updated: 2024/01/08 19:22:19 by yrigny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*a;
	char	**arg;

	a = NULL;
	arg = NULL;
	if (argc < 2)
		return (0);
	else if (argc == 2)
		arg = ft_split(argv[1], ' ');
	else
		arg = &argv[1];
	if (!parser(argc, arg, &a))
		ft_putstr_fd("Error\n", 2);
	else
	{
		sorter(&a, stacklen(a));
		free_stack(&a);
	}
	return (0);
}
