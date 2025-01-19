#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#pragma once
#include <iostream>

class Animal
{
    public:
        Animal();
        ~Animal();
        std::string getType() const;
        virtual void makeSound() const;

    protected:
        std::string type;

};

#endif // ANIMAL_HPP