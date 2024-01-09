/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrigny <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 16:36:12 by yrigny            #+#    #+#             */
/*   Updated: 2023/11/09 16:36:15 by yrigny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned int	i;

	i = 0;
	if (n == 0)
		return (0);
	while (s1[i] && s2[i] && s1[i] == s2[i] && i < n - 1)
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}
/*
int	main(void)
{
	char	str1[] = "";
	char	str2[] = "abcdefg";
	char	str3[] = "abcd";

	printf("ft_strncmp \"%s\", \"%s\", 0: %d\n", str1, str2,
	ft_strncmp(str1, str2, 0));
	printf("strncmp    \"%s\", \"%s\", 0: %d\n", str1, str2, strncmp(str1,
	str2,0));
	printf("ft_strncmp \"%s\", \"%s\", 3: %d\n", str2, str3,
	ft_strncmp(str2, str3, 3));
	printf("strncmp    \"%s\", \"%s\", 3: %d\n", str2, str3, strncmp(str2,
	str3, 3));
	printf("ft_strncmp \"%s\", \"%s\", 8: %d\n", str2, str3,
	ft_strncmp(str2, str3, 8));
	printf("strncmp    \"%s\", \"%s\", 8: %d\n", str2, str3, strncmp(str2,
	str3, 8));
}*/
