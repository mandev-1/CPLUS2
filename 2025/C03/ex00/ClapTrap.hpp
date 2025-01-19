#ifndef CLAPTRAP_H
#define CLAPTRAP_H

#pragma once

#include <iostream>
#include <string>

class ClapTrap
{
    private:
        int hitPoints;
        int energyPoints;
        int attackDamage;
    public:
        std::string name;
        ClapTrap(std::string name);
        ~ClapTrap();
        void attack(const std::string& target);
        void takeDamage(unsigned int amount);
        void beRepaired(unsigned int amount);
};

#endif