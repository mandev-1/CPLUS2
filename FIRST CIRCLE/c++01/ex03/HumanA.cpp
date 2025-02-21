#include "HumanA.hpp"
#include <iostream>

HumanA::HumanA(const std::string& name, Weapon& weapon)
    : name(name), weapon(weapon) {
    std::cout << "HumanA entity was instantiated with a name '" << this->name << "' and a DEFAULT weapon '" << this->weapon.getType() << "'" << std::endl;
}

void HumanA::attack() const {
    std::cout << name << " attacks with their " << weapon.getType() << std::endl;
}
