/* ************************************************************************** */
/*									      */
/*							  :::	   ::::::::   */
/*   ft_strchr.c					:+:	 :+:	:+:   */
/*						      +:+ +:+	      +:+     */
/*   By: yrigny <marvin@42.fr>			    +#+  +:+	   +#+	      */
/*						  +#+#+#+#+#+	+#+	      */
/*   Created: 2023/11/09 14:58:01 by yrigny	       #+#    #+#	      */
/*   Updated: 2023/11/09 16:03:16 by yrigny	      ###   ########.fr       */
/*									      */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	while (*s)
	{
		if (*s == (const char)c)
			return ((char *)s);
		s++;
	}
	if (*s == (const char)c)
		return ((char *)s);
	return (NULL);
}
/*
int	main(void)
{
	const char *s1 = "what are you looking for?";
	const char *s2 = "";
	int c1 = 'r';
	int c2 = '\0';
	int c3 = -42;

	printf("look for '%c' in \"%s\"\n", c1, s1);
	printf("ft result: %s\n", ft_strchr(s1, c1));
	printf("og result: %s\n", strchr(s1, c1));
	printf("look for '%c' in \"%s\"\n", c2, s1);
	printf("ft result: %p\n", (void*)ft_strchr(s1, c2));
	printf("og result: %p\n", (void*)strchr(s1, c2));
	printf("look for '%c' in \"%s\"\n", c3, s1);
	printf("ft result: %p\n", (void*)ft_strchr(s1, c3));
	printf("og result: %p\n", (void*)strchr(s1, c3));
	printf("look for '%c' in \"%s\"\n", c1, s2);
	printf("ft result: %p\n", (void*)ft_strchr(s2, c1));
	printf("og result: %p\n", (void*)strchr(s2, c1));
	return (0);
}*/
