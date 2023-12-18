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
/* Older version. Had few issues
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
*/

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*buffer;
	size_t	s_len;

	if (!s)
		return (NULL);
	s_len = ft_strlen(s);
	if (start >= s_len)
		return (ft_strdup(""));
	if (len > s_len - start)
		len = s_len - start;
	buffer = (char *)malloc(len + 1);
	if (!buffer)
		return (NULL);
	ft_strlcpy(buffer, s + start, len + 1);
	return (buffer);
}
