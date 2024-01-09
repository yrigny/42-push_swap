/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrigny <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 09:40:47 by yrigny            #+#    #+#             */
/*   Updated: 2023/11/08 09:40:50 by yrigny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	void	*d;

	d = dest;
	while (n-- > 0)
		*(char *)d++ = *(const char *)src++;
	return (dest);
}
/*
int	main()
{
	const char src1[10] = "";
	const char src2[10] = "hello!";
	const char src3[10] = "ABCDEFG";
	char dest[10];
	
	printf("Test1 - src1: %s\n", src1);	
	ft_memcpy(dest, src1, sizeof(src1));
	printf("ft result: ");
	for (size_t i = 0; i < sizeof(dest); ++i)
		printf("%02x ", dest[i]);
	printf("\n");
	printf("og result: ");
	memcpy(dest, src1, sizeof(src1));
	for (size_t i = 0; i < sizeof(dest); ++i)
		printf("%02x ", dest[i]);
	printf("\n");
	
	printf("Test2 - src2: %s\n", src2);
	ft_memcpy(dest, src2, 5);
	printf("ft result: ");
	for (size_t i = 0; i < sizeof(dest); ++i)
		printf("%02x ", dest[i]);
	printf("\n");
	printf("og result: ");
	memcpy(dest, src2, 5);
	for (size_t i = 0; i < sizeof(dest); ++i)
		printf("%02x ", dest[i]);
	printf("\n");
	
	printf("Test3 - src3: %s\n", src3);
	ft_memcpy(dest, src3, sizeof(src3));
	printf("ft result: ");
	for (size_t i = 0; i < sizeof(dest); ++i)
		printf("%02x ", dest[i]);
	printf("\n");
	memcpy(dest, src3, sizeof(src3));
	printf("og result: ");
	for (size_t i = 0; i < sizeof(dest); ++i)
		printf("%02x ", dest[i]);
	printf("\n");
	return 0;
}*/
