# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mman <mman@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/04 21:44:25 by mman              #+#    #+#              #
#    Updated: 2024/07/04 21:46:20 by mman             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Makefile for the megaphone program

# Compiler
CXX = g++

# Compiler flags
CXXFLAGS = -Wall -Wextra -std=c++11

# Target executable
TARGET = megaphone

# Source file
SRC = megaphone.cpp

# Rule to build the target executable
$(TARGET): $(SRC)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(SRC)

# Rule to clean up the generated
