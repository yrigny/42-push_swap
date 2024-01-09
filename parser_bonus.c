/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrigny <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 19:23:13 by yrigny            #+#    #+#             */
/*   Updated: 2024/01/08 19:23:15 by yrigny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

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
		i++;
	}
	if (i == 0 || i > 11)
		return (0);
	if (ar[0] == '0' && ar[1])
		return (0);
	return (1);
}

bool	unique(int nb, t_stack *a)
{
	if (a == NULL)
		return (1);
	while (a)
	{
		if (a->data == nb)
			return (0);
		a = a->next;
	}
	return (1);
}

int	get_idx(int nb, t_stack *a)
{
	int	idx;

	idx = 1;
	while (a)
	{
		if (nb == a->data)
			return (0);
		if (nb > a->data)
			idx++;
		if (nb < a->data)
			a->idx++;
		a = a->next;
	}
	return (idx);
}

bool	get_nb(char *ar, t_stack **a)
{
	long	nb;
	t_stack	*new;

	new = NULL;
	if (!numeric(ar))
		return (0);
	nb = ft_atol(ar);
	if (nb > INT_MAX || nb < INT_MIN)
		return (0);
	if (!unique((int)nb, *a))
		return (0);
	new = malloc(sizeof(t_stack));
	if (!new)
		return (0);
	new->data = (int)nb;
	new->idx = get_idx((int)nb, *a);
	new->next = NULL;
	if (*a == NULL)
		*a = new;
	else
		lastnb(*a)->next = new;
	return (1);
}

bool	parser(int argc, char **arg, t_stack **a)
{
	int		i;
	bool	data_ok;

	i = 0;
	data_ok = 1;
	if (!(*arg))
		data_ok = 0;
	while (data_ok && arg[i])
	{
		if (!get_nb(arg[i], a))
		{
			data_ok = 0;
			free_stack(a);
		}
		i++;
	}
	if (argc == 2)
		free_arg(arg);
	return (data_ok);
}
