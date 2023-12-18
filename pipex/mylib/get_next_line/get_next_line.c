/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mokhan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 11:42:03 by mokhan            #+#    #+#             */
/*   Updated: 2023/09/22 11:42:05 by mokhan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*read_line(int fd, char *buf, char *backup)
{
	int		check;
	char	*temp;

	check = 1;
	while (check)
	{
		check = read(fd, buf, BUFFER_SIZE);
		if (check == -1)
			return (0);
		else if (check == 0)
			break ;
		buf[check] = '\0';
		if (!backup)
			backup = gnl_strdup("");
		temp = backup;
		backup = (gnl_strjoin(temp, buf));
		if (!backup)
			return (NULL);
		free (temp);
		temp = NULL;
		if (gnl_strchr(buf, '\n'))
			break ;
	}
	return (backup);
}

static char	*extract(char *line)
{
	int		i;
	char	*temp;

	i = 0;
	while (line[i] != '\0' && line[i] != '\n')
		i++;
	if (line[i] == '\0')
		return (NULL);
	temp = gnl_substr(line, i + 1, gnl_strlen(line) - i);
	if (!temp)
		return (NULL);
	if (temp[0] == '\0')
	{
		free (temp);
		temp = NULL;
		return (NULL);
	}
	line[i + 1] = '\0';
	return (temp);
}

char	*get_next_line(int fd)
{
	char		*buf;
	char		*line;
	static char	*backup;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buf = malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!buf)
		return (NULL);
	line = read_line(fd, buf, backup);
	free(buf);
	if (!line)
		return (NULL);
	backup = extract(line);
	return (line);
}
/*
#include <fcntl.h>
#include <stdio.h>

int	main(void)
{
	int	fd;
	char	*line;

	fd = open("test_get_next_line.txt", O_RDONLY);

	if (fd == -1)
	{
		perror("Error opening file");
		return (1);
	}
	while ((line = get_next_line(fd)) != NULL)
	{
		printf("%s\n", line);
		free(line);
	}
	close(fd);
	return 0;
}
*/
