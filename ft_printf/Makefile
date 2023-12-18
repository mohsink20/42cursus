# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mokhan <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/06 13:39:35 by mokhan            #+#    #+#              #
#    Updated: 2023/10/06 13:39:38 by mokhan           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Define variables
TARGET = libftprintf.a
CC = cc
CFLAGS = -Wall -Werror -Wextra
AR = ar rcs
RM = rm -f
INCLUDE_DIR = -I.

# Define colors
DEFAULT_COLOR = \033[0;39m
RED = \033[0;91m
GREEN = \033[0;92m
YELLOW = \033[0;93m

# Source and object file lists
SOURCE_FILES =	ft_printf \
		ft_printf_utils \
		ft_printf_unbr \
		ft_printf_strchar \
		ft_printf_pointer \
		ft_printf_nbr \
		ft_printf_hex

SOURCES = $(addsuffix .c, $(SOURCE_FILES))
OBJECTS = $(addsuffix .o, $(SOURCE_FILES))

# Build rules

$(TARGET): $(OBJECTS)
	@ make -C libft
	@ echo "$(GREEN)Built libft.a successfully$(DEFAULT_COLOR)"
	@ cp libft/libft.a .
	@ echo "$(GREEN)Copied libft.a successfully$(DEFAULT_COLOR)"
	@ mv libft.a $(TARGET)
	@ echo "$(GREEN)Renamed libft.a to libftprintf.a$(DEFAULT_COLOR)"
	@ $(AR) $(TARGET) $(OBJECTS)
	@ echo "$(GREEN)Updated libftprintf.a$(DEFAULT_COLOR)"
	@ echo "$(GREEN)Compiled libftprintf.a successfully!$(DEFAULT_COLOR)"

%.o: %.c
	@ echo "$(YELLOW)Compiling: $<$(DEFAULT_COLOR)"
	@ $(CC) $(CFLAGS) $(INCLUDE_DIR) -c $< -o $@
	@ echo "$(GREEN)Created object files successfully$(DEFAULT_COLOR)"

all: $(TARGET)

clean:
	@ $(RM) -rf $(OBJECTS)
	@ echo "$(RED)Removed object files$(DEFAULT_COLOR)"
	@ make clean -C libft
	@ echo "$(RED)Removed libft object files$(DEFAULT_COLOR)"

fclean: clean
	@ $(RM) $(TARGET)
	@ echo "$(RED)Removed 'libftprintf.a' successfully$(DEFAULT_COLOR)"
	@ $(RM) libft/libft.a
	@ echo "$(RED)Removed 'libft.a' successfully$(DEFAULT_COLOR)"

bonus: all

re: fclean all
