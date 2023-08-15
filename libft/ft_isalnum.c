#include "libft.h"

int	ft_isalnum(int a)
{
	return(ft_isalpha(a) || ft_isdigit(a));
}
