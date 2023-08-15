#include "libft.h"

void	*ft_memchr(const void *s, int a, size_t b)
{
	size_t	i;

	i = -1;
	while (++i < b)
		if(((unsigned char *)s)[i] == (unsigned char)a)
			return ((void *)s + i);
	return (NULL);
}
