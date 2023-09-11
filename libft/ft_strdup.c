/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mokhan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 18:07:43 by mokhan            #+#    #+#             */
/*   Updated: 2023/09/07 18:07:44 by mokhan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	size_t	len;
	char	*buffer;

	len = ft_strlen(s);
	buffer = (char *)malloc(len + 1);
	if (!buffer)
		return (NULL);
	ft_strlcpy(buffer, s, len + 1);
	return (buffer);
}
