/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mokhan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 18:10:45 by mokhan            #+#    #+#             */
/*   Updated: 2023/09/07 18:10:47 by mokhan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*buffer;

	buffer = (char *)malloc(len + 1);
	if (!s || !buffer)
		return (NULL);
	if ((size_t)start >= ft_strlen(s)
		|| !(ft_strlcpy(buffer, s + start, len + 1)))
		buffer[0] = '\0';
	return (buffer);
}
