/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrigny <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 17:56:27 by yrigny            #+#    #+#             */
/*   Updated: 2023/11/06 17:56:29 by yrigny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(int c)
{
	if ((c >= 48 && c <= 57) || (c > 64 && c < 91) || (c > 96 && c < 123))
		return (1);
	return (0);
}
/*
int	main(void)
{
	int c = '?';
	if (isalnum(c))
		printf("isalnum result: is alnum\n");
	else
		printf("isalnum result: is not alnum\n");
	if (ft_isalnum(c))
		printf("ft_isalnum result: is alnum\n");
	else
		printf("ft_isalnum result: is not alnum\n");
	return 0;
}*/
