/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mokhan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 18:05:52 by mokhan            #+#    #+#             */
/*   Updated: 2023/09/07 18:05:54 by mokhan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>

typedef struct s_list
{
	void				*content;
	struct s_list		*next;
}					t_list;

int					ft_atoi(const char *s);
void				ft_bzero(void *s, size_t a);
void				*ft_calloc(size_t a, size_t b);
int					ft_isalnum(int a);
int					ft_isalpha(int a);
int					ft_isascii(int a);
int					ft_isdigit(int a);
int					ft_isprint(int a);
char				*ft_itoa(int n);
void				*ft_memchr(const void *s, int a, size_t b);
int					ft_memcmp(const void *s1, const void *s2, size_t a);
void				*ft_memcpy(void *dest, const void *src, size_t a);
void				*ft_memmove(void *dest, const void *src, size_t a);
void				*ft_memset(void *s, int a, size_t b);
void				ft_putchar_fd(char c, int fd);
void				ft_putendl_fd(char *s, int fd);
void				ft_putnbr_fd(int n, int fd);
void				ft_putstr_fd(char *s, int fd);
char				**ft_split(char const *s, char c);
char				*ft_strchr(const char *s, int a);
char				*ft_strdup(const char *s);
char				*ft_strjoin(char const *s1, char const *s2);
size_t				ft_strlcat(char *dest, const char *src, size_t dsize);
size_t				ft_strlcpy(char *dest, const char *src, size_t dsize);
size_t				ft_strlen(const char *str);
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int					ft_strncmp(const char *s1, const char *s, size_t n);
char				*ft_strnstr(const char *s1, const char *set, size_t a);
char				*ft_strrchr(const char *s, int a);
char				*ft_strtrim(char const *s1, char const *set);
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
char				*ft_substr(char const *s, unsigned int start, size_t len);
int					ft_tolower(int a);
int					ft_toupper(int a);

//Bonus

int					ft_lstsize(t_list *lst);
void				ft_lstadd_back(t_list **lst, t_list *new);
void				ft_lstadd_front(t_list **lst, t_list *new);
void				ft_lstclear(t_list **lst, void (*del)(void *));
void				ft_lstdelone(t_list *lst, void (*del)(void *));
void				ft_lstiter(t_list *lst, void (*f)(void *));
t_list				*ft_lstlast(t_list *lst);
t_list				*ft_lstmap(t_list *lst, void *(*f)(void *),
						void (*del)(void *));
t_list				*ft_lstnew(void *content);

#endif
