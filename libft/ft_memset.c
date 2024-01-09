/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrigny <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 11:57:56 by yrigny            #+#    #+#             */
/*   Updated: 2023/11/07 11:57:59 by yrigny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*ptr;

	ptr = (unsigned char *)s;
	while (n > 0)
	{
		*ptr = (unsigned char)c;
		ptr++;
		n--;
	}
	return (s);
}
/*
int	main()
{
	unsigned char buffer1[10];
	unsigned char buffer2[10];
	
	ft_memset(buffer1, 0, 10);
	printf("Test1 - memset to 0: ");
	for (size_t i = 0; i < 10; ++i)
		printf("%02x ", buffer1[i]);
	printf("\n");
	ft_memset(buffer2, 'A', 5);
	printf("Test2 - memset to A: %s\n", buffer2);
	printf("Test2 - memset to A: (show hidden char) ");
	for (size_t i = 0; i < 10; ++i)
		printf("%02X ", buffer2[i]);
	printf("\n");
	return 0;
}*/
