#ifndef CAT_HPP
#define CAT_HPP

#pragma once

#include "Animal.hpp"

class Cat : public Animal
{
    public:
        Cat();
        ~Cat();
        void makeSound() const;
};

#endif