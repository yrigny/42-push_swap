/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yifanr <yifanr@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 11:47:25 by yrigny            #+#    #+#             */
/*   Updated: 2023/11/12 23:07:05 by yifanr           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	len_src;
	size_t	len_dst;
	size_t	i;

	len_src = 0;
	len_dst = 0;
	while (src[len_src])
		len_src++;
	while (dst[len_dst] && len_dst < size)
		len_dst++;
	if (size <= len_dst)
		return (size + len_src);
	i = 0;
	while (len_dst + i < size - 1 && src[i])
	{
		dst[len_dst + i] = src[i];
		i++;
	}
	dst[len_dst + i] = '\0';
	return (len_dst + len_src);
}
/*
int	main(void)
{
	char	dest[] = "";
	char	destv[] = "";
	const char	src[] = "Yifan";
	size_t		size = 0;

	printf("dest \"%s\"\nsrc \"%s\"\nsize = %zu\n", dest, src, size);
	printf("ft_strlcat result \"%zu\"\n", ft_strlcat(dest, src, size));
	printf("strlcat result \"%zu\"\n", strlcat(destv, src, size));
	return (0);
}*/
