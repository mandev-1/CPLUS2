#ifndef DIAMONDTRAP_HPP
#define DIAMONDTRAP_HPP

#pragma once

#include "ScavTrap.hpp"
#include "FragTrap.hpp"

// To ensure that I do not create anything twice, I have modified the parent classes to use virtual inheritance.
class DiamondTrap : public ScavTrap, public FragTrap
{
    public:
        DiamondTrap(std::string name);
        ~DiamondTrap();
        void whoAmI();
        void attack(const std::string& target);
    private:
        std::string name;
        int hitPoints;
        int energyPoints;
        int attackDamage;
};

#endif // DIAMONDTRAP_HPP