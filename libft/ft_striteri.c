/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrigny <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 11:55:06 by yrigny            #+#    #+#             */
/*   Updated: 2023/11/14 13:58:32 by yrigny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*
void	iteri(unsigned int i, char *s)
{
	if (i == 0 && *s >= 'a' && *s <= 'z')
		*s -= 32;
	else if (i != 0 && *s >= 'A' && *s <= 'Z')
		*s += 32;
}
*/
void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	unsigned int	i;

	if (s == NULL)
		return ;
	i = -1;
	while (s[++i])
		(*f)(i, &s[i]);
	return ;
}
/*
int	main()
{
	char	s[] = "hEllO, WoRld";
	void	(*f)(unsigned int, char*) = &iteri;

	ft_striteri(s, f);
	printf("%s\n", s);
	return (0);
}*/
