CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98
NAME = program 
SRC = main.cpp Bureaucrat.cpp AForm.cpp PresidentialPardonForm.cpp RobotomyRequestForm.cpp ShrubberyCreationForm.cpp
OBJS = $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) $^ -o $@
	@printf "\rCompiled $(NAME)    \n"


fclean: clean
	@rm -rf $(NAME)
	@rm -rf garden_shrubbery

clean:
	@rm -rf $(OBJS)


re: fclean all

run: all
	./$(NAME)

.PHONY: all clean fclean re
