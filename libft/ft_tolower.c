/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrigny <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 14:54:35 by yrigny            #+#    #+#             */
/*   Updated: 2023/11/09 14:54:49 by yrigny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_tolower(int c)
{
	if (c >= 65 && c <= 90)
		c += 32;
	return (c);
}
/*
int	main(void)
{
	int	c1 = 'B';
	int	c2 = 'p';
	int	c3 = 42;

	printf("before: %c, after: %c\n", c1, ft_tolower(c1));
	printf("before: %c, after: %c\n", c2, ft_tolower(c2));
	printf("before: %c, after: %c\n", c3, ft_tolower(c3));
	return (0);
}*/
