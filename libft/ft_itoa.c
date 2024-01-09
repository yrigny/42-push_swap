/* ************************************************************************** */
/*									      */
/*							  :::	   ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*						      +:+ +:+	      +:+     */
/*   By: yrigny <marvin@42.fr>			    +#+  +:+	   +#+	      */
/*						  +#+#+#+#+#+	+#+	      */
/*   Created: 2023/11/13 15:07:18 by yrigny	       #+#    #+#	      */
/*   Updated: 2023/11/13 18:14:44 by yrigny           ###   ########.fr       */
/*									      */
/* ************************************************************************** */

#include "libft.h"

void	countdigit(int n, int *digit)
{
	*digit = 1;
	while (n >= 10 || n <= -10)
	{
		*digit += 1;
		n /= 10;
	}
	if (n < 0)
		*digit += 1;
}

char	*ft_itoa(int n)
{
	int		digit;
	char	*dest;

	countdigit(n, &digit);
	dest = malloc(digit + 1);
	if (!dest)
		return (NULL);
	dest[digit] = '\0';
	while (digit > 0)
	{
		if (n < 0)
			dest[--digit] = -(n % 10) + '0';
		if (n >= 0)
			dest[--digit] = n % 10 + '0';
		if (n < 10 && n > -10)
			break ;
		n /= 10;
	}
	if (n < 0)
		dest[--digit] = '-';
	return (dest);
}
/*
int	main()
{
	int	n[] = {0, -5, -2147483648, 42, 1024};

	for (int i = 0; i < 5; i++)
		printf("%s\n", ft_itoa(n[i]));
	return (0);
}*/
