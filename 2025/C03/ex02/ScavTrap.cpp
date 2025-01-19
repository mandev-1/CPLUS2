#include "ScavTrap.hpp"
#include <iostream>

ScavTrap::ScavTrap(std::string name): ClapTrap(name)
{
    this->hitPoints = 100;
    this->energyPoints = 50;
    this->attackDamage = 20;
    std::cout << "\033[32m" << name << "\033[0m is constructed. (" << hitPoints << "HP, " << energyPoints << "EP, " << attackDamage << "AD)" << std::endl;
}

ScavTrap::~ScavTrap()
{
    std::cout << "\033[32m" << name << "\033[30m SCAV-TR4P\033[0m addon\033[31m exploded.\033[0m" << std::endl;
}

void ScavTrap::guardGate()
{
    std::cout << "ScavTrap " << name << " has entered in Gate keeper mode." << std::endl;
}