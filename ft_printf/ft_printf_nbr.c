/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_nbr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mokhan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 20:31:26 by mokhan            #+#    #+#             */
/*   Updated: 2023/10/06 13:38:30 by mokhan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	print_nbr_right(char *nbr, int *flags, int neg)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (i < flags[7])
		i += write(1, " ", 1);
	if (neg)
		flags[1] = write(1, "-", 1);
	if (flags[1] && !neg)
		write(1, "+", 1);
	else if (flags[0] && !neg)
		flags[1] = write(1, " ", 1);
	while (j < flags[6])
		j += write(1, "0", 1);
	if (flags[5] < 2)
		ft_putstr_fd(nbr, 1);
	free(nbr);
	return (i + j + flags[1]);
}

static int	print_nbr_left(char *nbr, int *flags, int neg)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (neg)
		flags[1] = write(1, "-", 1);
	if (flags[1] && !neg)
		write(1, "+", 1);
	else if (flags[0] && !neg)
		flags[1] = write(1, " ", 1);
	while (j < flags[6])
		j += write(1, "0", 1);
	if (flags[5] < 2)
		ft_putstr_fd(nbr, 1);
	free(nbr);
	while (i < flags[7])
		i += write(1, " ", 1);
	return (i + j + flags[1]);
}

int	print_nbr(int n, int *flags)
{
	int		len;
	bool	neg;
	char	*nbr;

	nbr = ft_itoapositive(n);
	len = ft_intlen(n, 10);
	neg = n < 0;
	if (flags[5] && !flags[6] && !n)
		flags[5] += len--;
	if (flags[4] && !flags[5])
	{
		flags[6] = flags[7];
		flags[7] = 0;
	}
	if (flags[6] > len)
		flags[7] -= flags[6] + flags[1] + flags[0] + neg;
	else
		flags[7] -= len + flags[1] + flags[0] + neg;
	if (flags[5])
		flags[6] -= flags[1] + flags[0] + len;
	else
		flags[6] -= flags[1] + flags[0] + len + neg;
	if (flags[3])
		return (len + print_nbr_left(nbr, flags, neg));
	return (len + print_nbr_right(nbr, flags, neg));
}
