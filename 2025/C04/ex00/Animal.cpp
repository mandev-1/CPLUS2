#include "Animal.hpp"

Animal::Animal()
{
    std::cout << "Constructor called in animal.cpp" << std::endl;
};

Animal::~Animal()
{
    std::cout << "Destructor called in animal.cpp" << std::endl;
};

std::string Animal::getType() const
{
    return this->type;
};

