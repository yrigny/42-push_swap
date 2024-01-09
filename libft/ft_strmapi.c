/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrigny <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 11:12:24 by yrigny            #+#    #+#             */
/*   Updated: 2023/11/14 11:50:39 by yrigny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
char	mapi(unsigned int i, char c)
{
	char	res;

	if (i == 0 && c > 96 && c < 123)
		res = c - 32;
	else if (i != 0 && c > 64 && c < 91)
		res = c + 32;
	else
		res = c;
	return (res);
}
*/
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*dest;

	if (s == NULL)
		return (NULL);
	i = 0;
	while (s[i])
		i++;
	dest = malloc(i + 1);
	if (!dest)
		return (NULL);
	dest[i] = '\0';
	while (i--)
		dest[i] = (*f)(i, s[i]);
	return (dest);
}
/*
int	main()
{
	char	*s = "hEllO, WoRld";
	char (*f)(unsigned int, char) = &mapi;

	printf("%s\n", ft_strmapi(s, f));
	return (0);
}*/
