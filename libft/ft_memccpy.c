#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int a, size_t b)
{
	size_t	i;

	i = -1;
	while (++i < b)
	{
		((unsigned char *)dest)[i] = ((unsigned char *)src)[i];
		if(((unsigned char *)src)[i] == (unsigned char)a)
			return (dest + i + 1);
	}
	return (NULL);
}
