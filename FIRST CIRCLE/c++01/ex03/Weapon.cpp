#include "Weapon.hpp"
#include <iostream>

Weapon::Weapon(const std::string& type) : type(type)
{
    std::cout << "weapon of type '" << this->type << "' has been instantiated" << std::endl;
}

const std::string& Weapon::getType() const {
    return type;
}

void Weapon::setType(const std::string& newType) {
    type = newType;
}
