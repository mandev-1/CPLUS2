#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#pragma once

#include <string>

class ClapTrap
{
    public:
        ClapTrap(std::string name);
        ~ClapTrap();
        void attack(const std::string& target);
        void takeDamage(unsigned int amount);
        void beRepaired(unsigned int amount);
        std::string name;
        int hitPoints;
        int energyPoints;
        int attackDamage;
};

#endif