#ifndef A_ANIMAL_HPP
#define A_ANIMAL_HPP

#pragma once

#include <string>
#include "Brain.hpp"

class A_Animal
{
    protected:
        std::string type;
        Brain* animal_brain;
    
    public:
        A_Animal();
        virtual ~A_Animal();
        A_Animal(const A_Animal& other);
        A_Animal& operator=(const A_Animal& other);
        
        std::string getType() const;
        virtual void makeSound() const = 0;
};

#endif