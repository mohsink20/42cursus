
#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	int i;

	i = 0;
	while (str[i])
		++i;
	return (i);
}

char	*ft_strchr(const char *str, int c)
{
	while(*str && *str != (char)c)
		++str;
	if(*str == (char)c)
		return ((char *)str);
	return (NULL);
}


char	*ft_strjoin(char *s1, char *s2)
{
	int			i;
	int			ij;
	char		*j;

	if (!s1 || !s2 || !(j = malloc(sizeof(char) *
					(ft_strlen((char *)s1) + ft_strlen((char *)s2) + 1))))
		return (NULL);
	i = 0;
	ij = 0;
	while (s1[i])
		j[ij++] = s1[i++];
	i = 0;
	while (s2[i])
		j[ij++] = s2[i++];
	j[ij] = '\0';
	return (j);
}

char	*ft_strdup(const char *str)
{
	int		i;
	char	*dest;

	if (!(dest = (char *)malloc(sizeof(char) * (ft_strlen(str) + 1))))
		return (NULL);
	i = 0;
	while (str[i])
	{
		dest[i] = str[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	unsigned int	i;
	size_t			slen;
	char			*new_s;

	if (!s || !(new_s = malloc(sizeof(char) * (len + 1))))
		return (NULL);
	slen = ft_strlen((char *)s);
	i = 0;
	while (start < slen && s[start + i] && i < len)
	{
		new_s[i] = s[start + i];
		i++;
	}
	new_s[i] = '\0';
	return (new_s);
}
