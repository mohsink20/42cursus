/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mokhan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 20:29:03 by mokhan            #+#    #+#             */
/*   Updated: 2023/10/06 13:39:04 by mokhan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_intlen(long long n, int base)
{
	int	len;

	len = !n;
	while (n)
	{
		n /= base;
		len++;
	}
	return (len);
}

char	*ft_itoapositive(long long n)
{
	char		*c;
	bool		sign;
	long long	len;

	sign = n < 0;
	len = ft_intlen(n, 10);
	c = (char *)malloc(sizeof(char) * (len + 1));
	if (!c)
		return (NULL);
	c[len] = '\0';
	if (sign)
	{
		c[--len] = -(n % 10) + '0';
		n = -(n / 10);
	}
	while (len--)
	{
		c[len] = n % 10 + '0';
		n = n / 10;
	}
	return (c);
}
