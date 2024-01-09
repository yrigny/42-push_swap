/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrigny <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 17:42:35 by yrigny            #+#    #+#             */
/*   Updated: 2023/11/06 17:42:41 by yrigny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isdigit(int c)
{
	if (c >= 48 && c <= 57)
		return (1);
	return (0);
}
/*
int	main(void)
{
	int c = 'L';
	if (isdigit(c))
		printf("isdigit result: is digit\n");
	else
		printf("isdigit result: is not digit\n");
	if (ft_isdigit(c))
		printf("ft_isdigit result: is digit\n");
	else
		printf("ft_isdigit result: is not digit\n");
	return 0;
}*/
