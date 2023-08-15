#include "libft.h"

void	ft_putchar_fd(char a, int fd)
{
	write(fd, &a, 1);
}
