#include "libft.h"

char	*ft_strdup(const char *s)
{
	size_t	len;
	char	*buffer;

	len = ft_strlen(s);
	if (!(buffer = (char *)malloc(len + 1)))
		return (NULL);
	ft_strlcpy(buffer, s, len + 1);
	return (buffer);
}
