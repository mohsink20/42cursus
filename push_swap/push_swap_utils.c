/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mokhan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 19:13:37 by mokhan            #+#    #+#             */
/*   Updated: 2023/12/20 19:21:38 by mokhan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_error(void)
{
	printf("Error\n");
	exit(EXIT_FAILURE);
}

void	ft_free(void **ptr)
{
	int	i;

	i = 0;
	while (ptr[i])
	{
		free(ptr[i]);
		ptr[i] = NULL;
		i++;
	}
	free(ptr);
	ptr = NULL;
}

int	ps_strcmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (ft_strlen(s1) != ft_strlen(s2))
		return (-1);
	while ((!s1 && !s2) || i < n)
	{
		if ((unsigned char)s1[i] != (unsigned char)s2[i] || s1[i] == '\0')
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	return (0);
}

long	atoi_long(const char *nptr)
{
	long	i;
	long	neg;
	long	res;

	i = 0;
	neg = 0;
	res = 0;
	while ((nptr[i] > 8 && nptr[i] < 14) || nptr[i] == 32)
		i++;
	if (nptr[i] == 45 || nptr[i] == 43)
	{
		if (nptr[i] == 45)
			neg++;
		i++;
	}
	while (nptr[i] > 47 && nptr[i] < 58)
	{
		res = (nptr[i] - '0') + (res * 10);
		i++;
	}
	if (neg == 1)
		res = -res;
	return (res);
}
