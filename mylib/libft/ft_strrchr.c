/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mokhan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 18:06:40 by mokhan            #+#    #+#             */
/*   Updated: 2023/09/07 18:06:42 by mokhan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int a)
{
	size_t	i;

	i = ft_strlen(s) + 1;
	while (i--)
		if (s[i] == a)
			return ((char *)s + i);
	return (NULL);
}