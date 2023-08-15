#include "libft.h"

char	*ft_strchr(const char *s, int a)
{
	while(*s && *s != (char)a)
		++s;
	if(*s == (char)a)
		return ((char *)s);
	return (NULL);
}
