#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include <limits.h>

# ifndef OPEN_MAX
# define OPEN_MAX 256
# endif

# ifndef BUFFER_SIZE
# define BUFFER_SIZE 10
# endif

size_t		ft_strlen(const char *str);
char		*ft_strdup(const char *str);
char		*ft_strchr(const char *str, int c);
char		*ft_substr(char const *s, unsigned int start, size_t len);
char		*ft_strjoin(char *s1, char *s2);




int			read_buffer(int fd, char **store);
void		split_store(char **store, char **line);
int			get_next_line(int fd, char **line);

#endif
