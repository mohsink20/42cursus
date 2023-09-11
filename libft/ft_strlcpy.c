/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mokhan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 18:08:28 by mokhan            #+#    #+#             */
/*   Updated: 2023/09/07 18:08:30 by mokhan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t dsize)
{
	size_t		src_len;
	size_t		i;

	src_len = ft_strlen(src);
	i = 0;
	if (dsize == 0)
		return (src_len);
	while (i + 1 < dsize && *(src + i) != '\0')
	{
		*(dest + i) = *(src + i);
		i++;
	}
	*(dest + i) = '\0';
	return (src_len);
}

/*

int main() {
    char dest[100];
    const char *src;
    size_t result;

    src = "Hello";
    result = ft_strlcpy(dest, src, sizeof(dest));
    printf("Test 1: %s, result: %zu\n", dest, result);

    src = "";
    result = ft_strlcpy(dest, src, sizeof(dest));
    printf("Test 2: %s, result: %zu\n", dest, result);

    src = "Testing";
    result = ft_strlcpy(dest, src, sizeof(dest));
    printf("Test 3: %s, result: %zu\n", dest, result);

    src = "Buffer";
    result = ft_strlcpy(dest, src, sizeof(dest));
    printf("Test 4: %s, result: %zu\n", dest, result);

    src = "Overflow";
    result = ft_strlcpy(dest, src, sizeof(dest));
    printf("Test 5: %s, result: %zu\n", dest, result);

    src = NULL;
    result = ft_strlcpy(dest, src, 0);
    printf("Test 6: result: %zu\n", result);

    src = "Test";
    result = ft_strlcpy(dest, src, 0);
    printf("Test 7: result: %zu\n", result);

    src = "This is a long source string with spaces and special characters: !@#$%^&*()";
    result = ft_strlcpy(dest, src, sizeof(dest));
    printf("Test 8: %s, result: %zu\n", dest, result);

    src = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789!@#$%^&*()";
    result = ft_strlcpy(dest, src, sizeof(dest));
    printf("Test 9: %s, result: %zu\n", dest, result);

    src = "The quick brown fox jumps over the lazy dog! @#$%^&*()";
    result = ft_strlcpy(dest, src, sizeof(dest));
    printf("Test 10: %s, result: %zu\n", dest, result);

    src = "";
    result = ft_strlcpy(dest, src, sizeof(dest));
    printf("Test 11: %s, result: %zu\n", dest, result);

    src = "Short";
    result = ft_strlcpy(dest, src, sizeof(dest));
    printf("Test 12: %s, result: %zu\n", dest, result);

    return 0;
}
*/
