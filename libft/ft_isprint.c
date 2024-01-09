/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrigny <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 10:46:10 by yrigny            #+#    #+#             */
/*   Updated: 2023/11/07 10:49:41 by yrigny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isprint(int c)
{
	return (c >= 32 && c <= 126);
}
/*
int	main(void)
{
	int c = 32;
	if (isprint(c))
		printf("isprint result: is printable\n");
	else
		printf("isprint result: is not printable\n");
	if (ft_isprint(c))
		printf("ft_isprint result: is printable\n");
	else
		printf("ft_isprint result: is not printable\n");
	return 0;
}*/
