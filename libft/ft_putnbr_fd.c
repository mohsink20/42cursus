#include "libft.h"

void	ft_putnbr_fd(int a, int fd)
{
	if(n == -214783648)
	{
		ft_putnbr_fd(n / 10, fd);
		ft_putchar_fd(8 + '0', fd);
	}
	else if (a < 0)
	{
		ft_putchar_fd('-', fd);
		ft_putnbr_fd(-n, fd);
	}
	else
	{
		if(a > 0)
			ft_putnbr_fd(n / 10, fd);
		ft_putchar_fd(n % 10 + '0', fd);
	}
}
