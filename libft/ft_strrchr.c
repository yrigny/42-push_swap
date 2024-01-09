/* ************************************************************************** */
/*									      */
/*							  :::	   ::::::::   */
/*   ft_strrchr.c					:+:	 :+:	:+:   */
/*						      +:+ +:+	      +:+     */
/*   By: yrigny <marvin@42.fr>			    +#+  +:+	   +#+	      */
/*						  +#+#+#+#+#+	+#+	      */
/*   Created: 2023/11/09 16:06:08 by yrigny	       #+#    #+#	      */
/*   Updated: 2023/11/09 16:06:11 by yrigny	      ###   ########.fr       */
/*									      */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	signed int	len;

	len = 0;
	while (s[len])
		len++;
	s += len;
	while (len-- >= 0)
	{
		if (*s == (const char)c)
			return ((char *)s);
		s--;
	}
	return (NULL);
}
/*
int	main(void)
{
	const char *s1 = "what are you looking for?";
	const char *s2 = "";
	int c1 = 'o';
	int c2 = '\0';
	int c3 = -42;

	printf("look for '%c' in \"%s\"\n", c1, s1);
	printf("ft result: %s\n", ft_strrchr(s1, c1));
	printf("og result: %s\n", strrchr(s1, c1));
	printf("look for '%c' in \"%s\"\n", c2, s1);
	printf("ft result: %p\n", (void*)ft_strrchr(s1, c2));
	printf("og result: %p\n", (void*)strrchr(s1, c2));
	printf("look for '%c' in \"%s\"\n", c3, s1);
	printf("ft result: %p\n", (void*)ft_strrchr(s1, c3));
	printf("og result: %p\n", (void*)strrchr(s1, c3));
	printf("look for '%c' in \"%s\"\n", c1, s2);
	printf("ft result: %p\n", (void*)ft_strrchr(s2, c1));
	printf("og result: %p\n", (void*)strrchr(s2, c1));
	return (0);
}*/
