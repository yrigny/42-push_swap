/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrigny <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 11:15:44 by yrigny            #+#    #+#             */
/*   Updated: 2023/11/08 11:15:51 by yrigny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	void	*d;

	if (src == NULL || dest == NULL)
		return (NULL);
	d = dest;
	if (dest > src && dest < src + n)
	{
		dest += n - 1;
		src += n - 1;
		while (n-- > 0)
			*(char *)dest-- = *(char *)src--;
	}
	else
		while (n-- > 0)
			*(char *)dest++ = *(char *)src++;
	return (d);
}
/*
int 	main()
{
	char test1[20] = "Example String";
	char test1_copy[20];

	char test2[20] = "Overlap Test";
	char test2_copy[20];

	char test3[20] = "Another Test";
	char test3_copy[20];

    	// Test 1 - Non-overlapping
	printf("Test 1 - Non-overlapping:\n");
	strcpy(test1_copy, test1); // Reset the copy for the standard memmove
	ft_memmove(test1 + 8, test1, 7);
	memmove(test1_copy + 8, test1_copy, 7);
	printf("ft_memmove result: %s\n", test1);
	printf("memmove result:    %s\n", test1_copy);

	// Test 2 - Overlapping, dest ahead of src
	printf("\nTest 2 - Overlapping, dest ahead of src:\n");
	strcpy(test2_copy, test2); // Reset the copy for the standard memmove
	ft_memmove(test2 + 2, test2, 9);
	memmove(test2_copy + 2, test2_copy, 9);
	printf("ft_memmove result: %s\n", test2);
	printf("memmove result:    %s\n", test2_copy);

	// Test 3 - Overlapping, src ahead of dest
	printf("\nTest 3 - Overlapping, src ahead of dest:\n");
	strcpy(test3_copy, test3); // Reset the copy for the standard memmove
	ft_memmove(test3, test3 + 4, 12);
	memmove(test3_copy, test3_copy + 4, 12);
	printf("ft_memmove result: %s\n", test3);
	printf("memmove result:    %s\n", test3_copy);

	return 0;
}*/
