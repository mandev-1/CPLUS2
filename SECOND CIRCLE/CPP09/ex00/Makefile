CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98
NAME = btc 
SRC = main.cpp BitcoinExchange.cpp
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

run: all
	./$(NAME)

.PHONY: all clean fclean re
