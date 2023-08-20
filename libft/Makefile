CFLAGS = -Wall -Wextra -Werror

TARGET = libft.a
SOURCES = SRCS					= ft_atoi.c \
					  ft_bzero.c \
					  ft_calloc.c \
					  ft_isalnum.c \
					  ft_isalpha.c \
					  ft_isascii.c \
					  ft_isdigit.c \
					  ft_isprint.c \
					  ft_itoa.c \
					  ft_memccpy.c \
					  ft_memchr.c \
					  ft_memcmp.c \
					  ft_memcpy.c \
					  ft_memmove.c \
					  ft_memset.c \
					  ft_putchar_fd.c \
					  ft_putendl_fd.c \
					  ft_putnbr_fd.c \
					  ft_putstr_fd.c \
					  ft_split.c \
					  ft_strchr.c \
					  ft_strdup.c \
					  ft_strjoin.c \
					  ft_strlcat.c \
					  ft_strlcpy.c \
					  ft_strlen.c \
					  ft_strmapi.c \
					  ft_strncmp.c \
					  ft_strnstr.c \
					  ft_strrchr.c \
					  ft_strtrim.c \
					  ft_substr.c \
					  ft_tolower.c \
					  ft_toupper.c

BNS_SRCS				= ft_lstsize.c \
					  ft_lstadd_back.c \
					  ft_lstadd_front.c \
					  ft_lstclear.c \
					  ft_lstdelone.c \
					  ft_lstiter.c \
					  ft_lstlast.c \
					  ft_lstmap.c \
					  ft_lstnew.c

OBJECTS = $(SOURCES:.c=.o)

BNS_OBJS = $(BNS_SRCS:%.c=%.o)


all: $(TARGET)

%.o: %.c
	gcc $(CFLAGS) -c $<

$(TARGET): $(OBJECTS)
	gcc $(CFLAGS) -o $@ $^

clean:
	rm -f $(OBJECTS)

fclean: clean
	rm -f $(TARGET)

re: fclean all
