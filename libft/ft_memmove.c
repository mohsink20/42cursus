#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t a)
{
	size_t	i;

	i = dest > src ? a + 1 : -1;
	if (dest != src && a)
	{
		if (dest > src)
			while(--i)
				((unsigned char *)dest)[i - 1] = ((unsigned char *)src)[i - 1]
		else
			while (++i < a)
				((unsigned char *)dest)[i] = ((unsigned char *)src)[i]
	}
	return (dest);
}
