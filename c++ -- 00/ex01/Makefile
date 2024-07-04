# Makefile for My Awesome PhoneBook

CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++11

SRCS = main.cpp phonebook.cpp contact.cpp
OBJS = $(SRCS:.cpp=.o)
TARGET = phonebook

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(TARGET)

.PHONY: all clean
