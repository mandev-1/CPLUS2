#include "Dog.hpp"
#include <iostream>

Dog::Dog()
{
    this->type = "Dog";
    std::cout << "Dog consructor called" << std::endl;
};

Dog::~Dog()
{
    std::cout << "Dog destructor called" << std::endl;
};

void Dog::makeSound() const
{
    std::cout << "Woof woof" << std::endl;
};