/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mokhan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 17:32:52 by mokhan            #+#    #+#             */
/*   Updated: 2023/09/07 17:32:55 by mokhan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t a, size_t b)
{
	void	*buffer;

	buffer = (void *)malloc(a * b);
	if (!buffer)
		return (NULL);
	ft_bzero(buffer, a * b);
	return (buffer);
}
