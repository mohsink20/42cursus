/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mokhan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 18:06:54 by mokhan            #+#    #+#             */
/*   Updated: 2023/09/07 18:06:55 by mokhan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *set, size_t a)
{
	size_t	len;

	len = ft_strlen(set);
	if (!*set)
		return ((char *)s1);
	while (*s1 && a-- >= len)
	{
		if (*s1 == *set && !ft_memcmp(s1, set, len))
			return ((char *)s1);
		++s1;
	}
	return (NULL);
}
