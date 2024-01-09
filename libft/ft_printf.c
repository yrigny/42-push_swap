/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yifanr <yifanr@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 14:11:59 by yrigny            #+#    #+#             */
/*   Updated: 2023/11/29 01:32:43 by yifanr           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	parseflag(t_flags *p_flags, const char *fstr)
{
	while (*fstr && ft_strchr("-+ #0", *fstr))
	{
		if (*fstr == '-')
			p_flags->left = 1;
		if (*fstr == '+')
			p_flags->plus = 1;
		if (*fstr == ' ')
			p_flags->space = 1;
		if (*fstr == '#')
			p_flags->hash = 1;
		if (*fstr == '0')
			p_flags->zero = 1;
		fstr++;
	}
	if (*fstr && *fstr >= '1' && *fstr <= '9')
		p_flags->width = ft_atoi(fstr);
	while (*fstr && *fstr >= '0' && *fstr <= '9')
		fstr++;
	if (*fstr == '.')
		p_flags->dot = 1;
	if (*fstr == '.')
		p_flags->precis = ft_atoi(fstr + 1);
	while (*fstr && !ft_strchr("cspdiuxX%", *fstr))
		fstr++;
	p_flags->type = *fstr;
}

void	iniflagset(t_flags *p_flags)
{
	p_flags->left = 0;
	p_flags->plus = 0;
	p_flags->space = 0;
	p_flags->hash = 0;
	p_flags->zero = 0;
	p_flags->width = 0;
	p_flags->dot = 0;
	p_flags->precis = 0;
	p_flags->type = 0;
}

void	fprinter(const char *fstr, va_list *p_args, int *p_n)
{
	t_flags	flags;

	iniflagset(&flags);
	parseflag(&flags, fstr);
	if (flags.left == 1)
		flags.zero = 0;
	if (flags.plus == 1)
		flags.space = 0;
	if (flags.dot == 1)
		flags.zero = 0;
	if (flags.type == 'c')
		fprinter_c(flags, p_args, p_n);
	if (flags.type == 's')
		fprinter_s(flags, p_args, p_n);
	if (flags.type == 'p')
		fprinter_p(flags, p_args, p_n);
	if (flags.type == 'd' || flags.type == 'i')
		fprinter_d(flags, p_args, p_n);
	if (flags.type == 'u')
		fprinter_u(flags, p_args, p_n);
	if (flags.type == 'x')
		fprinter_x(flags, p_args, p_n, "0123456789abcdef");
	if (flags.type == 'X')
		fprinter_x(flags, p_args, p_n, "0123456789ABCDEF");
	*p_n += write(1, "%", (flags.type == '%'));
}

void	printer(const char *fstr, va_list *p_args, int *p_n)
{
	int	i;

	i = 0;
	while (fstr[i])
	{
		while (fstr[i] && fstr[i] != '%')
		{
			*p_n += write(1, &fstr[i], 1);
			i++;
		}
		if (fstr[i] == '%')
		{
			i += 1;
			fprinter(&fstr[i], p_args, p_n);
			while (fstr[i] && !ft_strchr("cspdiuxX%", fstr[i]))
				i++;
			i += 1;
		}
	}
}

int	ft_printf(const char *fstr, ...)
{
	va_list	args;
	int		n;

	n = 0;
	if (!fstr)
		return (-1);
	va_start(args, fstr);
	printer(fstr, &args, &n);
	va_end(args);
	return (n);
}
