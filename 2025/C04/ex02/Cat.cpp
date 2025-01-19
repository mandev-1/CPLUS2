#include "Cat.hpp"
#include <iostream>

Cat::Cat() : A_Animal()
{
    this->type = "Cat";
    std::cout << "Cat constructor called" << std::endl;
}

Cat::Cat(const Cat& other) : A_Animal(other)
{
    std::cout << "Cat 'COPY' constructor called" << std::endl;
}

Cat& Cat::operator=(const Cat& other)
{
    std::cout << "Cat assignment operator called" << std::endl;
    if (this != &other)             // Prevent self-assignment
        A_Animal::operator=(other);       // Call base class assignment
    return *this;                      // Return reference to current object
}

Cat::~Cat()
{
    std::cout << "Cat destructor called" << std::endl;
}

void Cat::makeSound() const
{
    std::cout << "meow" << std::endl;
};
