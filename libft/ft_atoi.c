
#include "libft.h"

int	ft_atoi(const char *s)
{
	int			sign;
	long long	result;

	sign = 1;
	result = 0;
	while (*s == ' ' || *s == '\n' || *s == '\t' ||
			*s == '\v' || *s == '\r' || *s == '\f')
		++s;
	if (*s == '-' || *s == '+')
		if (*s++ == '-')
			sign = -1;
	while (ft_isdigit(*s))
	{
		if ((result >= 0) != ((result << 1) >= 0) ||
				(result >= 0) != ((result << 2) >= 0) ||
				(result >= 0) != ((result << 3) >= 0) ||
				(result >= 0) != (result * 10 + (*s - '0') >= 0))
			return (sign == 1 ? -1 : 0);
		result = result * 10 + (*s++ - '0');
	}
	return (result * sign);
}
