#include "A_Animal.hpp"
#include <iostream>

A_Animal::A_Animal() : animal_brain(new Brain()) {
    std::cout << "Constructor called in animal.cpp" << std::endl;
    this->type = "";
}

A_Animal::A_Animal(const A_Animal& other) : animal_brain(new Brain(*other.animal_brain)) {
    std::cout << "Copy constructor called in animal.cpp" << std::endl;
    this->type = other.type;
}

A_Animal& A_Animal::operator=(const A_Animal& other) {
    std::cout << "Assignment operator called in animal.cpp" << std::endl;
    if (this != &other) {
        delete animal_brain;
        animal_brain = new Brain(*other.animal_brain);
        type = other.type;
    }
    return *this;
}

A_Animal::~A_Animal() {
    std::cout << "Destructor called in animal.cpp" << std::endl;
    delete animal_brain;
}

std::string A_Animal::getType() const {
    return this->type;
}