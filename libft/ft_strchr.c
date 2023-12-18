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
