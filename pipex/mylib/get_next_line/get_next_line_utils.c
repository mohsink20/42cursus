/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mokhan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 11:42:25 by mokhan            #+#    #+#             */
/*   Updated: 2023/09/22 11:42:26 by mokhan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	gnl_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*gnl_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	j;
	char	*temp;

	i = 0;
	j = 0;
	if (!s)
		return (NULL);
	temp = malloc(len + 1);
	if (!temp)
		return (NULL);
	while (s[i])
	{
		if (i >= start && j < len)
			temp[j++] = s[i];
		i++;
	}
	temp[j] = '\0';
	return (temp);
}

char	*gnl_strdup(const char *s1)
{
	char	*temp;
	int		len;
	int		i;

	len = 0;
	i = 0;
	while (s1[i])
	{
		len++;
		i++;
	}
	temp = (char *)malloc(sizeof(char) * len + 1);
	if (!temp)
		return (0);
	i = 0;
	while (i < len)
	{
		temp[i] = s1[i];
		i++;
	}
	temp[i] = 0;
	return (temp);
}

char	*gnl_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		j;
	char	*temp;

	i = 0;
	j = 0;
	if (!s1 || !s2)
		return (NULL);
	temp = (char *)malloc(sizeof(char) * (gnl_strlen(s1) + gnl_strlen(s2) + 1));
	if (!temp)
		return (NULL);
	while (s1[j])
		temp[i++] = s1[j++];
	j = 0;
	while (s2[j])
		temp[i++] = s2[j++];
	temp[i] = '\0';
	return (temp);
}

char	*gnl_strchr(const char *s, int c)
{
	int				i;
	unsigned char	temp;

	i = 0;
	temp = (unsigned char) c;
	while (s[i])
	{
		if (s[i] == temp)
			return ((char *)s + i);
		i++;
	}
	if (s[i] == temp)
		return ((char *)s + i);
	return (NULL);
}
