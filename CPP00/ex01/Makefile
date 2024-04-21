NAME = phonebook
CC = g++
FLAGS = -Wall -Werror -Wextra -std=c++98

SRC = main.cpp PhoneBook.cpp Contact.cpp

OBJ = $(SRC:.cpp=.o)

$(NAME) : $(OBJ)
	$(CC) $(FLAGS) $(SRC) -o $@

all : $(NAME)

clean :
	rm -rf $(OBJ)

fclean : clean
	rm -rf $(NAME)

re :
	make fclean
	make all

.PHONY : all clean fclean re
