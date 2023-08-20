#include "libft.h"

int	ft_isalpha(int a)
{
	if (a >= 'A' && a <= 'Z')
		return (1);
	else if (a >= 'a' && a <= 'z')
		return (2);
	return (0);
}
