/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yifanr <yifanr@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 23:35:58 by yrigny            #+#    #+#             */
/*   Updated: 2024/01/07 22:17:27 by yrigny           ###   ########.fr       */
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
		ft_printf("Error\n");
	else
	{
		sorter(&a, stacklen(a));
		free_stack(&a);
	}
	return (0);
}
