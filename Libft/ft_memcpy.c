#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t a)
{
	size_t	i;

	i = 0;
	if(dest != src && a)
	{
		while (i < a)
		{
			((unsigned char *)dest)[i] = ((unsigned char *)src)[i];
			++i;
		}
	}
	return dst;
}

