#include "libft.h"

void	*ft_calloc(size_t a, size_t b)
{
	void	*buffer;

	if (!(buffer = (void *)malloc(a * b)))
		return (NULL);
	ft_bzero(buffer, a * b);
	return (buffer);
}
