/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrigny <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 15:28:53 by yrigny            #+#    #+#             */
/*   Updated: 2023/11/10 15:28:55 by yrigny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *nptr)
{
	int	sign;
	int	num;

	sign = 1;
	num = 0;
	while ((*nptr >= 9 && *nptr <= 13) || *nptr == 32)
		nptr++;
	if (*nptr == '-' || *nptr == '+')
	{
		if (*nptr == '-')
			sign *= -1;
		nptr++;
	}
	while (*nptr >= 48 && *nptr <= 57)
	{
		num = num * 10 + *nptr - '0';
		nptr++;
	}
	return (num * sign);
}
/*
int 	main(void)
{
	const char *tests[] =
	{
		"123",
		"-123",
		"    123",
		"\t\n\v\f\r 45",
		"+123",
		"987xyz",
		"",
		"abc",
		"-0",
		"2147483647",    // INT_MAX
		"-2147483648",   // INT_MIN
	};
	for (int i = 0; i <= 10; i++)
		printf("Test \"%s\": %d\n", tests[i], ft_atoi(tests[i]));
	return 0;
}*/
