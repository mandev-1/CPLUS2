#include "HumanB.hpp"
#include <iostream>

HumanB::HumanB(const std::string& name) : name(name), weapon(NULL) {
    std::cout << "HumanB entity was instantiated with a name '" << this->name << "' and a DEFAULT weapon '" << this->weapon << "'" << std::endl;
}

void HumanB::setWeapon(Weapon& weapon) {
    this->weapon = &weapon;
    std::cout << "HumanB entity " << this->name << " had their weapon set to '" << this->weapon->getType() << "'" << std::endl;
}

void HumanB::attack() const {
    if (weapon)
        std::cout << name << " attacks with their " << weapon->getType() << std::endl;
    else
        std::cout << name << " has no weapon to attack with" << std::endl;
}
