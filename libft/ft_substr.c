#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*buffer;

	if (!s || !(buffer = (char *)malloc(len + 1)))
		return (NULL);
	if ((size_t)start >= ft_strlen(s) || !(ft_strlcpy(buffer, s + start, len + 1)))
		buffer[0] = '\0';
	return (buffer);
}
