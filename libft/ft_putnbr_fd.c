/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrigny <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 15:02:07 by yrigny            #+#    #+#             */
/*   Updated: 2023/11/14 16:18:54 by yrigny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	if (n <= -10 || n >= 10)
	{
		ft_putnbr_fd(n / 10, fd);
		if (n < 0)
			ft_putchar_fd(-(n % 10) + '0', fd);
		else
			ft_putchar_fd(n % 10 + '0', fd);
	}
	else if (n < 0 && n > -10)
	{
		ft_putchar_fd('-', fd);
		ft_putchar_fd(-n + '0', fd);
	}
	else
		ft_putchar_fd(n + '0', fd);
}
