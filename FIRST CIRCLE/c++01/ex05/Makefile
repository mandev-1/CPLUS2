# Defining the name of our executable
NAME = harl

# Specifying the compiler we're using (C++)
CC = c++

# Setting compiler flags for strict error checking and C++98 standard
CFLAGS = -Wall -Wextra -Werror -std=c++98

# List of source files needed for compilation
SRCS = main.cpp Harl.cpp

# Converting .cpp files to .o object files
OBJS = $(SRCS:.cpp=.o)

# Default target - builds the executable
all: $(NAME)

# Links object files into final executable
$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

# Pattern rule to compile source files into object files
%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

# Removes object files
clean:
	rm -f $(OBJS)

# Removes object files and executable
fclean: clean
	rm -f $(NAME)

# Complete rebuild from scratch
re: fclean all

# Declares which targets aren't actual files
.PHONY: all clean fclean re
