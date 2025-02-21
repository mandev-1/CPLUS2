#ifndef DOG_HPP
#define DOG_HPP

#pragma once

#include "Animal.hpp"
#include <iostream>

class Dog : public Animal
{
    public:
        Dog();
        ~Dog();
        void makeSound() const;
};

#endif