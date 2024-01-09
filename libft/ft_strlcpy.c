/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrigny <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 11:50:59 by yrigny            #+#    #+#             */
/*   Updated: 2023/11/08 11:51:01 by yrigny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	len;
	size_t	cpylen;
	size_t	i;

	len = 0;
	while (src[len])
		len++;
	if (size < 1)
		return (len);
	if (size - 1 >= len)
		cpylen = len;
	if (size - 1 < len)
		cpylen = size - 1;
	i = 0;
	while (i < cpylen)
	{
		*dst++ = *src++;
		i++;
	}
	*dst = '\0';
	return (len);
}
/*
int	main(void)
{
	const char src[20] = "";
	char dst[20];
	const char srcv[20] = "";
	char dstv[20];
	size_t len;		
	size_t lenv;		

	len = strlcpy(dst, src, 10);
	lenv = ft_strlcpy(dstv, srcv, 10);
	printf("len: %zu\n", len);
	printf("lenv: %zu\n", lenv);
	printf("strlcpy result: %s\n", dst);
	printf("ft_strlcpy result: %s\n", dstv);
	return 0;
}*/
