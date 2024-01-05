/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_hex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mokhan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 20:30:41 by mokhan            #+#    #+#             */
/*   Updated: 2023/10/06 13:38:18 by mokhan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_puthex_fd(unsigned int num, const char c, int fd)
{
	if (num >= 16)
	{
		ft_puthex_fd(num / 16, c, fd);
		ft_puthex_fd(num % 16, c, fd);
	}
	else
	{
		if (num <= 9)
			ft_putchar_fd(num + '0', fd);
		else
			ft_putchar_fd(num - 33 + c, fd);
	}
}

static int	print_nbr_right(unsigned int nbr, int *flags, const char c)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (i < flags[7])
		i += write(1, " ", 1);
	if (flags[2])
	{
		flags[2] = write(1, "0", 1);
		flags[2] += write(1, &c, 1);
	}
	while (j < flags[6])
		j += write(1, "0", 1);
	if (flags[5] < 2)
		ft_puthex_fd(nbr, c, 1);
	return (i + j + flags[2]);
}

static int	print_nbr_left(unsigned int nbr, int *flags, const char c)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (flags[2])
	{
		flags[2] = write(1, "0", 1);
		flags[2] += write(1, &c, 1);
	}
	while (j < flags[6])
		j += write(1, "0", 1);
	if (flags[5] < 2)
		ft_puthex_fd(nbr, c, 1);
	while (i < flags[7])
		i += write(1, " ", 1);
	return (i + j + flags[2]);
}

int	print_hex(unsigned int nbr, int *flags, const char c)
{
	int	len;

	len = ft_numlen(nbr, 16);
	if (!nbr)
		flags[2] = 0;
	if (flags[5] && !flags[6] && !nbr)
		flags[5] += len--;
	if (flags[4] && !flags[5])
	{
		flags[6] = flags[7];
		flags[7] = 0;
	}
	if (flags[6] > len)
		flags[7] -= flags[6];
	else
		flags[7] -= len ;
	if (flags[5])
		flags[6] -= len;
	else
		flags[6] -= len ;
	if (flags[3])
		return (len + print_nbr_left(nbr, flags, c));
	return (len + print_nbr_right(nbr, flags, c));
}
