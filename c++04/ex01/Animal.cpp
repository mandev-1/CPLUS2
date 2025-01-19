#include "Animal.hpp"
#include <iostream>

Animal::Animal() : animal_brain(new Brain()) {
    std::cout << "Constructor called in animal.cpp" << std::endl;
    this->type = "";
}

Animal::Animal(const Animal& other) : animal_brain(new Brain(*other.animal_brain)) {
    std::cout << "Copy constructor called in animal.cpp" << std::endl;
    this->type = other.type;
}

Animal& Animal::operator=(const Animal& other) {
    std::cout << "Assignment operator called in animal.cpp" << std::endl;
    if (this != &other) {
        delete animal_brain;
        animal_brain = new Brain(*other.animal_brain);
        type = other.type;
    }
    return *this;
}

Animal::~Animal() {
    std::cout << "Destructor called in animal.cpp" << std::endl;
    delete animal_brain;
}

std::string Animal::getType() const {
    return this->type;
}