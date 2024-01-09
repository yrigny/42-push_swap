/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yifanr <yifanr@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 18:03:06 by yrigny            #+#    #+#             */
/*   Updated: 2023/11/11 00:33:33 by yifanr           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub;
	size_t	i;
	size_t	sublen;

	if (!s)
		return (NULL);
	i = 0;
	while (s[i])
		i++;
	sublen = len;
	if (start + len > i)
		sublen = i - start;
	if (start >= i)
		sublen = 0;
	sub = (char *)malloc(sizeof(char) * (sublen + 1));
	if (!sub)
		return (NULL);
	i = 0;
	while (i < sublen && s[start + i])
	{
		sub[i] = s[start + i];
		i++;
	}
	sub[i] = '\0';
	return (sub);
}
/*
int	main()
{
	char const	*s = "This is a test.";
	unsigned int	start = 0;
	size_t		len = 10;

	printf("str: %s\nstart index: %d\nmax len: %zu\n", s, start, len);
	printf("sub: %s\n", ft_substr(s, start, len));
	return (0);
}*/
