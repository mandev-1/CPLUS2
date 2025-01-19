#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include "Brain.hpp"
#include <string>

class Animal {
    public:
        Animal();
        Animal(const Animal& other);
        Animal& operator=(const Animal& other);
        virtual ~Animal();
        
        std::string getType() const;
        virtual void makeSound() const = 0;

    protected:
        std::string type;
        Brain* animal_brain;
};

#endif