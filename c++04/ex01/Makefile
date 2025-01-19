CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98
NAME = program
SRC = main.cpp Animal.cpp Cat.cpp Dog.cpp Brain.cpp
OBJS = $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) $^ -o $@
	@printf "\rCompiled $(NAME)    \n"


fclean: clean
	@rm -rf $(NAME)

clean:
	@rm -rf $(OBJS)


re: fclean all

.PHONY: all clean fclean re
