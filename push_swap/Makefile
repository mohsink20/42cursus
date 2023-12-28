# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mokhan <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/22 15:37:33 by mokhan            #+#    #+#              #
#    Updated: 2023/12/22 15:37:35 by mokhan           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Makefile for push_swap

# Compiler and flags
CC = gcc
CFLAGS = -Wall -Wextra -Werror
SRC = push_swap.c push_swap_cmd.c push_swap_init.c push_swap_lst.c push_swap_lst2.c push_swap_moves.c push_swap_rot.c push_swap_smallest.c push_swap_sort_big.c push_swap_sort.c push_swap_steps.c push_swap_utils.c
BONUS_SRC = push_swap_checker.c push_swap_checker_utils.c push_swap_cmd.c push_swap_init.c push_swap_lst.c push_swap_lst2.c push_swap_moves.c push_swap_smallest.c push_swap_utils.c
OBJ = $(SRC:.c=.o)
BONUS_OBJ = $(BONUS_SRC:.c=.o)
EXEC = push_swap
BONUS_EXEC = checker
LIBDIR = mylib
LIB = mylib.a

all: $(LIBDIR)/$(LIB) $(EXEC)

bonus:  $(LIBDIR)/$(LIB) $(BONUS_OBJ)
	$(CC) $(CFLAGS) -o $(BONUS_EXEC) $(BONUS_OBJ) -L$(LIBDIR)/libft -lft -L$(LIBDIR)/get_next_line -l:gnl.a

$(EXEC): $(OBJ)
	$(CC) $(CFLAGS) -o $(EXEC) $(OBJ) -L$(LIBDIR)/libft -lft

$(BONUS_EXEC): $(BONUS_OBJ)
	$(CC) $(CFLAGS) -o $(BONUS_EXEC) $(BONUS_OBJ) -L$(LIBDIR)/libft -lft

%.o: %.c pipex.h
	$(CC) $(CFLAGS) -c $< -o $@

$(LIBDIR)/$(LIB):
	$(MAKE) -C $(LIBDIR)
	cp $(LIBDIR)/$(LIB) .

clean:
	rm -f $(OBJ) $(BONUS_OBJ)
	$(MAKE) -C $(LIBDIR) clean

fclean: clean
	rm -f $(EXEC) $(BONUS_EXEC) $(LIB)
	$(MAKE) -C $(LIBDIR) fclean

re: fclean all

.PHONY: all bonus clean fclean re
