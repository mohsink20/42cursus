#include "libft.h"

char	*ft_strrchr(const char *s, int a)
{
	size_t	i;

	i = ft_strlen(s) + 1;
	while (i--)
		if (s[i] == a)
			return ((char *)s + i);
	return (NULL);
}
