#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t a)
{
	size_t	i;

	i = -1;
	while(++i < a)
		if((unsigned char *)s1)[i] != ((unsigned char *)s2)[i])
			return ((unsigned char *)s1)[i] - ((unsigned char *)s2)[i]);
	return (0);
}
