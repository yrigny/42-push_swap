/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrigny <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 10:40:07 by yrigny            #+#    #+#             */
/*   Updated: 2023/11/07 10:40:11 by yrigny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isascii(int c)
{
	return (c >= 0 && c <= 127);
}
/*
int	main(void)
{
	int c = -42;
	if (isascii(c))
		printf("isascii result: is ascii\n");
	else
		printf("isascii result: is not ascii\n");
	if (ft_isascii(c))
		printf("ft_isascii result: is ascii\n");
	else
		printf("ft_isascii result: is not ascii\n");
	return 0;
}*/
