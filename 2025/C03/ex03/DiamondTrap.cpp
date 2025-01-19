#include "DiamondTrap.hpp"
#include <iostream>

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name + "_clap_name"), ScavTrap(name), FragTrap(name)
{
    this->name = name;
    this->hitPoints = FragTrap::hitPoints;
    this->energyPoints = ScavTrap::energyPoints;
    this->attackDamage = FragTrap::attackDamage;
    std::cout << "\033[32m" << name << "\033[30m -- DIAMOND-TR4P package being added on top of ClapTrap body to create it with " << hitPoints << "HP, " << energyPoints << "EP, " << attackDamage << "AD\033[0m" << std::endl;
}

DiamondTrap::~DiamondTrap()
{
    std::cout << "\033[32m" << name << "'s \033[30m DIAMOND-TR4P\033[0m addon\033[31m exploded.\033[0m" << std::endl;
}

void DiamondTrap::whoAmI()
{
    std::cout << "My name is " << name << " and my ClapTrap name is " << ClapTrap::name << std::endl;
}

void DiamondTrap::attack(const std::string &target)
{
    ScavTrap::attack(target);
}