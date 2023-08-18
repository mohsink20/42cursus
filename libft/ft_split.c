#include "libft.h"

static size_t	ft_wordlen(char const *s, char c)
{
	size_t	count;

	count = 0;
	while (*s)
	{
		if (*s != c)
		{
			++count;
			while (*s && *s != c)
				++s;
		}
		else
			++s;
	}
	return (count);
}

static char		**ft_free_dptr(char **s, int i)
{
	while (--i >= 0 && s[i])
	{
		free(s[i]);
		s[i] = NULL;
	}
	free(s);
	s = NULL;
	return (NULL);
}

char			**ft_split(char const *s, char c)
{
	int		i;
	char	*from;
	char	**buffer;

	i = 0;
	if (!s || !(buffer = (char **)malloc((ft_wordlen(s, c) + 1) * sizeof(char *))))
		return (NULL);
	while (*s)
	{
		if (*s != c)
		{
			from = (char *)s;
			while (*s && *s != c)
				++s;
			if (!(buffer[i++] = ft_substr(from, 0, (s - from))))
				return (ft_free_dptr(buffer, i));
		}
		else
			++s;
	}
	buffer[i] = NULL;
	return (buffer);
}
