/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrigny <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 08:36:09 by yrigny            #+#    #+#             */
/*   Updated: 2023/11/13 12:06:53 by yrigny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	len;

	if (s1 == NULL || set == NULL)
		return (NULL);
	while (*s1 && ft_strchr(set, *s1))
		s1++;
	len = ft_strlen(s1);
	while (len && ft_strchr(set, s1[len]))
		--len;
	return (ft_substr(s1, 0, len + 1));
}
/*
int	main()
{
	char const	*s1 = " test !  ";
	char const	*set = " !";
	char		*res = ft_strtrim(s1, set);

	printf("s1 :%s\n", s1);
	printf("set:%s\n", set);
	printf("res:%s\n", res);
	return (0);
}*/
