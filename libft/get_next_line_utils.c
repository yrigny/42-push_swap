/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrigny <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 14:37:29 by yrigny            #+#    #+#             */
/*   Updated: 2024/01/07 19:13:00 by yrigny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_memcp(char *dest, char *src, size_t n)
{
	while (n-- > 0)
		*(char *)dest++ = *(char *)src++;
	*(char *)dest++ = '\0';
}

int	find_endl(t_lst *stash)
{
	int	i;

	while (stash->next)
		stash = stash->next;
	i = 0;
	while (stash->content[i])
	{
		if (stash->content[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

int	count_line_len(t_lst *stash)
{
	int	line_len;
	int	i;

	line_len = 0;
	while (stash)
	{
		i = 0;
		while (stash->content[i] && stash->content[i] != '\n')
			i++;
		if (stash->content[i] == '\n')
		{
			line_len += i + 1;
			return (line_len);
		}
		line_len += i;
		stash = stash->next;
	}
	return (line_len);
}

void	ft_lstdel_front(t_lst **p_lst)
{
	t_lst	*temp;

	if (!(*p_lst))
		return ;
	temp = (*p_lst)->next;
	free((*p_lst)->content);
	free(*p_lst);
	*p_lst = temp;
}

void	ft_lstadd(t_lst **p_lst, t_lst *new)
{
	t_lst	*temp;

	temp = *p_lst;
	if (!(*p_lst))
		*p_lst = new;
	else
	{
		while (temp->next)
			temp = temp->next;
		temp->next = new;
	}
}
