/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mokhan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 18:08:50 by mokhan            #+#    #+#             */
/*   Updated: 2023/09/07 18:08:51 by mokhan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	i;
	char	*buffer;

	buffer = (char *)malloc(ft_strlen(s) + 1);
	if (!s || !f || !buffer)
		return (NULL);
	i = 0;
	while (s[i])
	{
		buffer[i] = f(i, s[i]);
		++i;
	}
	buffer[i] = '\0';
	return (buffer);
}
