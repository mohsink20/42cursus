/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mokhan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 17:41:03 by mokhan            #+#    #+#             */
/*   Updated: 2023/09/07 17:44:07 by mokhan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t a)
{
	size_t	i;

	i = 0;
	if (dest != src && a)
	{
		while (i < a)
		{
			((unsigned char *)dest)[i] = ((unsigned char *)src)[i];
			++i;
		}
	}
	return (dest);
}
