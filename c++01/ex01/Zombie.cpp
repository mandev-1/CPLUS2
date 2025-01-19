#include "Zombie.hpp"
#include <iostream>

Zombie::Zombie() {
    std::cout << "A zombie appeared" << std::endl;
}

Zombie::Zombie(std::string name) : name(name) {
    std::cout << "A zombie was CREATED with a name: " << this->name << std::endl;
}

Zombie::~Zombie() {
    std::cout << "Zombie called '" << this->name << "' has been destroyed" << std::endl;
}

void Zombie::announce() const {
    std::cout << this->name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

void Zombie::setName(std::string name) {
    this->name = name;
    std::cout << "An existing zombie was assigned a name: " << this->name << std::endl;
}
