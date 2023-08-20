#include "libft.h"

int	ft_tolower(int a)
{
	if(ft_isalpha(a) == 1)
		return (a + 32);
	return (a);
}
