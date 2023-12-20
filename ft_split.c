#include "push_swap.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub;
	size_t	i;
	size_t	sublen;

	if (!s)
		return (NULL);
	i = 0;
	while (s[i])
		i++;
	sublen = len;
	if (start + len > i)
		sublen = i - start;
	if (start >= i)
		sublen = 0;
	sub = (char *)malloc(sizeof(char) * (sublen + 1));
	if (!sub)
		return (NULL);
	i = 0;
	while (i < sublen && s[start + i])
	{
		sub[i] = s[start + i];
		i++;
	}
	sub[i] = '\0';
	return (sub);
}

int	countwords(char const *s, char c)
{
	int	count;

	count = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s)
			count += 1;
		while (*s && *s != c)
			s++;
	}
	return (count);
}

char	**copywords(int wordcount, char **dest, char const *s, char c)
{
	int	i;
	int	j;
	int	start;

	i = 0;
	j = 0;
	while (s[j] && i < wordcount)
	{
		while (s[j] == c)
			j++;
		start = j;
		while (s[j] && s[j] != c)
			j++;
		dest[i] = ft_substr(s, start, j - start);
		if (!dest[i])
		{
			while (i-- >= 0)
				free(dest[i]);
			free(dest);
			return (NULL);
		}
		i++;
	}
	dest[i] = 0;
	return (dest);
}

char	**ft_split(char const *s, char c)
{
	int		wordcount;
	char	**dest;

	if (s == NULL)
		return (NULL);
	wordcount = countwords(s, c);
	dest = malloc(sizeof(char *) * (wordcount + 1));
	if (!dest)
		return (NULL);
	dest = copywords(wordcount, dest, s, c);
	return (dest);
}
