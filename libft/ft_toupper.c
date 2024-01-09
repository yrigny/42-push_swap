/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrigny <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 14:38:25 by yrigny            #+#    #+#             */
/*   Updated: 2023/11/09 14:51:25 by yrigny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_toupper(int c)
{
	if (c >= 97 && c <= 122)
		c -= 32;
	return (c);
}
/*
int	main(void)
{
	int	c1 = 'B';
	int	c2 = 'p';
	int	c3 = 42;

	printf("before: %c, after: %c\n", c1, ft_toupper(c1));
	printf("before: %c, after: %c\n", c2, ft_toupper(c2));
	printf("before: %c, after: %c\n", c3, ft_toupper(c3));
	return (0);
}*/
