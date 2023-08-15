#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t a)
{
	while(*s1 && *s2 && a && (*s1 == *s2))
	{
		++s1;
		++s2;
		--a;
	}
	if(a == 0)
		return(0);
	return(*(unsigned char *)s1 - *(unsigned char *)s2);
}
