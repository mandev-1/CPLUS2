#ifndef DOG_HPP
#define DOG_HPP

#pragma once

#include "A_Animal.hpp"
#include <iostream>

class Dog : public A_Animal
{
    public:
        Dog();
        Dog(const Dog& other);
        Dog& operator=(const Dog& other);
        ~Dog();
        void makeSound() const;
};

#endif
