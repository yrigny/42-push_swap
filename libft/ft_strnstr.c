/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrigny <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 14:15:56 by yrigny            #+#    #+#             */
/*   Updated: 2023/11/10 15:22:32 by yrigny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	if (!*little)
		return ((char *)big);
	i = 0;
	while (big[i] && i < len)
	{
		j = 0;
		while (little[j] && big[i + j] == little[j] && i + j < len)
			j++;
		if (!little[j])
			return ((char *)&big[i]);
		i++;
	}
	return (NULL);
}
/*
int	main(void)
{
	const char *testString = "This is a simple test string";
	const char *subStrings[] = {"simple", "test", "is", "not found", ""};
	size_t	lengths[] = {10, 20, 30, 40, 0};
	char	*result;
	char	*expected;

	for (int i = 0; i < 5; i++)
	{
		printf("Searching for '%s' in '%s' (length %zu):\n",
				subStrings[i], testString, lengths[i]);
		result = ft_strnstr(testString, subStrings[i], lengths[i]);
		expected = strnstr(testString, subStrings[i], lengths[i]);
		printf("ft_strnstr result: %s\n", result);
		printf("strnstr result:    %s\n", expected);
	}
    	return 0;
}*/
