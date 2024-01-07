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

int	main(int argc, char **argv)
{
	t_nlst	*a;
	t_nlst	*b;
	char	**arg;

	a = NULL;
	b = NULL;
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
		// read instruction line by line from stdin, check if error
		char *line = get_next_line(0);
		// if all lines are ok, execute the instructions
		// check if order ok and stack b empty
		// print the result OK / KO
		free_stack(&a);
		free_stack(&b);
	}
	return (0);
}
