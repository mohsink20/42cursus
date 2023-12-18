/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mokhan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 18:08:13 by mokhan            #+#    #+#             */
/*   Updated: 2023/09/07 18:08:18 by mokhan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t dsize)
{
	size_t	i;

	i = 0;
	while (*dest && i < dsize)
	{
		++i;
		++dest;
	}
	while (*src && i + 1 < dsize)
	{
		*dest = *src;
		++dest;
		++src;
		++i;
	}
	if (i < dsize)
		*dest = 0;
	while (*src)
	{
		++i;
		++src;
	}
	return (i);
}
/*
int main(void)
{
    char dest[20] = "Hello, ";
    char src[] = "Worrrrlddd!";
    size_t size = sizeof(dest);

    size_t result = ft_strlcat(dest, src, size);
    printf("Concatenated string: %s\n", dest);
    printf("Length of concatenated string: %zu\n", result);

    return 0;
}
*/
