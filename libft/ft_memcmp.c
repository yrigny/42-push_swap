/* ************************************************************************** */
/*									      */
/*							  :::	   ::::::::   */
/*   ft_memcmp.c					:+:	 :+:	:+:   */
/*						      +:+ +:+	      +:+     */
/*   By: yifanr <yifanr@student.42.fr>		    +#+  +:+	   +#+	      */
/*						  +#+#+#+#+#+	+#+	      */
/*   Created: 2023/11/10 00:14:14 by yifanr	       #+#    #+#	      */
/*   Updated: 2023/11/10 00:16:28 by yifanr	      ###   ########.fr       */
/*									      */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	while (n-- > 0)
	{
		if (*(unsigned char *)s1 != *(unsigned char *)s2)
			return (*(unsigned char *)s1 - *(unsigned char *)s2);
		s1++;
		s2++;
	}
	return (0);
}
/*
int main(void)
{
	const char *str1 = "";
	const char *str2 = "abcdefg";
	const char *str3 = "abcd";

	printf("ft_memcmp \"%s\", \"%s\", 0: %d\n", str1, str2,
	ft_memcmp(str1, str2, 0));
	printf("memcmp	  \"%s\", \"%s\", 0: %d\n", str1, str2, memcmp(str1,
	str2, 0));
	printf("ft_memcmp \"%s\", \"%s\", 3: %d\n", str2, str3,
	ft_memcmp(str2, str3, 3));
	printf("memcmp	  \"%s\", \"%s\", 3: %d\n", str2, str3, memcmp(str2,
	str3, 3));
	printf("ft_memcmp \"%s\", \"%s\", 8: %d\n", str2, str3,
	ft_memcmp(str2, str3, 8));
	printf("memcmp	  \"%s\", \"%s\", 8: %d\n", str2, str3, memcmp(str2,
	str3, 8));
}*/
