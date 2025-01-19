#include "ClapTrap.hpp"
#include <iostream>


// # 2 ----------- Default Constructor + Destructor -----------

//Constructor + Initializer List
ClapTrap::ClapTrap(std::string name): name(name), hitPoints(10), energyPoints(10), attackDamage(0)
{
    std::cout << "\033[32m" << name << "\033[0m is created." << std::endl;
}

ClapTrap::~ClapTrap()
{
	std::cout << "\033[32m" << name << "\033[31m is destroyed. RIP!\033[0m" << std::endl;
}



// # 3 ----------- Member Functions -----------

void ClapTrap::attack(const std::string& target)
{
	this->energyPoints -= 1;
	std::cout << "ClapTrap " << name << " attacks " << target << ", causing \033[31m" << attackDamage << "\033[0m points of damage!" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	this->hitPoints -= amount;
	std::cout << "ClapTrap " << name << " takes \033[31m" << amount << "\033[0m points of damage!" << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	this->hitPoints += amount;
	this->energyPoints -= 1;
	std::cout << name << " is repaired for \033[33m" << amount << "\033[0m points!" << std::endl;
}