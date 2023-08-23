#include "get_next_line.h"

int		get_next_line(int fd, char **line)
{
	int	bytes;
	static char	*store[OPEN_MAX];

	if (fd < 0 || fd > OPEN_MAX || !line || BUFFER_SIZE <= 0)
		return (-1);

	if (store[fd] == NULL)
		store[fd] = ft_strdup("");
	bytes = 1;

	while (bytes > 0 && !ft_strchr(store[fd], '\n'))
	{
		bytes = read_buffer(fd, &store[fd]);
	}

	if (ft_strchr(store[fd], '\n'))
	{
		split_store(&store[fd], line);
	}
	
	if (bytes == 0 && !ft_strchr(store[fd], '\n'))
	{
		*line = ft_strdup(store[fd]);
		free(store[fd]);
		store[fd] = NULL;
	}
	
	return (bytes);
}

int	read_buffer(int fd, char **store)
{
	int	bytes;
	char	*tmp;
	char	*buffer;

	if (BUFFER_SIZE <= 0)
		return (-1);

	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (buffer == NULL)
		return (-1);

	bytes = read(fd, buffer, BUFFER_SIZE);
	if (bytes < 0)
	{
		free(buffer);
		return (-1);
	}

	buffer[bytes] = '\0';
	tmp = ft_strjoin(*store, buffer);
	free(*store);
	*store = tmp;
	free(buffer);

	if (bytes > 1)
		return (1);
	else
		return (0);
}


void	split_store(char **store, char **line)
{
	size_t	len;
	char	*tmp;

	len = ft_strchr(*store, '\n') - *store;
	*line = ft_substr(*store, 0, len);
	tmp = ft_substr(*store, len + 1, ft_strlen(*store) - len);
	free(*store);
	*store = tmp;
}

#include <stdio.h>

int main()
{
    int fd;
    char *line;

    fd = open("test_get_next_line.txt", O_RDONLY);

    if (fd < 0)
    {
        perror("Error opening file");
        return 1;
    }

    int ret;
    while ((ret = get_next_line(fd, &line)) > 0)
    {
        printf("Line: %s\n", line);
        free(line);
    }

    if (ret == 0)
    {
        printf("End of file\n");
    }
    else if (ret < 0)
    {
        perror("Error reading line");
    }

    close(fd);

    return 0;
}

