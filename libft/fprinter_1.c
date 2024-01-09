/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fprinter_1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yifanr <yifanr@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 13:33:39 by yrigny            #+#    #+#             */
/*   Updated: 2023/11/28 02:37:26 by yifanr           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	putnchar(int n, char c)
{
	int	i;

	i = 0;
	while (i++ < n)
		write(1, &c, 1);
	return (n);
}

int	getulen(unsigned long num, unsigned int baselen)
{
	int	numlen;

	numlen = 1;
	while (num >= baselen)
	{
		numlen += 1;
		num /= baselen;
	}
	return (numlen);
}

long	unsign(long n)
{
	if (n < 0)
		return (-n);
	else
		return (n);
}

void	putunbr_base(unsigned long nbr, char *base, unsigned int baselen)
{
	if (nbr < 0)
		nbr = -nbr;
	if (nbr >= baselen)
	{
		putunbr_base(nbr / baselen, base, baselen);
		write(1, &base[nbr % baselen], 1);
	}
	else
		write(1, &base[nbr], 1);
}

void	fprinter_c(t_flags flags, va_list *p_args, int *p_n)
{
	int		c;

	c = va_arg(*p_args, int);
	if (flags.width > 1 && flags.left == 0)
		*p_n += putnchar(flags.width - 1, ' ');
	*p_n += write(1, &c, 1);
	if (flags.width > 1 && flags.left == 1)
		*p_n += putnchar(flags.width - 1, ' ');
}
