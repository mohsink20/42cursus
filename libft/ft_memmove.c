/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mokhan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 17:41:36 by mokhan            #+#    #+#             */
/*   Updated: 2023/09/07 17:41:38 by mokhan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t a)
{
	size_t	i;

	if (dest != src && a)
	{
		if (dest > src)
		{
			i = a;
			while (i > 0)
			{
				i--;
				((unsigned char *)dest)[i] = ((unsigned char *)src)[i];
			}
		}
		else
		{
			i = 0;
			while (i < a)
			{
				((unsigned char *)dest)[i] = ((unsigned char *)src)[i];
				i++;
			}
		}
	}
	return (dest);
}
