/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrigny <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 17:16:50 by yrigny            #+#    #+#             */
/*   Updated: 2023/11/07 17:16:54 by yrigny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*str;

	str = (unsigned char *)s;
	while (n-- > 0)
		*str++ = 0;
}
/*
int	main(void)
{
	unsigned char buffer1[20] = "0123456789ABCDEF";
	unsigned char buffer2[10] = "";
	
	ft_bzero(buffer1, 10);
	printf("Test1 - bzero first 10 bytes of buffer: ");
	for (size_t i = 0; i < sizeof(buffer1); i++)
		printf("%02X ", buffer1[i]);
	printf("\n");
	
	ft_bzero(buffer2, sizeof(buffer2));
	printf("Test2 - bzero all bytes of buffer: ");
	for (size_t i = 0; i < sizeof(buffer2); i++)
		printf("%02X ", buffer2[i]);
	printf("\n");
	return (0);
}*/
