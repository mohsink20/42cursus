#include "libft.h"

size_t	ft_strlen(const char *str)
{
	int i;

	i = 0;
	while (str[i])
		++i;
	return (i);
}
/*
int	main()
{
	char *c = "Hello World!";
	printf("%ld", ft_strlen(c));
}
*/
