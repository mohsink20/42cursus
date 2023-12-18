/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mokhan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 17:37:58 by mokhan            #+#    #+#             */
/*   Updated: 2023/09/07 17:37:59 by mokhan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int a, size_t b)
{
	size_t	i;

	i = -1;
	while (++i < b)
		if (((unsigned char *)s)[i] == (unsigned char)a)
			return ((void *)s + i);
	return (NULL);
}
