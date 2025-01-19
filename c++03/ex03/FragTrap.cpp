#include "FragTrap.hpp"
#include <iostream>

FragTrap::FragTrap(std::string name): ClapTrap(name)
{
    this->hitPoints = 100;
    this->energyPoints = 100;
    this->attackDamage = 30;
    std::cout << "\033[32m" << name << "\033[30m -- Frag-Tr4P package being added on top of ClapTrap body to create it with " << hitPoints << "HP, " << energyPoints << "EP, " << attackDamage << "AD\033[0m" << std::endl;
}

FragTrap::~FragTrap()
{
    std::cout << "\033[32m" << name << "\033[29m FR46-TR4P\033[0m addon\033[31m exploded.\033[0m" << std::endl;
}

void FragTrap::highFivesGuys(void)
{
    std::cout << "FragTrap " << name << " is requesting a high five!" << std::endl;
}