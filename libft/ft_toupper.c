#include "libft.h"

int	ft_toupper(int a)
{
	if(ft_isalpha(a) == 2)
		return(a - 32);
	return (a);
}
