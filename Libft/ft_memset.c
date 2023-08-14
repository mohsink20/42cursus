#include "libft.h"

void	*ft_memset(void *s, int a, size_t b)
{
	size_t	i;

	i = -1;
	while(++i < b)
		((unsigned char *)s)[i] = (unsigned char)a;
	return(s);
}
