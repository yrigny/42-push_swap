/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fprinter_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yifanr <yifanr@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 19:44:18 by yrigny            #+#    #+#             */
/*   Updated: 2023/11/29 01:34:56 by yifanr           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	fprinter_s(t_flags flags, va_list *p_args, int *p_n)
{
	char	*s;
	int		printable_s;

	s = va_arg(*p_args, char *);
	if (!s)
		printable_s = 6;
	else
		printable_s = ft_strlen(s);
	if (flags.dot == 1 && flags.precis < printable_s)
		printable_s = flags.precis;
	if (flags.width > printable_s && flags.left == 0)
		*p_n += putnchar(flags.width - printable_s, ' ');
	if (!s && printable_s >= 6)
		*p_n += write(1, "(null)", 6);
	if (s)
		*p_n += write(1, s, printable_s);
	if (flags.width > printable_s && flags.left == 1)
		*p_n += putnchar(flags.width - printable_s, ' ');
}

void	fprinter_p(t_flags flags, va_list *p_args, int *p_n)
{
	void	*p;
	int		printable_p;

	p = va_arg(*p_args, void *);
	if (!p)
		printable_p = 5;
	else
		printable_p = getulen((unsigned long)p, 16) + 2;
	if (flags.width > printable_p && flags.left == 0)
		*p_n += putnchar(flags.width - printable_p, ' ');
	if (p)
		write(1, "0x", 2);
	if (!p)
		write(1, "(nil)", 5);
	else
		putunbr_base((unsigned long)p, "0123456789abcdef", 16);
	*p_n += printable_p;
	if (flags.width > printable_p && flags.left == 1)
		*p_n += putnchar(flags.width - printable_p, ' ');
}

void	fprinter_d(t_flags flags, va_list *p_args, int *p_n)
{
	int	d;
	int	printable_d;

	d = va_arg(*p_args, int);
	printable_d = getulen(unsign(d), 10);
	if (flags.precis > printable_d || (!d && flags.dot && !flags.precis))
		printable_d = flags.precis;
	if (flags.plus == 1 || flags.space == 1 || d < 0)
		printable_d += 1;
	if (flags.width > printable_d && flags.left == 0 && flags.zero == 0)
		*p_n += putnchar(flags.width - printable_d, ' ');
	*p_n += write(1, "+", (flags.plus == 1 && d >= 0));
	*p_n += write(1, " ", (flags.space == 1 && d >= 0));
	*p_n += write(1, "-", (d < 0));
	if (flags.width > printable_d && flags.zero == 1)
		*p_n += putnchar(flags.width - printable_d, '0');
	if (flags.precis > getulen(unsign(d), 10))
		*p_n += putnchar(flags.precis - getulen(unsign(d), 10), '0');
	if (!(d == 0 && flags.dot == 1 && flags.precis == 0))
	{
		putunbr_base(unsign(d), "0123456789", 10);
		*p_n += getulen(unsign(d), 10);
	}
	if (flags.width > printable_d && flags.left == 1)
		*p_n += putnchar(flags.width - printable_d, ' ');
}

void	fprinter_u(t_flags flags, va_list *p_args, int *p_n)
{
	unsigned int	u;
	int				numlen;
	int				printable_u;

	u = va_arg(*p_args, unsigned int);
	numlen = getulen((long)u, 10);
	printable_u = numlen;
	if (flags.precis > printable_u || (!u && flags.dot && !flags.precis))
		printable_u = flags.precis;
	if (flags.width > printable_u && flags.zero == 1)
		*p_n += putnchar(flags.width - printable_u, '0');
	else if (flags.width > printable_u && flags.left == 0)
		*p_n += putnchar(flags.width - printable_u, ' ');
	if (flags.precis > numlen)
		*p_n += putnchar(flags.precis - numlen, '0');
	if (!(u == 0 && flags.dot == 1 && flags.precis == 0))
	{
		putunbr_base(u, "0123456789", 10);
		*p_n += numlen;
	}
	if (flags.width > printable_u && flags.left == 1)
		*p_n += putnchar(flags.width - printable_u, ' ');
}

void	fprinter_x(t_flags flags, va_list *p_args, int *p_n, char *base)
{
	unsigned int	x;
	int				numlen;
	int				printable_x;

	x = va_arg(*p_args, unsigned int);
	numlen = getulen(x, 16);
	printable_x = numlen;
	if (flags.precis > printable_x || (!x && flags.dot && !flags.precis))
		printable_x = flags.precis;
	if (flags.hash == 1)
		printable_x += 2;
	if (flags.width > printable_x && flags.left == 0 && flags.zero == 0)
		*p_n += putnchar(flags.width - printable_x, ' ');
	*p_n += write(1, "0x", 2 * (x != 0 && flags.hash && flags.type == 'x'));
	*p_n += write(1, "0X", 2 * (x != 0 && flags.hash && flags.type == 'X'));
	if (flags.width > printable_x && flags.zero == 1)
		*p_n += putnchar(flags.width - printable_x, '0');
	else if (flags.precis > numlen)
		*p_n += putnchar(flags.precis - numlen, '0');
	if (!(x == 0 && flags.dot == 1 && flags.precis == 0))
		putunbr_base(x, base, 16);
	if (!(x == 0 && flags.dot == 1 && flags.precis == 0))
		*p_n += numlen;
	if (flags.width > printable_x && flags.left == 1)
		*p_n += putnchar(flags.width - printable_x, ' ');
}
