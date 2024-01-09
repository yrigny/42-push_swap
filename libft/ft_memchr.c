/* ************************************************************************** */
/*									      */
/*							  :::	   ::::::::   */
/*   ft_memchr.c					:+:	 :+:	:+:   */
/*						      +:+ +:+	      +:+     */
/*   By: yrigny <marvin@42.fr>			    +#+  +:+	   +#+	      */
/*						  +#+#+#+#+#+	+#+	      */
/*   Created: 2023/11/09 16:56:58 by yrigny	       #+#    #+#	      */
/*   Updated: 2023/11/09 16:57:00 by yrigny	      ###   ########.fr       */
/*									      */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*ptr;

	ptr = (unsigned char *)s;
	while (n-- > 0)
	{
		if (*ptr == (unsigned char)c)
			return (ptr);
		ptr++;
	}
	return (NULL);
}
/*
int	main(void)
{
	const char s1[25] = "what are you looking for?";
	const char s2[25] = "";
	int c1 = 'r';
	int c2 = '\0';
	int c3 = -42;

	printf("look for '%c' in \"%s\", 10 bytes\n", c1, s1);
	printf("ft result: %p\n", (void*)ft_memchr(s1, c1, 10));
	printf("og result: %p\n", (void*)memchr(s1, c1, 10));
	printf("look for '%c' in \"%s\", 25 bytes\n", c2, s1);
	printf("ft result: %p\n", (void*)ft_memchr(s1, c2, 25));
	printf("og result: %p\n", (void*)memchr(s1, c2, 25));
	printf("look for '%c' in \"%s\", 25 bytes\n", c3, s1);
	printf("ft result: %p\n", (void*)ft_memchr(s1, c3, 25));
	printf("og result: %p\n", (void*)memchr(s1, c3, 25));
	printf("look for '%c' in \"%s\", 25 bytes\n", c1, s2);
	printf("ft result: %p\n", (void*)ft_memchr(s2, c1, 25));
	printf("og result: %p\n", (void*)memchr(s2, c1, 25));
	return (0);
}*/
